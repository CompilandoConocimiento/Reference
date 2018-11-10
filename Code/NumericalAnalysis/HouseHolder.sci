// Get the estimated solution to Ax = b using the HouseHolder transformation
// @param: A a matriz in M_{m x n} where m > n
// @return: Q a matriz in M_{m x m} that is ortogonal
// @return: R a matriz in M_{m x n} that is triangular superior

// @Author: Rosas Hernandez Oscar Andres
// @Author: Alarcón Alvarez Aylin Yadira Guadalupe
// @Author: Laurrabaquio Rodríguez Miguel Salvador
// @Author: Pahua Castro Jesús Miguel Ángel

function [Q, R] = HouseHolder(A, b)
    [m, n] = size(A);
    Q = eye(m, m);

    
    for i = (1 : n)
        aei = zeros(m - i + 1, 1);

        alpha = -sign(A(i,i)) * norm(A(i : m, i));
        aei(1) = alpha
        
        v = A(i : m, i) - aei;
        HouseHolder = eye(m - (i-1), m-(i-1)) -2 * ((v * v') / (v' * v));

        RealHouseHolder = eye(m, m);
        RealHouseHolder(i : m, i : m) = HouseHolder;

        A = RealHouseHolder * A;
        Q = Q * RealHouseHolder;
    end 
    R = A;

endfunction
