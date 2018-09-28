//Función que resuelve un sistema diagonal superior
//Parametros:

//U:Matríz diagonal superior del sistema Ux=b
//b:Vector de soluciones del sistema Ux=b

function [x] = SolveDiagonalSuperiorSystem(U, b)
    [m, n] = size(U);
    x = zeros(n, 1);
    for j = (n : -1 : 1)
        if ( U(j, j) == 0 )
            disp('No se puede resolver');
            return;
        else
            x(j) = b(j) / U(j,j);
            for i = (1 : j - 1)
                b(i) = b(i) - U(i, j) * x(j);
            end
        end
    end
endfunction