// Get the norm 1 (max in columns)
// @param: A a matriz
// @return: r which is r = |A|

function [r] = NormInfty(A)
    [m, n] = size(A);
    r = 0;

    for row = (1 : m)
        temporal = 0
        for column = (1 : n)
            temporal = temporal + abs(A(row, column))
        end
        if temporal > r
            r = temporal
        end
    end
endfunction