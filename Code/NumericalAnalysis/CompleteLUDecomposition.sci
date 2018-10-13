// Factor A as PAQ = LU
// @param: A a not singular matrix
// @return: L (not sure) lower triangule matrix
// @return: U upper triangule matrix
// @return: P permutation matrix 
// @return: Q permutation matrix 

// JUST BECAUSE I WRITE IT, IT DOES NOT MEAN IT IS FAST, IT IS NOT FAST!

function [L, U, P, Q] = CompleteLUDecomposition(A)
    [m, n] = size(A);
    if (m ~= n) == 0 then
        error('Error: Not square matrix'); 
    end
    P = eye(n, n);
    Q = eye(n, n);
    L = eye(n, n);
    U = A;

    for step = (1 : n - 1)
        Qi = eye(n, n);
        Pi = eye(n, n);

        [maxIndex, index] = max(abs(A(step : n, step : n)));
        index(1) = index(1) + step - 1;
        index(2) = index(2) + step - 1;

        if (maxIndex == 0)
            error('Error: Singular matrix'); 
        end

        temporal = Pi(step, :);
        Pi(step, :) = Pi(index(1), :);
        Pi(index(1), :) = temporal;

        temporal = Qi(:, step);
        Qi(:, step) = Qi(:, index(2));
        Qi(:, index(2)) = temporal;

        temporal = U(step, :);
        U(step, :) = U(index(1), :);
        U(index(1), :) = temporal;

        temporal = U(:, step);
        U(:, step) = U(:, index(2));
        U(:, index(2)) = temporal;

        for row = (step + 1 : n)
            L(row, step) = U(row, step) / U(step, step);
            for column = (1 : n)
                U(row, column) = U(row, column) - L(row, step) * U(step, column);
            end
        end

        Q = Q * Qi;
        P = Pi * P;
    end

endfunction