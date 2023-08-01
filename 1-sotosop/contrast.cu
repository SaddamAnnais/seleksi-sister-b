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

void contrast_host(Mat& input_image, Mat& output_image, uchar3* d_input, uchar3* d_output, string path, int c, bool save) {

    // Copy the input image to the GPU
    cudaMemcpy(d_input, input_image.ptr<uchar3>(), input_image.cols * input_image.rows * sizeof(uchar3), cudaMemcpyHostToDevice);

    // Define the CUDA kernel launch parameters
    dim3 blockDim(32, 32);
    dim3 gridDim((input_image.cols + blockDim.x - 1) / blockDim.x, (input_image.rows + blockDim.y - 1) / blockDim.y);

    // Launch the CUDA kernel to apply the contrast filter
    contrast_device << <gridDim, blockDim >> > (d_input, d_output, input_image.cols, input_image.rows, c);

    // Copy the output image from the GPU
    cudaMemcpy(output_image.ptr<uchar3>(), d_output, input_image.cols * input_image.rows * sizeof(uchar3), cudaMemcpyDeviceToHost);

    // Save the output image to disk
    if (save) saveImage(path, output_image, "_" + to_string(c) + "_contrast");
}
