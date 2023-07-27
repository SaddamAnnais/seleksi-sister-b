#include "saturation.cuh"
#include <string>
#include <iostream>
#include <cuda.h>
#include "image_io.hpp"
#include <math.h>

using namespace std;
using namespace cv;



__device__ uchar3 hsl2rgb(HSLColor hsl) {
    // Convert the HSL color to RGB
    float c = (1 - abs(2 * hsl.l - 1)) * hsl.s;
    float x = c * (1 - abs(fmodf(hsl.h / 60, 2) - 1));
    float m = hsl.l - c / 2;

    float r, g, b;
    if (hsl.h >= 0 && hsl.h < 60) {
        r = c;
        g = x;
        b = 0;
    }
    else if (hsl.h >= 60 && hsl.h < 120) {
        r = x;
        g = c;
        b = 0;
    }
    else if (hsl.h >= 120 && hsl.h < 180) {
        r = 0;
        g = c;
        b = x;
    }
    else if (hsl.h >= 180 && hsl.h < 240) {
        r = 0;
        g = x;
        b = c;
    }
    else if (hsl.h >= 240 && hsl.h < 300) {
        r = x;
        g = 0;
        b = c;
    }
    else {
        r = c;
        g = 0;
        b = x;
    }

    r += m;
    g += m;
    b += m;

    return make_uchar3(static_cast<unsigned char>(r * 255), static_cast<unsigned char>(g * 255), static_cast<unsigned char>(b * 255));
}

__device__ HSLColor rgb2hsl(uchar3 rgb) {
    // Convert the RGB color to HSL
    float r = rgb.x / 255.0f;
    float g = rgb.y / 255.0f;
    float b = rgb.z / 255.0f;

    float cmax = max(max(r, g), b);
    float cmin = min(min(r, g), b);
    float delta = cmax - cmin;

    float h, s, l;
    if (delta == 0) {
        h = 0;
    }
    else if (cmax == r) {
        h = fmodf((g - b) / delta, 6);
    }
    else if (cmax == g) {
        h = (b - r) / delta + 2;
    }
    else {
        h = (r - g) / delta + 4;
    }

    h *= 60;

    l = (cmax + cmin) / 2;

    if (delta == 0) {
        s = 0;
    }
    else {
        s = delta / (1 - fabs(2 * l - 1));
    }

    return { h, s, l };
}

__global__ void saturation_kernel(uchar3* input, uchar3* output, int width, int height, int c) {
    int col = blockIdx.x * blockDim.x + threadIdx.x;
    int row = blockIdx.y * blockDim.y + threadIdx.y;

    if (col < width && row < height) {
        int idx = row * width + col;
        uchar3 pixel = input[idx];

        // Convert to hsl
        HSLColor pixel_hsl = rgb2hsl(pixel);

        // Multiply the saturation by c
        pixel_hsl.s *= c;

        // Convert the back to RGB
        uchar3 pixel_rgb = hsl2rgb(pixel_hsl);

        output[idx].x = pixel_rgb.x;
        output[idx].y = pixel_rgb.y;
        output[idx].z = pixel_rgb.z;
    }
}

void saturation_host(Mat& image, string path, int c) {
    // Allocate memory on the GPU
    uchar3* d_input;
    uchar3* d_output;
    cudaMalloc(&d_input, image.cols * image.rows * sizeof(uchar3));
    cudaMalloc(&d_output, image.cols * image.rows * sizeof(uchar3));

    // Copy the input image to the GPU memory
    cudaMemcpy(d_input, image.ptr<uchar3>(0), image.cols * image.rows * sizeof(uchar3), cudaMemcpyHostToDevice);

    // Set the block size and grid size
    dim3 blockSize(32, 32);
    dim3 gridSize((image.cols + blockSize.x - 1) / blockSize.x, (image.rows + blockSize.y - 1) / blockSize.y);

    // Launch the kernel
    saturation_kernel << <gridSize, blockSize >> > (d_input, d_output, image.cols, image.rows, c);

    // Copy the output image from the GPU
    Mat output_buffer(image.rows, image.cols, CV_8UC3);
    cudaMemcpy(output_buffer.ptr<uchar3>(0), d_output, image.cols * image.rows * sizeof(uchar3), cudaMemcpyDeviceToHost);

    // Save the output image to disk
    saveImage(path, output_buffer, "_" + to_string(c) + "_saturation");
    output_buffer.copyTo(image);

    // Free the GPU memory
    cudaFree(d_input);
    cudaFree(d_output);
}