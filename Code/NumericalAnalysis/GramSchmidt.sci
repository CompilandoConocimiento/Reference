// Get the estimated solution to Ax = b using the Gramm-Schmmidt transformation
// @param: A a matriz in M_{m x n} where m > n
// @param: option if 1 then is the alterate else is the classic algorithm
// @return: Q a matriz in M_{m x m} that is ortogonal
// @return: R a matriz in M_{m x n} that is triangular superior


// @Author: Rosas Hernandez Oscar Andres
// @Author: Alarcón Alvarez Aylin Yadira Guadalupe
// @Author: Laurrabaquio Rodríguez Miguel Salvador
// @Author: Pahua Castro Jesús Miguel Ángel

function [Q, R] = GramSchmidt(A, option)
    [m, n] = size(A);

    Q = zeros(m, n);
    R = A

    for j = (1:n)
        
        Q(:,j) = A(:, j)
        
        for i = (1 : j - 1)
            if (option == 1) 
                R(i, j) = Q(:, i)' * Q(:, j);
            else 
                R(i, j) = Q(:, i)' * A(:, j);
            end

            Q(:, j) = Q(:, j) - R(i, j) * Q(:, i);
        end

        R(j, j) = norm(Q(:, j));
        Q(:, j) = Q(:, j) / R(j, j);
    end
    
endfunction

