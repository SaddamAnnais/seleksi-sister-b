#include "grayscale.cuh"
#include <cuda.h>
#include "image_io.hpp"

using namespace std;
using namespace cv;

__global__ void grayscale_device(uchar3* input, uchar3* output, int width, int height) {
    int col = blockIdx.x * blockDim.x + threadIdx.x;
    int row = blockIdx.y * blockDim.y + threadIdx.y;

    if (col < width && row < height) {
        int idx = row * width + col;
        uchar3 pixel = input[idx];

        float output_pixel = float((pixel.x + pixel.y + pixel.z) / 3);
        output[idx].x = output_pixel;
        output[idx].y = output_pixel;
        output[idx].z = output_pixel;
    }
}

void grayscale_host(Mat& input_image, Mat& output_image, uchar3* d_input, uchar3* d_output, string path, bool save) {
    // Copy the input image to the GPU
    cudaMemcpy(d_input, input_image.ptr<uchar3>(), input_image.cols * input_image.rows * sizeof(uchar3), cudaMemcpyHostToDevice);

    // Define the CUDA kernel launch parameters
    dim3 blockDim(32, 32);
    dim3 gridDim((input_image.cols + blockDim.x - 1) / blockDim.x, (input_image.rows + blockDim.y - 1) / blockDim.y);

    // Invoke Device Kernel
    grayscale_device << <gridDim, blockDim >> > (d_input, d_output, input_image.cols, input_image.rows);

    // Copy the output image from the GPU
    cudaMemcpy(output_image.ptr<uchar>(), d_output, input_image.cols * input_image.rows * sizeof(uchar3), cudaMemcpyDeviceToHost);

    // Save the output image to disk
    if (save) saveImage(path, output_image, "_grayscale");
}