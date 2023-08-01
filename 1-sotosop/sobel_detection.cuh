#ifndef SOBEL_DETECTION_H
#define SOBEL_DETECTION_H

#include <opencv2/core.hpp>
#include <cuda_runtime.h>
#include "image_io.hpp"
#include <string>

__global__ void sobelEdgeDetection(uchar3* input, uchar3* output, int width, int height);
void sobelEdgeDetection_host(cv::Mat& input_image, cv::Mat& output_image, uchar3* d_input, uchar3* d_output, std::string path, bool save);

#endif /* SOBEL_DETECTION_H*/