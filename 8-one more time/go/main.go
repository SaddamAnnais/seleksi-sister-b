package main

import (
	"bufio"
	"fmt"
	"io/ioutil"
	"log"
	"math"
	"os"
	"path/filepath"
	"strconv"
	"strings"

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

func readTextFile(filename string) (int, []float64, []float64, error) {
	// Open the file
	file, err := os.Open(filename)
	if err != nil {
		return 0, nil, nil, err
	}
	defer file.Close()

	scanner := bufio.NewScanner(file)

	// Read the first line containing the count
	scanner.Scan()
	count, err := strconv.Atoi(scanner.Text())
	if err != nil {
		return 0, nil, nil, err
	}
	count += 1

	// Read the remaining lines and extract the values
	var firstArray []float64
	var secondArray []float64

	for scanner.Scan() {
		line := scanner.Text()
		parts := strings.Split(line, " ")
		if len(parts) != 2 {
			return 0, nil, nil, fmt.Errorf("invalid line format")
		}

		firstValue, err := strconv.ParseFloat(parts[0], 64)
		if err != nil {
			return 0, nil, nil, err
		}

		secondValue, err := strconv.ParseFloat(parts[1], 64)
		if err != nil {
			return 0, nil, nil, err
		}

		firstArray = append(firstArray, firstValue)
		secondArray = append(secondArray, secondValue)
	}

	if err := scanner.Err(); err != nil {
		return 0, nil, nil, err
	}

	return count, firstArray, secondArray, nil
}

func writeFloatArrayToFile(path string, array []float64) error {
	// Convert the float array to a string representation
	var stringArray []string
	for _, value := range array {
		stringArray = append(stringArray, strconv.FormatFloat(value, 'f', -1, 64))
	}
	data := strings.Join(stringArray, "\n")

	// Write the data to the file
	err := ioutil.WriteFile(path, []byte(data), 0644)
	if err != nil {
		return err
	}

	return nil
}

func getParentDirectory(filePath string) (string, error) {
	absPath, err := filepath.Abs(filePath)
	if err != nil {
		return "", err
	}

	parentDir := filepath.Dir(absPath)
	return parentDir, nil
}

func main() {
	fmt.Print("Enter the file: ")
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	filePath := scanner.Text()

	degree, x, y, err := readTextFile(filePath)
	if err != nil {
		log.Fatal(err)
	}
	
	coefficients := polyfit(x, y, degree)
	fmt.Printf("Polynomial coefficients: %v\n", coefficients)

	parentDir, err := getParentDirectory(filePath)
	if err != nil {
		fmt.Println("Error:", err)
		return
	}

	writeFloatArrayToFile(parentDir + "/output.txt", coefficients)
	if err != nil {
		log.Fatal(err)
	}

	fmt.Println("Polynomial equation is written to file successfully to " + parentDir  + "\\output.txt")
}