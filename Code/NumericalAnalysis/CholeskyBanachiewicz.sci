// Factor A as A = L * L^T
// using the famous algorithm called Cholesky using this really awesome propierty
// First A = L U then we make U a unit upper triangular matrix so we have L D L' and then
// we do L D2 D2 L' were D2(i, j) = sqrt(D(i, j)) finally we associate and we have A = L2 * L2'
// where L2 = L * D2
// @param: A a positive defined matrix (so A is symetric)
// @param: option if 1 then A = L * L else A = L * D * L
// @return: L lower triangule matrix

// @Author: Rosas Hernandez Oscar Andres
// @Author: Alarcón Alvarez Aylin Yadira Guadalupe
// @Author: Laurrabaquio Rodríguez Miguel Salvador
// @Author: Pahua Castro Jesús Miguel Ángel

function[L, D] = CholeskyBanachiewicz(A, option)
    [m, n] = size(A);       
    D = eye(n, n);     
    L = eye(m, n);
    U = A; 

    for step = (1 : n - 1)
        if (A(step, step) == 0)
            error('Error: Singular matrix');
            return;
        end

        for row = (step + 1 : n)
            L(row, step) = U(row, step) / U(step, step);
            for column = (1 : n)
                U(row, column) = U(row, column) - L(row, step) * U(step, column);
            end
        end
    end

    if option == 1
        for step = (1 : n) 
            for row = (step : n) 
                L(row, step) = L(row, step) * sqrt(U(step, step));
            end
        end
    else
        for step = (1 : n) 
            D(step, step) = U(step, step);
        end
    end



endfunction