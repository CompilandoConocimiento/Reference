// /**
//  * Function to aproximate a root of f(x) using the Newton Raphson method
//  *
//  * @param: estimation a initial guess to the root
//  * @param f - a function :v
//  * @param tolerance - a number to set how exact you want a root
//  * @param MaxIterations - a number of maximum iterations
//  * @return estimation - a number such someFunction(estimation) = 0
//  *
//  * @author: Rosas Hernandez Oscar Andres
//  * @author: Alarcón Alvarez Aylin Yadira Guadalupe
//  * @author: Laurrabaquio Rodríguez Miguel Salvador
//  * @author: Pahua Castro Jesús Miguel Ángel
//  */

function [estimation, iterations] = NewtonRaphson(estimation, f, tolerance, MaxIterations)
    iterations = 0;

    while ((abs(norm(f(estimation))) > tolerance) && (iterations < MaxIterations))
        oldEstimation = estimation;
        estimation = NewtonRaphsonStep(estimation, f);

        if (isnan(estimation)) then
            disp("Wrong initial point")
            break;
        elseif (RelativeDifference(oldEstimation, estimation) < tolerance) 
            break 
        end

        iterations = iterations + 1;
    end
endfunction

function [estimation] = NewtonRaphsonStep(estimation, f)
    dx = 10^-6;
    derivative = (f(estimation + dx) - f(estimation)) / dx; 
    estimation = estimation - f(estimation) / derivative;
endfunction


function [estimation, iterations] = NewtonRaphsonGeneralized(estimation, f, tolerance, MaxIterations)
    iterations = 0;
    [n, _] = size(estimation)
    [m, _] = size(f(estimation))

    while ((abs(norm(f(estimation))) > tolerance) && (iterations < MaxIterations))
        oldEstimation = estimation;
        estimation = NewtonRaphsonGeneralizedStep(estimation, f, m, n);

        if (isnan(estimation)) then
            disp("Wrong initial point")
            break;
        elseif (RelativeDifference(oldEstimation, estimation) < tolerance) 
            break;
        end

        iterations = iterations + 1;
    end
endfunction

function [estimation] = NewtonRaphsonGeneralizedStep(estimation, f, m, n)
    jacobian = Jacobian(f, estimation);
    if (m == n)
        [L, U] = LUDecomposition(jacobian);
        y = FowardSubstitution(L, -f(estimation));
        S = BackwardSubstitution(U, y);
    else
        S = LeastSquares(jacobian, -f(estimation));
    end
    estimation = estimation + S;
endfunction
