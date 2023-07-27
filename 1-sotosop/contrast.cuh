#ifndef CONTRAST_H
#define CONTRAST_H

#include <opencv2/core.hpp>
#include <cuda_runtime.h>
#include <string>

__global__ void contrast_device(uchar3* input, uchar3* output, int width, int height, int c);
void contrast_host(cv::Mat& image, std::string path, int c);

#endif /* CONTRAST_H */