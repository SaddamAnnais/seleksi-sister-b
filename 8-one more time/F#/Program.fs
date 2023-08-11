open MathNet.Numerics.LinearAlgebra
open MathNet.Numerics.LinearAlgebra.Double

let polyfit (x : Vector<float>) (y : Vector<float>) (degree : int) : Vector<float> =
    let m = DenseMatrix.Create(x.Count, min degree x.Count, fun i j -> pown (x.[i]) j)
    let b = m.PseudoInverse() * y
    b

// Example usage:
let x = Vector<float>.Build.Dense([|0.0; 1.0; 2.0|])
let y = Vector<float>.Build.Dense([|3.0; 6.0; 13.0|])
let degree = 3

let coefficients = polyfit x y degree
printfn "Polynomial coefficients: %A" coefficients