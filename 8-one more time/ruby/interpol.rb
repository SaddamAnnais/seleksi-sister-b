require 'matrix'

def polyfit(x, y, degree)
  x = x.to_a
  y = y.to_a

  m = Matrix.build(x.size, [degree, x.size].min) do |i, j|
    x[i]**j
  end

  b = (m.transpose * m).inverse * m.transpose * Vector.elements(y)

  return b.to_a
end

# Example usage:
x = Vector[0, 1, 2]
y = Vector[2, 2, 2]
degree = 2

coefficients = polyfit(x, y, degree)
puts "Polynomial coefficients: #{coefficients}"
