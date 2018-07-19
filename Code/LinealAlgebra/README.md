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
//Create a 'Empty' Matrix of 4 Rows and 5 Columns
Matrix<char> M1(4, 5);

//Create a Matrix with a Vector with Data
Matrix<int> M2(3, 3, {1, 2, 3, 4, 5, 6, 7, 8, 9}); 

//This way yo can do this like this
Matrix<double> M1(3, 4, {
    1   ,  4    ,  6    , -7    , 
    -3  , -7    , -8    , 6     , 
    2   ,  12   , 17    , -32   , 
});

//Create a copy Matrix
Matrix<T> NewM1(M1); 

//Create a Matrix and fill it with result of a Lamda Expression
Matrix<T> M1(3, 3, [](auto &M, int i, int j) {return Value});
```

### Fill a Matrix with a Function

You can fill any Matrix with the result of a Function, this
function should take 3 arguments:

* First argument is a reference to itself (auto &Matrix should work fine) 
* Second argument is a int, refering to the number of Row
* Third argument is a int, refering to the number of Column

And I should return the value of the Matrix in this spot.

```c++
//You can create a Matrix and fill it with a Lamda Expression
Matrix<T> M1(3, 3, [](auto &M, int i, int j) {return Value});

//M1 and M2 are the Same
Matrix<T> M1(3, 3, {1, 2, 3, 4, 5, 6, 7, 8, 9});
Matrix<int> M2(3, 3, [](auto &M, int i, int j) {return M.GetRows() * i + j + 1;}); 


//Transform M3 into Indentity
M3.Populate([](auto &M, int i, int j) {return 1;}); 
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

//Create an Identity of 1.0
auto SomeIdentity = Matrix<double>::CreateIdentity(3);
```

### Elemental Operations Functions
```c++
//Swap Row of Column
M1.SwapRow(OriginRow, DestinationRow);
M1.SwapColumn(OriginColumn, DestinationColumn);

M1.ScaleRow(RowNumber, Scale);
M1.ScaleColumn(ColumnNumber, Scale);

M1.PivotRow(Destination, Reference, Scale);
M1.PivotColumn(Destination, Reference, Scale);
```

### Set ZERO and UNIT
```c++
//Set what it means a zero (epsilon also count)
Matrix<double>::SetUNIT(1.0);
Matrix<double>::SetZERO(1e-10);
```

### Gauss Jordan
```c++
//Get Gaussian Elimination
M1.GaussianElimination();
```


* * *


### Author

[SoyOscarRH:  Oscar Andrés Rosas Hernandez](https://github.com/SoyOscarRH).

### License

This project is under the GNU V2 License - you can check it out in [LICENSE.md](LICENSE.md)

