require 'matrix'
require 'pathname'

def polyfit(x, y, degree)
  x = x.to_a
  y = y.to_a

  m = Matrix.build(x.size, [degree, x.size].min) do |i, j|
    x[i]**j
  end

  b = (m.transpose * m).inverse * m.transpose * Vector.elements(y)

  return b.to_a
end

def read_txt_file(file_path)
  # Initialize variables
  first_integer = nil
  array1 = []
  array2 = []

  # Read the file
  File.open(file_path, 'r') do |file|
    # Read the first line and extract the first integer
    first_integer = file.readline.to_i + 1

    # Read the remaining lines
    file.each_line do |line|
      # Split the line into two integers
      values = line.split.map(&:to_f)
      array1 << values[0]
      array2 << values[1]
    end
  end

  # Return the results
  [first_integer, array1, array2]
end

def write_array_to_file(array, file_path)
  # Open the file in write mode
  File.open(file_path, 'w') do |file|
    # Iterate over each element in the array
    array.each do |element|
      # Write the element to the file
      file.puts(element.to_s)
    end
    puts "List contents successfully written to #{file_path}"
  end
end

def get_parent_directory(file_path)
  path = Pathname.new(file_path)
  parent_directory = path.dirname
  parent_directory.to_s
end

# Example usage:
puts "Enter the file: "
filepath = gets.chomp
input = read_txt_file(filepath)
coefficients = polyfit(input[1], input[2], input[0])
puts "Polynomial coefficients: #{coefficients}"
write_array_to_file(coefficients, get_parent_directory(filepath) + "/output.txt")
