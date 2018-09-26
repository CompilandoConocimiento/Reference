#include <iostream>                         
#include <vector>                           
#include <stdexcept>                        
#include <algorithm>                        
#include <functional>                        

template <class T>                                                                 
class Matrix {   
  using namespace std;       

  private:                                                                         
    std::size_t rows;                                                                   
    std::size_t columns;                                                                

    vector<T> data;                                                               

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
    Matrix (size_t initialRows, size_t initialColumns, function<T (size_t, size_t)> Function): 
        rows {initialRows}, 
        columns {initialColumns}, 
        data (initialRows * initialColumns) 
    {
        for (size_t i = 0; i < initialRows; ++i)                            
            for (size_t j = 0; j < initialColumns; ++j)       
                (*this)(i, j) = Function(i, j);       
    }

    Matrix (size_t initialRows, size_t initialColumns, const vector<T>& initialData): 
        rows {initialRows}, 
        columns {initialColumns}, 
        data (initialData) 
    {
        if (rows * columns != initialData.size())                                            
        throw std::length_error("Incompatible size of rows or columns");   
    }

    Matrix (const initializer_list< initializer_list<T> > initialData): 
        rows {initialData.size()}, 
        columns {(*initialData.begin()).size()} 
    {
        assert(initialData.size() > 0);
        for (const auto& rows : initialData) {
            size_t j {0};
            for (const auto& element : rows) data.push_back(element), j++;

            if (j == columns) throw std::length_error("Incompatible size of columns");
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
    int getRows() const { return rows; }                   
    int getColumns() const { return columns; }           

    bool isSafeIndex(size_t i, size_t j) const {
        return ( 0 <= i and i < rows and 0 <= j and j < columns );
    }

    // Operators
    friend ostream& operator<<(ostream& os, const Matrix& matrix) { 
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


    T operator()(size_t i, size_t j) const {
        if (!isSafeIndex(i, j)) throw std::invalid_argument("Out of Bounderies");
        return data[(columns * i) + j];
    }
    T& operator()(size_t i, size_t j) {
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