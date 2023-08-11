using MathNet.Numerics.LinearAlgebra;

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

    public static void Main()
    {
        double[] x = { 0, 1, 2 };
        double[] y = { 3, 6, 13 };
        int degree = 3;

        double[] coefficients = Polyfit(x, y, degree);
        Console.WriteLine("Polynomial coefficients: " + string.Join(", ", coefficients));
    }
}