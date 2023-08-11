# Polynomial Interpolation using C#
Simple program to predict the polynom of the given point using least squares

## Requirement
Each installation tutorial is on the link.
- [Visual Studio 2017 or higher](https://visualstudio.microsoft.com/)
- .NET Core 7

## Input and Output
### Input File Format
The first line is the degree. The next line until finished is the x and y point. For example, if we wanted to find the 2 degree polynom and the polynom is going through (0,3), (1,6), and (2, 13), we should input it as follow
```
2
0 3
1 6
2 13
```

### Output File Format
Each line correspond to the power of the x. So the first line is x^0, the second line is x^1, and so on. Here's what `3 + x + 2x^2` looks like
```
2,9999999999999982
1,0000000000000044
1,9999999999999973
```
## How to Run
### Using Visual Studio 2022
1. Open the `.sln` file using Visual Studio
2. When opened, it will configure the NuGet dependencies autmatically.
3. If somehow the `MathNet.Numerics` isn't installed automatically, install it using the NuGet package manager.
4. Run the program by clicking the start button.

### Using the binary file
Execute the following command from C# project folder
```shell
./bin/Release/net7.0/C#.exe
```
## Example 
```
Enter the file: 
../test/1.txt 
Polynomial coefficients: 2,9999999999999982, 1,0000000000000044, 1,9999999999999973
Array successfully written to the file: ..\test\output.txt
```
