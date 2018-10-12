#include <iostream>                         
#include <vector>                           
#include <stdexcept>                        
#include <algorithm>                        
#include <functional>                        

using namespace std;

template <class T>                                                                 
class Matrix {   

  private:                                                                         
    std::size_t rows;                                                                   
    std::size_t columns;                                                                

    std::vector<T> data;                                                               

  public:                                                                         
    
    // CONSTRUCTORS
    Matrix (size_t initialRows, size_t initialColumns, T element = T{}): 
        rows {initialRows}, 
        columns {initialColumns}, 
        data (initialRows * initialColumns, element) 
    {
        if (rows < 1 or columns < 1)                                            
        throw std::length_error("Incompatible size of rows or columns");   
    }
    Matrix (size_t initialRows, size_t initialColumns, std::function<T (size_t, size_t)> Function): 
        rows {initialRows}, 
        columns {initialColumns}, 
        data (initialRows * initialColumns) 
    {
        for (size_t i = 0; i < initialRows; ++i)                            
            for (size_t j = 0; j < initialColumns; ++j)       
                (*this)(i, j) = Function(i, j);       
    }

    Matrix (size_t initialRows, size_t initialColumns, const std::vector<T>& initialData): 
        rows {initialRows}, 
        columns {initialColumns}, 
        data (initialData) 
    {
        if (rows * columns != initialData.size())                                            
        throw std::length_error("Incompatible size of rows or columns");   
    }

    Matrix (const std::initializer_list< std::initializer_list<T> > initialData): 
        rows {initialData.size()}, 
        columns {(*initialData.begin()).size()} 
    {
        for (const auto& rows : initialData) {
            size_t j {0};
            for (const auto& element : rows) data.push_back(element), j++;

            if (j != columns) throw std::length_error("Incompatible size of columns");
        }
    }

    Matrix(Matrix&& toMoveMatrix): 
        rows {toMoveMatrix.rows},
        columns {toMoveMatrix.columns},
        data {std::move(toMoveMatrix.data)}
    {

    }

    Matrix(const Matrix& toCopyMatrix): 
        rows {toCopyMatrix.rows},
        columns {toCopyMatrix.columns},
        data {toCopyMatrix.data}
    {

    }

    // GENERAL FUNCTIONS
    size_t getRows() const { return rows; }                   
    size_t getColumns() const { return columns; }           

    bool isSafeIndex(size_t i, size_t j) const {
        return ( 0 <= i and i < rows and 0 <= j and j < columns );
    }

    // Operators
    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
        os << "{";
        for (size_t i = 0; i < matrix.rows; i++) {
            os << "{";
            for (size_t j = 0; j < matrix.columns; j++) {
                os << matrix(i, j);
                if (j + 1 != matrix.columns) os << ",";
            }
            os << "}";
            if (i + 1 != matrix.rows) os << ",";
        }
        os << "}";

