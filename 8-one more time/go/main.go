package main

import (
	"fmt"
	"math"

	"gonum.org/v1/gonum/mat"
)

func polyfit(x, y []float64, degree int) []float64 {
	yVec := mat.NewVecDense(len(y), y)

	m := mat.NewDense(len(x), min(degree, len(x)), nil)
	for i := 0; i < min(degree, len(x)); i++ {
		for j := 0; j < len(x); j++ {
			m.Set(j, i, pow(x[j], float64(i)))
		}
	}

	var b mat.VecDense
	b.SolveVec(m, yVec)

	return b.RawVector().Data
}

func pow(base, exponent float64) float64 {
	return math.Pow(base, exponent)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	x := []float64{0, 1, 2}
	y := []float64{3, 6, 13}
	degree := 3

	coefficients := polyfit(x, y, degree)
	fmt.Printf("Polynomial coefficients: %v\n", coefficients)
}