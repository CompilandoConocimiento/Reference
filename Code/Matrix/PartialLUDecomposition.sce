// Factor A as A = LU
// @param: A a not singular matrix
// @return: L lower triangule matrix
// @return: U upper triangule matrix
// @return: P permutation matrix 

// To solve use A = LU
// y = FS(PL, Pb)
// x = BS(U, y)

function[L, U, P] = PartialLUDecomposition(A)
    [m, n] = size(A);
    P = eye(m, n);
    L = eye(m, n);
    U = A;

    for step = (1 : n - 1)
        
        maxPivotRow = step;
        for posibility = (step + 1 : n)
            if abs(U(posibility, step)) > U(maxPivotRow, step)
                maxPivotRow = posibility
            end
        end

        if (A(step, step) == 0)
            error('Error: Singular matrix');
            return;
        end

        Pstep = eye(m, n);
        ElimitationMatrix = eye(m, n);
        
        for element = (1 : n)
            temporal = U(step, element)
            U(step, element) = U(maxPivotRow, element)
            U(maxPivotRow, element) = temporal

            temporal = P(step, element)
            P(step, element) = P(maxPivotRow, element)
            P(maxPivotRow, element) = temporal

            temporal = Pstep(step, element)
            Pstep(step, element) = Pstep(maxPivotRow, element)
            Pstep(maxPivotRow, element) = temporal
        end
            
        for row = (step + 1 : n)
            ElimitationMatrix(row, step) = U(row, step) / U(step, step);

            for column = (1 : n)
                U(row, column) = U(row, column) - (ElimitationMatrix(row, step) * U(step, column));
            end
        end

        L = L * (Pstep' * ElimitationMatrix);
    end
endfunction