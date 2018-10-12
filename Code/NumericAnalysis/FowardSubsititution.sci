// Solve a system Ly = b where L is triangular inferior
// @param: L triangular inferior matrix
// @param: b the b in Ly = b
// @return: x the solution vector

function [y] = FowardSubstitution(L, b)
    [m, n] = size(L);
    y = zeros(n, 1);

    for i = (1 : n)
        if (L(i, i) == 0)
            error('Error: Singular matrix');
            return;
        end

        y(i) = b(i) / L(i, i);

        for j = (i + 1 : n)
            b(j) = b(j) - L(j, i) * y(i);
        end
    end
endfunction
