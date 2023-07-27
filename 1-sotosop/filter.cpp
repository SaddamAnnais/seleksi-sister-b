#include "filter.hpp"
#include "image_io.hpp"
#include "grayscale.cuh"
#include "contrast.cuh"
#include "saturation.cuh"

void applyFilter(cv::Mat& image, int chosenFilter, std::string path, int c) {
	loadImage(path, image);
	if (chosenFilter == 1) grayscale_host(image, path);
	else if (chosenFilter == 2) contrast_host(image, path, c);
	else if (chosenFilter == 3) saturation_host(image, path, c);
}