#include <iostream>                         
#include <vector>                           
#include <stdexcept>                        
#include <algorithm>                        
#include <functional>  


using namespace std;

// Ax = b => (L U) x = b
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