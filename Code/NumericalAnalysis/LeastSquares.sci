// Get the estimated solution to Ax = b using least squares
// @param: A a matriz in M_{m x n} where m > n
// @param: b a vector of m rows
// @return: x a estimated solution

// @Author: Rosas Hernandez Oscar Andres
// @Author: Alarcón Alvarez Aylin Yadira Guadalupe
// @Author: Laurrabaquio Rodríguez Miguel Salvador
// @Author: Pahua Castro Jesús Miguel Ángel

function [x] = LeastSquares(A, b)
    [L] = CholeskyBanachiewicz(A' * A, 1);

    y = FowardSubstitution(L, A' * b);
    x = BackwardSubstitution(L', y);
endfunction

