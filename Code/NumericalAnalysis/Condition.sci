// Estimates the condition of a Matrix: (|A||A^{-1}|)
// @param: A a not singular matrix
// @return: result the estimation

function [result] = Condition(A, numberOfTimes)
    [m, n] = size(A);
    if m ~= n
        error('Error: Not square matrix'); 
    end

    [normA] = Norm1(A);
    normAInverse = 0;

    [L, U, P] = PartialLUDecomposition(A);

    for i = (1 : numberOfTimes)

        randomC = zeros(n, 1);
        for i = (1 : n)
            if rand() < 0.5 then
                randomC(i) = 1;
            else 
                randomC(i) = -1;
            end
        end

        v = FowardSubstitution(U', P * randomC);
        y = BackwardSubstitution(L', v);

        t = FowardSubstitution(L, P * y);
        z = BackwardSubstitution(U, t);

        temporal = Norm1(z) / Norm1(y);
        if temporal > normAInverse then
            normAInverse = temporal;
        end
    end

    result = normA * normAInverse;

endfunction