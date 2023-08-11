#include <iostream>
#include <fstream>
#include <stdexcept>
#include <Eigen/Dense>

using namespace Eigen;

VectorXd polyfit(const VectorXd& x, const VectorXd& y, int degree)
{
    MatrixXd m(x.size(), std::min(degree, static_cast<int>(x.size())));
    m.setOnes();

    for (int i = 1; i < m.cols(); ++i) {
        m.col(i) = m.col(i - 1).array() * x.array();
    }

    //std::cout << m;
    //std::cout << y;
    return m.completeOrthogonalDecomposition().pseudoInverse() * y;
}

std::tuple<int, VectorXd, VectorXd> readFile(const std::string& filePath)
{
    std::ifstream file(filePath);
    if (!file)
    {
        throw std::runtime_error("File not found.");
    }

    int firstValue;
    file >> firstValue;
    firstValue += 1;

    int numValues = 0;
    double x, y;
    while (file >> x >> y)
    {
        numValues++;
    }

    VectorXd xArray(numValues);
    VectorXd yArray(numValues);

    file.clear();
    file.seekg(0);

    // Skip the first line
    std::string line;
    std::getline(file, line);

    for (int i = 0; i < numValues; i++)
    {
        file >> x >> y;
        xArray(i) = x;
        yArray(i) = y;
    }

    return std::make_tuple(firstValue, xArray, yArray);
}

void writeArrayToFile(const std::string& filePath, const VectorXd& array)
{
    std::ofstream file(filePath);
    if (!file)
    {
        throw std::runtime_error("Error opening file for writing.");
    }

    for (int i = 0; i < array.size(); i++)
    {
        file << array(i) << "\n";
    }

    std::cout << "Array successfully written to the file: " << filePath << std::endl;
}

std::string getParentDirectory(const std::string& filePath)
{
    std::size_t found = filePath.find_last_of("/\\");
    if (found != std::string::npos)
    {
        return filePath.substr(0, found);
    }
    else
    {
        throw std::runtime_error("The specified path does not have a parent directory.");
    }
}

int main()
{
    std::cout << "Enter the file: ";
    std::string filePath;
    std::cin >> filePath;

    try
    {
        auto result = readFile(filePath);

        int degree = std::get<0>(result);
        VectorXd x = std::get<1>(result);
        VectorXd y = std::get<2>(result);

        VectorXd coefficients = polyfit(x, y, degree);
        std::cout << "Polynomial coefficients: " << coefficients.transpose() << std::endl;

        writeArrayToFile(getParentDirectory(filePath) + "/output.txt", coefficients);
    }
    catch (const std::exception& ex)
    {
        std::cout << "An error occurred: " << ex.what() << std::endl;
    }

    return 0;
}