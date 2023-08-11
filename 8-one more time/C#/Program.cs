using MathNet.Numerics.LinearAlgebra;
using System.Text;

public class PolynomialFit
{
    public static double[] Polyfit(double[] x, double[] y, int degree)
    {
        var xVector = Vector<double>.Build.DenseOfArray(x);
        var yVector = Vector<double>.Build.DenseOfArray(y);

        var m = Matrix<double>.Build.Dense(x.Length, Math.Min(degree, x.Length), (i, j) => Math.Pow(xVector[i], j));
        var b = m.PseudoInverse() * yVector;

        return b.ToArray();
    }

    public static (int, double[], double[]) ReadFile(string filePath)
    {
        try
        {
            string[] lines = File.ReadAllLines(@filePath, Encoding.UTF8);

            if (lines.Length < 2)
            {
                throw new InvalidDataException("Invalid file format.");
            }

            int firstValue = int.Parse(lines[0]);
            firstValue += 1;

            double[] firstArray = new double[lines.Length - 1];
            double[] secondArray = new double[lines.Length - 1];

            for (int i = 1; i < lines.Length ; i++)
            {
                string[] values = lines[i].Split(' ');

                if (values.Length < 2)
                {
                    throw new InvalidDataException("Invalid file format.");
                }

                firstArray[i-1] = double.Parse(values[0]);
                secondArray[i-1] = double.Parse(values[1]);
            }

            return (firstValue, firstArray, secondArray);
        }
        catch (FileNotFoundException)
        {
            throw new FileNotFoundException("File not found.");
        }
        catch (Exception ex)
        {
            throw new Exception("An error occurred: " + ex.Message);
        }
    }
    public static void WriteArrayToFile(string filePath, double[] array)
    {
        try
        {
            using (StreamWriter writer = new StreamWriter(filePath))
            {
                foreach (double value in array)
                {
                    writer.WriteLine(value);
                }
            }

            Console.WriteLine("Array successfully written to the file: " + filePath);
        }
        catch (Exception ex)
        {
            Console.WriteLine("An error occurred: " + ex.Message);
        }
    }

    public static string GetParentDirectory(string filePath)
    {
        try
        {
            string parentDirectory = Path.GetDirectoryName(filePath);

            if (!string.IsNullOrEmpty(parentDirectory))
            {
                return parentDirectory;
            }
            else
            {
                throw new Exception("The specified path does not have a parent directory.");
            }
        }
        catch (Exception ex)
        {
            throw new Exception("An error occurred: " + ex.Message);
        }
    }

    public static void Main()
    {
        Console.WriteLine("Enter the file: ");
        string filePath = Console.ReadLine();
        var result = ReadFile(filePath);

        int degree = result.Item1;
        double[] x = result.Item2;
        double[] y = result.Item3;

        double[] coefficients = Polyfit(x, y, degree);
        Console.WriteLine("Polynomial coefficients: " + string.Join(", ", coefficients));
        WriteArrayToFile(GetParentDirectory(filePath)+"\\output.txt", coefficients);
    }
}