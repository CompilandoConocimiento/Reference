// Get the estimated solution to QRx = b
// @param: Q a matriz in M_{m x m} that is ortogonal
// @param: R a matriz in M_{m x n} that is triangular superior
// @return: x a estimated solution

// @Author: Rosas Hernandez Oscar Andres
// @Author: Alarcón Alvarez Aylin Yadira Guadalupe
// @Author: Laurrabaquio Rodríguez Miguel Salvador
// @Author: Pahua Castro Jesús Miguel Ángel
function [x] = QRDecomposition(Q, R, b)
    x = BackwardSubstitution(R, Q' * b);
endfunction

