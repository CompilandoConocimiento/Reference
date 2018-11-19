// /**
//  * Function to aproximate a root of f(x) using the Newton Raphson method
//  *
//  * @param: estimation a initial guess to the root
//  * @param someFunction - a string that represent the expression to get x 
//  * @param tolerance - a number to set how exact you want a root
//  * @param MaxIterations - a number of maximum iterations
//  * @return estimation - a number such someFunction(estimation) = 0
//  *
//  * @author: Rosas Hernandez Oscar Andres
//  * @author: Alarcón Alvarez Aylin Yadira Guadalupe
//  * @author: Laurrabaquio Rodríguez Miguel Salvador
//  * @author: Pahua Castro Jesús Miguel Ángel
//  */

function [estimation, iterations] = NewtonRaphson(estimation, someFunction, tolerance, MaxIterations)
    deff('y = f(x)', ['y = evstr(someFunction)']);
    iterations = 0;

    while ((abs(f(estimation)) > tolerance) && (iterations < MaxIterations))
        oldEstimation = estimation;
        estimation = NewtonRaphsonStep(estimation, f);

        if (RelativeDifference(oldEstimation, estimation) < tolerance) 
            break 
        end

        iterations = iterations + 1;
    end
endfunction

function [estimation] = NewtonRaphsonStep(estimation, f)
    dx = 10^-7;
    derivative = (f(estimation + dx) - f(estimation)) / dx; 
    estimation = estimation - f(estimation) / derivative;
endfunction
