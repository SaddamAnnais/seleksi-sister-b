#include "grayscale.cuh"
#include <cuda.h>
#include "image_io.hpp"

using namespace std;
using namespace cv;

__global__ void grayscale_device(uchar3* input, uchar* output, int width, int height) {
    int col = blockIdx.x * blockDim.x + threadIdx.x;
    int row = blockIdx.y * blockDim.y + threadIdx.y;
    if (col < width && row < height) {
        int idx = row * width + col;
        uchar3 pixel = input[idx];
        output[idx] = float((pixel.x + pixel.y + pixel.z) / 3);
    }
}

void grayscale_host(Mat& image, string path) {
    // Allocate memory on the GPU
    uchar3* d_input;
    uchar* d_output;
    cudaMalloc(&d_input, image.cols * image.rows * sizeof(uchar3));
    cudaMalloc(&d_output, image.cols * image.rows * sizeof(uchar));

    // Copy the input image to the GPU
    cudaMemcpy(d_input, image.ptr<uchar3>(), image.cols * image.rows * sizeof(uchar3), cudaMemcpyHostToDevice);

    // Define the CUDA kernel launch parameters
    dim3 blockDim(32, 32);
    dim3 gridDim((image.cols + blockDim.x - 1) / blockDim.x, (image.rows + blockDim.y - 1) / blockDim.y);

    // Invoke Device Kernel
    grayscale_device << <gridDim, blockDim >> > (d_input, d_output, image.cols, image.rows);

    // Copy the output image from the GPU
    Mat output_buffer(image.rows, image.cols, CV_8UC1);
    cudaMemcpy(output_buffer.ptr<uchar>(), d_output, image.cols * image.rows * sizeof(uchar), cudaMemcpyDeviceToHost);

    // Save the output image to disk
    saveImage(path, output_buffer, "_grayscale");
    output_buffer.copyTo(image);

    // Free memory on the GPU
    cudaFree(d_input);
    cudaFree(d_output);
}