#include "sobel_detection.cuh"
#include "image_io.hpp"

using namespace cv;
using namespace std;

__constant__ int sobel_x[9] = { -1, 0, 1, -2, 0, 2, -1, 0, 1 };
__constant__ int sobel_y[9] = { -1, -2, -1, 0, 0, 0, 1, 2, 1 };

__global__ void sobelEdgeDetection(uchar3* input, uchar3* output, int width, int height) {
    int col = blockIdx.x * blockDim.x + threadIdx.x;
    int row = blockIdx.y * blockDim.y + threadIdx.y;

    if (col < width && row < height) {
        int sum_col = 0;
        int sum_row = 0;

        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                int pixel_col = col + i;
                int pixel_row = row + j;
                int pixel_index = pixel_row * width + pixel_col;

                float pixel_gray = (input[pixel_index].x + input[pixel_index].y + input[pixel_index].z)/3;

                sum_col += sobel_x[(i + 1) * 3 + (j + 1)] * pixel_gray;
                sum_row += sobel_y[(i + 1) * 3 + (j + 1)] * pixel_gray;
            }
        }
        unsigned char final_pixel = static_cast<unsigned char>(sqrtf(static_cast<float>(sum_col * sum_col + sum_row * sum_row)));
        output[row * width + col] = make_uchar3(final_pixel, final_pixel, final_pixel);
    }
}

void sobelEdgeDetection_host(cv::Mat& input_image, cv::Mat& output_image, uchar3* d_input, uchar3* d_output, std::string path, bool save) {
    // Copy the input image to the GPU
    cudaMemcpy(d_input, input_image.ptr<uchar3>(), input_image.cols * input_image.rows * sizeof(uchar3), cudaMemcpyHostToDevice);

    //Launch the CUDA kernel to apply the blur filter
    dim3 blockDim(32, 32);
    dim3 gridDim((input_image.cols + blockDim.x - 1) / blockDim.x, (input_image.rows + blockDim.y - 1) / blockDim.y);

    // Call the box filter kernel 
    sobelEdgeDetection << <gridDim, blockDim >> > (d_input, d_output, input_image.cols, input_image.rows);

    // Copy the output image from the GPU
    cudaMemcpy(output_image.ptr<uchar3>(), d_output, input_image.cols * input_image.rows * sizeof(uchar3), cudaMemcpyDeviceToHost);


    // Save the output image to disk
    if (save) saveImage(path, output_image, "_sobelEdgeDetection");
}