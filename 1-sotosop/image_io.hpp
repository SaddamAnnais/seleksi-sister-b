#ifndef IMAGE_IO_H
#define IMAGE_IO_H

#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>

//using namespace System;
//using namespace System::Drawing;


void loadImage(const std::string& path, cv::Mat& image);
void saveImage(const std::string& path, cv::Mat& image, const std::string text);

#endif // IMAGE_IO_H