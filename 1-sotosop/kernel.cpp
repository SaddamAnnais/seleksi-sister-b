#include <iostream>
#include <string>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <cuda_runtime.h>
#include <cuda.h>

#include "image_io.hpp"
#include "grayscale.cuh"
#include "saturation.cuh"
#include "contrast.cuh"


using namespace std;
using namespace cv;

int main() {
    // Get the path to the image file
    string path;
    cout << "Enter the path to the image file: ";
    cin >> path;

    // Load the image
    Mat image;
    loadImage(path, image);

    // Input from user
    string input;
    cout << "Enter 1 for grayscale, 2 for contrast, 3 for saturation: ";
    cin >> input;

    // Launch the CUDA kernel to convert the image
    if (input == "1") grayscale_host(image, path);

    else if (input == "2") {
        int c;
        cout << "Enter the contrast value c: ";
        cin >> c;
        contrast_host(image, path, c);
    }
    else if (input == "3") {
        int c;
        cout << "Enter the saturation value c: ";
        cin >> c;
        saturation_host(image, path, c);
    }
    return 0;
}