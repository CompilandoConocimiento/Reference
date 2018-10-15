// Factor A as PA = LU
// @param: A a not singular matrix
// @return: L (not sure) lower triangule matrix
// @return: U upper triangule matrix
// @return: P permutation matrix 

// To solve use PA = LU
// y = FS(PL, Pb)
// x = BS(U, y)

function [L, U, P] = PartialLUDecomposition(A)
    [m, n] = size(A);
    P = eye(n, n); L = eye(n, n); U = A;

    for step = (1 : n - 1)
        
        maxPivotRow = step;
        for posibility = (step + 1 : n)
            if abs(U(posibility, step)) > U(maxPivotRow, step)
                maxPivotRow = posibility
            end
        end

        if (A(maxPivotRow, step) == 0)
            error('Error: Singular matrix'); 
        end

        if maxPivotRow ~= step
            if step >= 2
                for column = (1 : step - 1)
                    temporal = L(step, column);
                    L(step, column) = L(maxPivotRow, column);
                    L(maxPivotRow, column) = temporal;
                end
            end

            for element = (1 : n)
                temporal = U(step, element)
                U(step, element) = U(maxPivotRow, element)
                U(maxPivotRow, element) = temporal

                temporal = P(step, element)
                P(step, element) = P(maxPivotRow, element)
                P(maxPivotRow, element) = temporal
            end
        end
            
        for row = (step + 1 : n)
            L(row, step) = U(row, step) / U(step, step);
            for column = (1 : n)
                U(row, column) = U(row, column) - L(row, step) * U(step, column);
            end
        end
    end

endfunction