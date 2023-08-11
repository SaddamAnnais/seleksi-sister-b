open System
open System.IO
open System.Text
open MathNet.Numerics.LinearAlgebra
open MathNet.Numerics.LinearAlgebra.Double

let polyfit (x : Vector<float>) (y : Vector<float>) (degree : int) : Vector<float> =
    let m = DenseMatrix.Create(x.Count, min degree x.Count, fun i j -> pown (x.[i]) j)
    let b = m.PseudoInverse() * y
    b

let ReadFile (filePath: string) : int * double[] * double[] =
    try
        let lines = File.ReadAllLines(filePath, Encoding.UTF8)
        
        if lines.Length < 2 then
            failwith "Invalid file format."
        
        let mutable firstValue = int(lines.[0])
        firstValue <- firstValue + 1

        let firstArray = Array.zeroCreate<double> (lines.Length - 1)
        let secondArray = Array.zeroCreate<double> (lines.Length - 1)

        for i in 1 .. lines.Length - 1 do
            let values = lines.[i].Split([|' '|], StringSplitOptions.RemoveEmptyEntries)

            if values.Length < 2 then
                failwith "Invalid file format."

            firstArray.[i - 1] <- double(values.[0])
            secondArray.[i - 1] <- double(values.[1])

        (firstValue, firstArray, secondArray)
    with
    | :? FileNotFoundException ->
        raise (FileNotFoundException("File not found."))
    | ex ->
        raise (Exception("An error occurred: " + ex.Message))

let WriteArrayToFile (filePath: string) (array: Vector<float>) =
    try
        use writer = new StreamWriter(filePath)
        
        for value in array do
            writer.WriteLine(value)

        printfn "Array successfully written to the file: %s" filePath
    with
    | ex ->
        printfn "An error occurred: %s" ex.Message

let GetParentDirectory (filePath: string) : string =
    try
        let parentDirectory = Path.GetDirectoryName(filePath)

        match parentDirectory with
        | null | "" ->
            raise (Exception("The specified path does not have a parent directory."))
        | _ ->
            parentDirectory
    with
    | ex ->
        raise (Exception("An error occurred: " + ex.Message))

// Example usage:
printfn "Enter the file path:"
let filepath = Console.ReadLine()
let (degree, arrX, arrY) = ReadFile(filepath)
let x = Vector<float>.Build.Dense(arrX)
let y = Vector<float>.Build.Dense(arrY)

let coefficients = polyfit x y degree
printfn "Polynomial coefficients: %A" coefficients
let outputPath = GetParentDirectory filepath + "\\output.txt"
WriteArrayToFile outputPath coefficients