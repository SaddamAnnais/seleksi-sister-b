#ifndef SATURATION_H
#define SATURATION_H

#include <opencv2/core.hpp>
#include <cuda_runtime.h>
#include <string>

// Define a struct to represent a color in the HSL color space
struct HSLColor {
    float h;
    float s;
    float l;
};

__device__ uchar3 hsl2rgb(HSLColor hsl);
__device__ HSLColor rgb2hsl(uchar3 rgb);
__global__ void saturation_kernel(uchar3* input, uchar3* output, int width, int height, int c);
void saturation_host(cv::Mat& image, std::string path, int c);

#endif /* SATURATION_H */