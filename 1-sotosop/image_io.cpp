#include "image_io.hpp"

void loadImage(const std::string& path, cv::Mat& image) {
    image = cv::imread(path, cv::IMREAD_COLOR);
    if (image.empty()) {
        std::cerr << "Failed to load image: " << path << "\nExitting..." << std::endl;
        exit(0);
    }
}

void saveImage(const std::string& path, cv::Mat& image, const std::string text) {
    size_t last_dot_idx = path.find_last_of(".");
    std::string extension = (last_dot_idx == std::string::npos) ? "" : path.substr(last_dot_idx);
    // Generate the output file path
    std::string output_path = path.substr(0, last_dot_idx) + text + extension;
    if (!cv::imwrite(output_path, image)) std::cerr << "Failed to save image: " << path << std::endl;
    else {
        std::cout << text << " image is saved successfully\n";
        std::cout << "Saved image to " << output_path << std::endl;
    }
}

//System::Drawing::Bitmap^ mat2Bitmap(cv::Mat mat_data) {
//    // convert the Mat data to a Bitmap object
//    System::IntPtr ptr(mat_data.ptr());
//    System::Drawing::Bitmap^ bitmap = gcnew System::Drawing::Bitmap(mat_data.cols, mat_data.rows, mat_data.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr);
//
//    return bitmap;
//
//}
