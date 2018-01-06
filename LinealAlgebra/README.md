# MATRIX CLASS C++

This class was made for learning, so expect many suddle mistakes, 
this code is like a simple documentation.


## To Remember

* This is a template class, to you can create a Matrix of almost
  everything.
* To abstract this mathematical object we have 3 elements:
    * The size of Rows (**Rows**)
    * The size of Columns (**Columns**)
    * A vector to store the data (**Data**)



## Learn to Use It

### Constructors
```c++
//Create a 'Empty' Vector of 4 Rows and 5 Columns
Matrix<T> M1(4, 5);

//Create with a Vector with Data
Matrix<T> M2(3, 3, {1, 2, 3, 4, 5, 6, 7, 8, 9}); 

//Create a copy Matrix
Matrix<T> CopyMatrix(M1); 
```

### General Methods
```c++
//Change the Data inside
TestMatrix.Populate({"a", "b", "c", "d"});

//Get the Dimensions
GetRows(); 
GetColumns(); 

//Show the Matrix
std::cout << TestMatrix << std::endl;

//Get the Element of Matrix [M]_{i, j}
T SimpleElement = TestMatrix(i, j);

//Modify the Element of Matrix [M]_{i, j}
TestMatrix(i, j) = "3.1416";

//Swap Matrices
swap(MatrixA, MatrixB);
MatrixA.swap(MatrixB);
```

### Operators
```c++
//Check if Matrices are equal
if (MatrixA == MatrixB)
    std::cout << "We are equals";
    
if (MatrixA != MatrixB)
    std::cout << "We are different";

//Asign Matrix
MatrixA = MatrixB;

//Sum 2 Matrices
Matrix<T> NewSum = MatrixB + MatrixC;

//Diference of 2 Matrices
Matrix<T> NewDiference = MatrixB - MatrixC;
NewDiference += NewDiference;

//Diference of 2 Matrices
Matrix<T> NewDiference = MatrixB - MatrixC;
NewDiference -= MatrixB;

//Multiplicate 2 Matrices
Matrix<T> NewMatrix = MatrixA * MatrixB;

```

### General Functions
```c++
//Get the Trace of a Matrix
int SomeTrace = MatrixA.Trace();

//Create an Identity
auto SomeIdentity = Matrix<double>::CreateIdentity(3, 1.0);
```

### Gauss Jordan Functions
```c++
//Swap Row of Column
M1.SwapRow(OriginRow, DestinationRow);
M1.SwapColumn(OriginColumn, DestinationColumn);

M1.ScaleRow(RowNumber, Scale);
M1.ScaleColumn(ColumnNumber, Scale);

M1.PivotRow(Destination, Reference, Scale);
M1.PivotColumn(Destination, Reference, Scale);


```

* * *


### Author

[SoyOscarRH:  Oscar Andrés Rosas Hernandez](https://github.com/SoyOscarRH).

### License

This project is under the GNU V2 License - you can check it out in [LICENSE.md](LICENSE.md)


