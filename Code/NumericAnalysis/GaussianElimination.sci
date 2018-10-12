function [x] = GaussianElimination(A, b)
        [m, n] = size(A);
        U = A, B = b, x = zeros(n, 1)
    
        for step = (1 : n)
            maxPivotRow = step;
            for posibility = (step + 1 : n)
                if abs(U(posibility, step)) > U(maxPivotRow, step)
                    maxPivotRow = posibility
                end
            end
    
            if (A(step, step) == 0)
                error('Error: Singular matrix'); 
            end
    
            if maxPivotRow ~= step
                for element = (1 : n)
                    temporal = U(step, element)
                    U(step, element) = U(maxPivotRow, element)
                    U(maxPivotRow, element) = temporal
                end

                temporal = B(maxPivotRow)
                B(maxPivotRow) = B(step)
                B(step) = temporal
            end

            pivot = U(step, step);
            B(step) = B(step) / pivot
            for column = (1 : n)
                U(step, column) = U(step, column) / pivot;
            end

            for row = (step + 1 : n)
                rowPivot = U(row, step)
                B(row) = B(row) - rowPivot * B(step)
                for column = (1 : n)
                    U(row, column) = U(row, column) - rowPivot * U(step, column);
                end
            end
        end

        for i = (n : -1 : 1)
            x(i) = B(i) / U(i,i);

            for j = (1 : i - 1)
                B(j) = B(j) - U(j, i) * x(i);
            end
        end

    endfunction