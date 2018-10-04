#include <iostream>                         
#include <vector>                           
#include <stdexcept>                        
#include <algorithm>                        
#include <functional>                        

using namespace std;

// L x = b
template <typename T>
Matrix<T> SolveLowerTriangular(Matrix<T> L, Matrix<T> b) {
    Matrix<T> x(L.getRows(), 1);

    for (size_t i = 0; i < L.getRows(); i++) {
        if (L(i, i) == T{0}) 
            throw std::invalid_argument("Singular matrix"); 

        x(i) = b(i) / L(i, i) ;
        
        for (size_t j = i + 1; j < L.getRows(); j++)
            b(j) = b(j) - L(j, i) * x(i);
    }

    return x;
}

// U x = b
template <typename T>
Matrix<T> SolveUpperTriangular(Matrix<T> U, Matrix<T> b) {
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