//Función que resuelve un sistema diagonal inferior
//Parametros:
//L:Matríz diagonal inferior del sistema Lx=b
//b:Vector de soluciones del sistema Lx=b

function [x] = SolveDiagonalInferiorSystem(L, b)
    [m, n] = size(L);
    x = zeros(n, 1);
    for j = (1 : n)
        if ( L(j, j) == 0)
            disp('No se puede resolver');
            return;
        else
            x(j) = b(j) / L(j, j);
            for (i = j + 1 : n)
                b(i) = b(i) - L(i, j) * x(j);
            end
        end
    end
endfunction
    //Salida:
    //x:Vector de soluciones o un mensaje de error