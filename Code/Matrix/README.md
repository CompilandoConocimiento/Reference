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
Matrix<int> m1(4, 5);

//Create a Matrix with a Vector with Data
Matrix<int> m2(3, 3, {1, 2, 3, 4, 5, 6, 7, 8, 9}); 

//This way yo can do this like this
Matrix<double> m3({
    {1   ,  4    ,  6    , -7  },
    {-3  , -7    , -8    , 6   },
    {2   ,  12   , 17    , -32 }
});

//Create a copy Matrix
Matrix<int> newM1 {m1}; 

//Create a Matrix and fill it with result of a Lamda Expression
Matrix<double> m4(3, 3, [](size_t i, size_t j) { return i + j;} );
```

### Fill a Matrix with a Function

You can fill any Matrix with the result of a Function, this
function should take 2 arguments:

* Second argument is a size_t, refering to the number of Row
* Third argument is a size_t, refering to the number of Column

And I should return the value of the Matrix in this spot.


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

* * *


### Author

[SoyOscarRH:  Oscar Andrés Rosas Hernandez](https://github.com/SoyOscarRH).

### License

This project is under the GNU V2 License - you can check it out in [LICENSE.md](LICENSE.md)


