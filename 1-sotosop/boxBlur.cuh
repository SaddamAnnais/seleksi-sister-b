#ifndef BOXBLUR_H
#define BOXBLUR_H

#include <opencv2/core.hpp>
#include <cuda_runtime.h>
#include "image_io.hpp"
#include <string>

__global__ void boxBlur_device(uchar3* input, uchar3* output, int width, int height, int kernelSize);
void boxBlur_host(cv::Mat& input_image, cv::Mat& output_image, uchar3* d_input, uchar3* d_output, std::string path, int kernelSize, bool save);

#endif /* BOXBLUR_H*/