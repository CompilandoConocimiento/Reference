// Get the estimated solution to Ax = b using the HouseHolder transformation
// @param: A a matriz in M_{m x n} where m > n
// @return: Q a matriz in M_{m x m} that is ortogonal
// @return: R a matriz in M_{m x n} that is triangular superior

// @Author: Rosas Hernandez Oscar Andres
// @Author: Alarcón Alvarez Aylin Yadira Guadalupe
// @Author: Laurrabaquio Rodríguez Miguel Salvador
// @Author: Pahua Castro Jesús Miguel Ángel

function [Q, R] = Givens(A)
    [m, n] = size(A);
    Q = eye(m, m);
    R = A;
  
    for j = (1 : n)
        for i = (m : -1 : j + 1)
            GivenMatrix = eye(m, m);
            [c, s] = GivensRotations(R(i-1, j), R(i, j));
            GivenMatrix([i-1, i], [i-1, i]) = [c -s; s c];

            R = GivenMatrix' * R;
            Q = Q * GivenMatrix;
        end
    end

end

function [c,s] = GivensRotations(a,b)
    if (b == 0)
        c = 1;
        s = 0;
    else
        if abs(b) > abs(a)
            r = a / b;
            s = 1 / sqrt(1 + r**2);
            c = s * r;
        else
            r = b / a;
            c = 1 / sqrt(1 + r**2);
            s = c * r;
        end
    end

end