        return os;
    }

    Matrix& operator=(Matrix&& other) {
        data = std::move(other.data);
        rows = std::move(other.rows);
        columns = std::move(other.columns);
        return *this;
    }


    T operator()(size_t i, size_t j = T{0}) const {
        if (!isSafeIndex(i, j)) throw std::invalid_argument("Out of Bounderies");
        return data[(columns * i) + j];
    }
    T& operator()(size_t i, size_t j = T{0}) {
        if (!isSafeIndex(i, j)) throw std::invalid_argument("Out of Bounderies");
        return data[(columns * i) + j];
    }

    bool operator==(const Matrix& other) const {
        if (this->data.size() != other.data.size()) return false;

        for (size_t i = 0; i < other.data.size(); i++)
            if (other.data[i] != this->data[i]) return false;
        
        return true;
    }
    bool operator!= (const Matrix<T> &other) const { return !(this->operator==(other)); } 

    Matrix operator+ (const Matrix<T> &other) const { 
        Matrix newMatrix {*this};   
        newMatrix += other;  
        return newMatrix;   
    }
    Matrix& operator+= (const Matrix<T> &other) {           
        if (this->rows != other.rows or this->columns != other.columns)  
            throw std::invalid_argument("Different size of inputs");  

        for (size_t i = 0; i < this->data.size(); i++)
            this->data[i] += other.data[i];  

        return *this;
    }

    Matrix operator- (const Matrix<T> &other) const { 
        Matrix newMatrix {*this};   
        newMatrix -= other;  
        return newMatrix;   
    }
    Matrix& operator-= (const Matrix<T> &other) {           
        if (this->rows != other.rows or this->columns != other.columns)  
            throw std::invalid_argument("Different size of inputs");  

        for (size_t i = 0; i < this->data.size(); i++)
            this->data[i] -= other.data[i];  

        return *this;
    }

    Matrix operator*(const T& element) const {
        Matrix result {*this};
        result *= element;
        return result;
    }
    Matrix& operator*=(const T& element) {
        for (auto& cell : this->data) cell *= element;

        return *this;
    }

    Matrix operator*(const Matrix& other) const {
        Matrix result {*this};
        result *= other;
        return result;
    }
    Matrix& operator*=(const Matrix& other) {
        if (this->columns != other.rows) 
            throw std::invalid_argument("Incompatible size of inputs");  

        Matrix result {rows, other.columns, -1};

        for (size_t i = 0; i < this->rows; i++) {
            for (size_t j = 0; j < other.columns; j++) {
                T sum  {0};
                for (size_t k = 0; k < this->columns; k++) 
                    sum += operator()(i, k) * other(k, j);
                result(i, j) = sum;
            }
        }
        
        *this = std::move(result);
        
        return *this;
    }

};


template <typename T>
pair< Matrix<T>, Matrix<T> > BasicLUDecomposition(const Matrix<T>& A) {
    if (A.getColumns() != A.getRows()) throw invalid_argument("Not square matrix"); 

    const size_t n = A.getColumns();
    Matrix<T> L(n, n, T{0}), U {A};

    for (size_t row = 0; row < n; row++) L(row, row) = T{1};

    for (size_t step = 0; step < n; step++) {
        for (size_t row = step + 1; row < n; row++) {
            if (U(step, step) == T{0}) throw invalid_argument("Singular matrix");  
            L(row, step) =  U(row, step) / U(step, step);

            for (size_t column = 0; column < n; column++)
                U(row, column) += T{-1} * L(row, step) * U(step, column); 
        }
    }

    return {L, U};
}


// L y = b
template <typename T>
Matrix<T> SolveLowerTriangular(const Matrix<T>& L, Matrix<T> b) {
    Matrix<T> y(L.getRows(), 1);

    for (size_t i = 0; i < L.getRows(); i++) {
        if (L(i, i) == T{0}) 
            throw std::invalid_argument("Singular matrix"); 

        y(i) = b(i) / L(i, i);
        
        for (size_t j = i + 1; j < L.getRows(); j++)
            b(j) = b(j) - L(j, i) * y(i);
    }

    return x;
}

// U y = b
template <typename T>
Matrix<T> SolveUpperTriangular(const Matrix<T>& U, Matrix<T> b) {
    Matrix<T> x(U.getRows(), 1);

    for (ssize_t i = U.getRows() - 1; i >= 0; i--) {
        if (U(i, i) == T{0}) 
            throw std::invalid_argument("Singular matrix"); 

        x(i) = b(i) / U(i, i);
        
        for (ssize_t j = i - 1; j >= 0; j--)
            b(j) = b(j) - U(j, i) * x(i);
    }

    return x;
}


int main(void) {

    Matrix<double> A({
        {1 ,  1,  1},
        {4 ,  3, -1},
        {4 ,  5 , 3},
    });

    Matrix<double> b({
        {1},
        {6},
        {4},
    });

    auto [L, U] = BasicLUDecomposition(A);
    cout << A << endl;
    
    cout << L << endl;
    cout << U << endl;
    cout << endl;

    cout << L * U << endl;
    cout << endl;

    auto y = SolveLowerTriangular(L, b);

    cout << "y" << y << endl;
    cout << L * y << endl;
    cout << b << endl;

    cout << endl;

    auto x = SolveUpperTriangular(U, y);
    cout << U * x << endl;
    cout << y << endl;

    cout << endl;

    cout << x << endl;

    cout << A * x << endl;

    return 0;
}


