//Función que calcula la factorización LU de A una matriz de nxn
//mediante matrices de eliminación
//Parámetros de entrada 
//A: Una matriz no singular de nxn

function [L, U] = FactorLU(A)
        [m, n] = size(A);
        invM = eye(m,n);
        for k = (1 : n - 1)
            if (A(k, k) == 0)
                disp('No se puede resolver');
                return;
            else
                for i = (k + 1 : n)
                    invM(i, k) = A(i, k) / A(k, k);
                end
                for j = (1 : n)
                    for i = (k + 1 : n)
                        A(i,j) = A(i, j) - invM(i, k) * A(k,j);
                    end
                end
            end
        end

    L = invM; 
    U = A; 
endfunction
