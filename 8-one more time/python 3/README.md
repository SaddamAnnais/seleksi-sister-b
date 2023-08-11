# Polynomial Interpolation using Python 3
Simple program to predict the polynom of the given point using least squares

## Requirement
Each installation tutorial is on the link.
- [Python 3]([https://www.python.org/downloads/](https://go.dev/doc/install))
- [Go]([https://pypi.org/project/numpy/](https://pkg.go.dev/gonum.org/v1/gonum/mat))

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
3.0
1.0
2.0
```

## How to Run

```Python
python './python 3/interpol.py'

```

## Example 
```
Enter the file: ./test/1.txt
Polynomial coefficients: [3. 1. 2.]
List contents successfully written to ./test/output.txt
```
