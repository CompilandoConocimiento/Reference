// Factor A as A = L * U
// @param: A a not singular matrix
// @return: L lower triangule matrix
// @return: U upper triangule matrix

function [L, U] = LUDecomposition(A)
    [m, n] = size(A);
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
    
endfunction