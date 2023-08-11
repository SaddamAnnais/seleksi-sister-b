# Polynomial Interpolation using Ruby
Simple program to predict the polynom of the given point using least squares

## Requirement
Each installation tutorial is on the link.
- [Ruby]([https://www.python.org/downloads/](https://www.ruby-lang.org/en/downloads/))

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
3/1
1/1
2/1
```
## How to Run
```Ruby
ruby ./ruby/interpol.rb 

```

## Example 
```
Enter the file: 
./test/1.txt
Polynomial coefficients: [(3/1), (1/1), (2/1)]
List contents successfully written to ./test/output.txt
```
