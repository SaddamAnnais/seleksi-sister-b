# Polynomial Interpolation using Python 3
Simple program to predict the polynom of the given point using least squares

## Requirement
Each installation tutorial is on the link.
- [Python 3](https://www.python.org/downloads/)
- [NumPy](https://pypi.org/project/numpy/)

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

```Python
python './python 3/interpol.py'

```
![image](https://github.com/SaddamAnnais/seleksi-sister-b/assets/85011841/4099ebc4-c478-4f8d-870b-fae063076dbc)
