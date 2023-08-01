#ifndef CONTRAST_H
#define CONTRAST_H

#include <opencv2/core.hpp>
#include <cuda_runtime.h>
#include <string>

__global__ void contrast_device(uchar3* input, uchar3* output, int width, int height, int c);
void contrast_host(cv::Mat& input_image, cv::Mat& output_image, uchar3* d_input, uchar3* d_output, std::string path, int c, bool save);

#endif /* CONTRAST_H */