#ifndef GRAYSCALE_H
#define GRAYSCALE_H

#include <opencv2/core.hpp>
#include <cuda_runtime.h>
#include <string>

__global__ void grayscale_device(uchar3* input, uchar3* output, int width, int height);
void grayscale_host(cv::Mat& input_image, cv::Mat& output_image, uchar3* d_input, uchar3* d_output, std::string path, bool save);

#endif /* GRAYSCALE_H */