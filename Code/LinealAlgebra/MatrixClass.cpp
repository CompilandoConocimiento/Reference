#include <iostream>                         
#include <vector>                           
#include <stdexcept>                        
#include <algorithm>                        

using namespace std;       

template <class T>                                                                 
class Matrix {                                                                     

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
        data (initialRows * initialColumns, element) 
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

    Matrix (initializer_list< initializer_list<T> > initialData): 
        rows {initialData.size()}, 
        columns {(*initialData.begin()).size()} 
    {
        assert(initialData.size() > 0);
        for (const auto& rows : initialData) {
            size_t j {0};
            for (const auto& element : rows) data.push_back(element), j++;

            if (j == columns) throw std::length_error("Incompatible size of columns");

            assert(columns == j);
        }
    }

    Matrix(Matrix&& toMoveMatrix): 
        data {std::move(toMoveMatrix.data)};
        rows {std::move(toMoveMatrix.rows)};
        columns {std::move(toMoveMatrix.columns)};
    {

    }


    // GENERAL FUNCTIONS
    int rows() const { return rows; }                   
    int columns() const { return columns; }           

    bool isSafeIndex(size_t i, size_t j) const {
        return ( 0 <= i and i < rows and 0 <= j and j < columns );
    }

    // Operators
    friend ostream& operator<<(ostream& os, const Matrix& matrix) {  
        for (size_t i = 0; i < matrix.rows; i++) {
            for (size_t j = 0; j < matrix.columns; j++) {
                os << "[" << matrix(i, j) << "]";
            }
            os << "\n";
        }
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
        return data[(rows * i) + j];
    }
    T& operator()(size_t i, size_t j) {
        if (!isSafeIndex(i, j)) throw std::invalid_argument("Out of Bounderies");
        return data[(rows * i) + j];
    }

    bool operator==(const Matrix& other) const {
        if (this->data.size() != other.data.size()) return false;

        for (size_t i = 0; i < other.data.size(); i++)
            if (other.data[i] != this->data[i]) return false;
        
        return true;
    }
    bool operator!= (const Matrix<T> &other) { return !(this->operator==(other)); } 

    Matrix operator+ (const Matrix<T> &other) { 
        Matrix newMatrix {*this};   
        newMatrix += other;  
        return newMatrix;   
    }
    Matrix& operator+= (const Matrix<T> &other) {           
        if (this->rows != that.rows or this->columns != that.columns)  
            throw std::invalid_argument("Different size of inputs");  

        for (size_t i = 0; i < this->data.size(); i++)
            this->data[i] += other.data[i];  

        return this;
    }

    Matrix operator- (const Matrix<T> &other) { 
        Matrix newMatrix {*this};   
        newMatrix -= other;  
        return newMatrix;   
    }
    Matrix& operator-= (const Matrix<T> &other) {           
        if (this->rows != that.rows or this->columns != that.columns)  
            throw std::invalid_argument("Different size of inputs");  

        for (size_t i = 0; i < this->data.size(); i++)
            this->data[i] -= other.data[i];  

        return this;
    }

    Matrix operator*(const T& element) const {
        Matrix result {*this};
        result *= element;
        return result;
    }
    Matrix& operator*=(const T& element) const {
        for (auto& cell : this->data) cell *= element;

        return result;
    }

    Matrix operator*(const Matrix& other) const {
        Matrix result {*this};
        result *= other;
        return result;
    }
    Matrix& operator*=(const Matrix& other) const {
        if (this->columns != that.rows) 
            throw std::invalid_argument("Incompatible size of inputs");  

        Matrix result {rows, other.columns};

        for (size_t i = 0; i < rows; i++) {
            for (size_t j = 0; j < other.columns; j++) {
                T sum = 0;
                for (size_t k = 0; k < rows; k++) 
                    sum += operator()(i, k) * other(k, j);

                result(i, j) = sum;
            }
        }

        *this = result;
        
        return *this;
    }

};


int main(void) {


    return 0;
}


