import numpy as np;

def polyfit(x, y, degree):
    """
    Fits a polynomial of given degree to the data points (x, y) using matrix calculations.
    
    Arguments:
    x -- array-like object representing the x-coordinates of the data points
    y -- array-like object representing the y-coordinates of the data points
    degree -- degree of the polynomial to fit
    
    Returns:
    coefficients -- array of polynomial coefficients in decreasing order of degree
    """
    x = np.asarray(x)
    y = np.asarray(y)
    
    m = np.ones((len(x), min(degree, len(x))))
    for i in range(min(degree, len(x))):
        m[:, i] *= x**i

    b = np.matmul(np.linalg.pinv(m), y)
    
    return b

# Example usage:
x = np.array([0, 1, 2])
y = np.array([3, 6, 13])
degree = 3

coefficients = polyfit(x, y, degree)
print coefficients