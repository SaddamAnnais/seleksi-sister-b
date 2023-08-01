#include "filter.hpp"
#include "grayscale.cuh"
#include "contrast.cuh"
#include "saturation.cuh"
#include "boxBlur.cuh"
#include "sobel_detection.cuh"

void applyFilter(cv::Mat& input_image, cv::Mat& output_image, uchar3* d_input, uchar3* d_output, int chosenFilter, std::string path, int c, bool save) {
	if (chosenFilter == 1) grayscale_host(input_image, output_image, d_input, d_output, path, save);
	else if (chosenFilter == 2) contrast_host(input_image, output_image, d_input, d_output, path, c, save);
	else if (chosenFilter == 3) saturation_host(input_image, output_image, d_input, d_output, path, c, save);
	else if (chosenFilter == 4) boxBlur_host(input_image, output_image, d_input, d_output, path, c, save);
	else if (chosenFilter == 5) sobelEdgeDetection_host(input_image, output_image, d_input, d_output, path, save);
}