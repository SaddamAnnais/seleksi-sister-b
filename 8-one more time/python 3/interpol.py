import numpy as np
import os

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

    b = np.linalg.pinv(m) @ y
    
    return np.round(b, decimals=5)

def read_txt_file(file_path):
    with open(file_path, 'r') as file:
        lines = file.readlines()

    # Extract the first integer
    first_integer = int(lines[0]) + 1

    # Extract the pairs of integers and split them into two separate lists
    pairs = [line.split() for line in lines[1:]]
    first_list, second_list = zip(*pairs)
    first_list = list(map(int, first_list))
    second_list = list(map(int, second_list))

    return first_list, second_list, first_integer

def write_arr_to_file(arr, file_path):
    try:
        with open(file_path, 'w') as file:
            for item in arr:
                file.write(str(item) + '\n')
        print(f"List contents successfully written to {file_path}")
    except IOError:
        print("An error occurred while writing to the file.")

def get_parent_directory(file_path):
    parent_directory = os.path.dirname(file_path)
    return parent_directory        

# Example usage:
if __name__ == '__main__':
    filepath = input('Enter the file: ')        
    x, y, degree = read_txt_file(filepath)
    coefficients = polyfit(x, y, degree)
    print(f"Polynomial coefficients: {coefficients}")
    write_arr_to_file(coefficients, get_parent_directory(filepath)+'/output.txt')