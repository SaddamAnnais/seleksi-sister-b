#include "boxBlur.cuh"
#include "image_io.hpp"

using namespace cv;
using namespace std;

__global__ void boxBlur_device(uchar3* d_input, uchar3* d_output, int width, int height, int kernelSize) {
    int col = blockIdx.x * blockDim.x + threadIdx.x;
    int row = blockIdx.y * blockDim.y + threadIdx.y;

    if (col < width && row < height) {
        float sumX = 0;
        float sumY = 0;
        float sumZ = 0;
        int count = 0;

        for (int i = -kernelSize; i <= kernelSize; i++) {
            for (int j = -kernelSize; j <= kernelSize; j++) {
                int curRow = row + i;
                int curCol = col + j;
                if (curRow >= 0 && curRow < height && curCol >= 0 && curCol < width) {
                    sumX += d_input[curRow * width + curCol].x;
                    sumY += d_input[curRow * width + curCol].y;
                    sumZ += d_input[curRow * width + curCol].z;
                    count++;
                }
            }
        }

        d_output[row * width + col].x = sumX / count;
        d_output[row * width + col].y = sumY / count;
        d_output[row * width + col].z = sumZ / count;

    }

}

void boxBlur_host(Mat& input_image, Mat& output_image, uchar3* d_input, uchar3* d_output, string path, int kernelSize, bool save) {

    // Copy the input image to the GPU
    cudaMemcpy(d_input, input_image.ptr<uchar3>(), input_image.cols * input_image.rows * sizeof(uchar3), cudaMemcpyHostToDevice);

    //Launch the CUDA kernel to apply the blur filter
    dim3 blockDim(32, 32);
    dim3 gridDim((input_image.cols + blockDim.x - 1) / blockDim.x, (input_image.rows + blockDim.y - 1) / blockDim.y);

    // Call the box filter kernel 
    boxBlur_device << <gridDim, blockDim >> > (d_input, d_output, input_image.cols, input_image.rows, kernelSize);

    // Copy the output image from the GPU
    cudaMemcpy(output_image.ptr<uchar3>(), d_output, input_image.cols * input_image.rows * sizeof(uchar3), cudaMemcpyDeviceToHost);


    // Save the output image to disk
    if (save) saveImage(path, output_image, "_" + to_string(kernelSize) + "_boxBlur");
}