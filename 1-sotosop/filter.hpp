#ifndef FILTER_H
#define FILTER_H

#include <opencv2/core.hpp>
#include <string>
#include <vector_types.h>

void applyFilter(cv::Mat& input_image, cv::Mat& output_image, uchar3* d_input, uchar3* d_output, int chosenFilter, std::string path, int c, bool save);

#endif /* FILTER_H */