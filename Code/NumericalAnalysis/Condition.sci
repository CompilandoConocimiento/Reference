function [result] = Condition(A, number)
    [m, n] = size(A);
    [normA] = Norm1(A);
    normAInverse = 0;

    for i = (1 : number)
        randomY = rand(n, 1, 'uniform');
        [randomZ] = GaussianElimination(A, randomY);
        temporal = Norm1(randomZ) / Norm1(randomY);
        if temporal > normAInverse
            normAInverse = temporal;
        end
    end

    result = normA * normAInverse;

endfunction


function [r] = Norm1(A)
    [m, n] = size(A);
    r = 0;

    for column = (1 : n)
        temporal = 0
        for row = (1 : m)
            temporal = temporal + abs(A(row, column))
        end
        if temporal > r
            r = temporal
        end
    end
endfunction


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