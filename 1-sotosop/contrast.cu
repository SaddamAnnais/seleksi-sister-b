#include <cuda_runtime.h>
#include <cuda.h>
#include "image_io.hpp"

using namespace std;
using namespace cv;


__global__ void contrast_device(uchar3* input, uchar3* output, int width, int height, int c) {
    int col = blockIdx.x * blockDim.x + threadIdx.x;
    int row = blockIdx.y * blockDim.y + threadIdx.y;

    if (col < width && row < height) {
        int idx = row * width + col;
        uchar3 pixel = input[idx];

        int r = max(0, min(255, c * (pixel.x - 128) + 128));
        int g = max(0, min(255, c * (pixel.y - 128) + 128));
        int b = max(0, min(255, c * (pixel.z - 128) + 128));

        output[idx].x = r;
        output[idx].y = g;
        output[idx].z = b;
    }
}

void contrast_host(Mat& image, string path, int c) {
    // Allocate memory on the GPU
    uchar3* d_input;
    uchar3* d_output;
    cudaMalloc(&d_input, image.cols * image.rows * sizeof(uchar3));
    cudaMalloc(&d_output, image.cols * image.rows * sizeof(uchar3));

    // Copy the input image to the GPU
    cudaMemcpy(d_input, image.ptr<uchar3>(), image.cols * image.rows * sizeof(uchar3), cudaMemcpyHostToDevice);

    // Define the CUDA kernel launch parameters
    dim3 blockDim(32, 32);
    dim3 gridDim((image.cols + blockDim.x - 1) / blockDim.x, (image.rows + blockDim.y - 1) / blockDim.y);

    // Launch the CUDA kernel to apply the contrast filter
    contrast_device << <gridDim, blockDim >> > (d_input, d_output, image.cols, image.rows, c);

    // Copy the output image from the GPU
    Mat output_buffer(image.rows, image.cols, CV_8UC3);
    cudaMemcpy(output_buffer.ptr<uchar3>(), d_output, image.cols * image.rows * sizeof(uchar3), cudaMemcpyDeviceToHost);

    // Save the output image to disk
    saveImage(path, output_buffer, "_" + to_string(c) + "_contrast");
    output_buffer.copyTo(image);

    // Free memory on the GPU
    cudaFree(d_input);
    cudaFree(d_output);
}
