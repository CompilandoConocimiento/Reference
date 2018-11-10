// Factor A as A = L * L^T
// using the famous algorithm called Cholesky using a modification of Gaussian Elimination
// @param: A a positive defined matrix (so A is symetric)
// @return: L lower triangule matrix

// @Author: Rosas Hernandez Oscar Andres
// @Author: Alarcón Alvarez Aylin Yadira Guadalupe
// @Author: Laurrabaquio Rodríguez Miguel Salvador
// @Author: Pahua Castro Jesús Miguel Ángel

function[L] = CholeskyGaussian(A)
    
    [m, n] = size(A);       
    L = zeros(m, n);        
    
    for step = (1 : n)
        A(step, step) = sqrt( A(step, step) );  
        
        for column = (step + 1 : n)
            A (column, step) = A(column, step) / A(step, step);
        end
        
        for i = (step + 1 : n)
            for j = (step + 1 : n)
                A(i, j) = A(i, j) - A(i, step) * A(j, step);
            end
        end
    end
    
    for row = (1 : n)
        for column = (1 : n)
            if (row >= column)
                L(row, column) = A(row, column);
            end
        end
    end

endfunction