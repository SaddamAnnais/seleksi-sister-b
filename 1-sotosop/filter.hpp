#ifndef FILTER_H
#define FILTER_H

#include <opencv2/core.hpp>
#include <string>

void applyFilter(cv::Mat& image, int chosenFilter, std::string path, int c);

#endif /* FILTER_H */