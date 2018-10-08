#include <iostream>                         
#include <vector>                           
#include <stdexcept>                        
#include <algorithm>                        
#include <functional> 

using namespace std;

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