#ifndef GRAYSCALE_H
#define GRAYSCALE_H

#include <opencv2/core.hpp>
#include <cuda_runtime.h>
#include <string>

__global__ void grayscale_device(uchar3* input, uchar* output, int width, int height);
void grayscale_host(cv::Mat& image, std::string path);

#endif /* GRAYSCALE_H */