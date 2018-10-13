// Solve a system Ux = y where U is an upper triangular 
// @param: U triangular superior matrix
// @param: b the b in Ux = b
// @return: x the solution vector

function [x] = BackwardSubstitution(U, b)
    [m, n] = size(U);
    x = zeros(n, 1);

    for i = (n : -1 : 1)
        if (U(i, i) == 0)
            error('Error: Singular matrix');
            return;
        end

        x(i) = b(i) / U(i,i);

        for j = (1 : i - 1)
            b(j) = b(j) - U(j, i) * x(i);
        end
    end
endfunction