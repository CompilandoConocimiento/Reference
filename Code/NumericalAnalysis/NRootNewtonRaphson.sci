// Function to aproximate a \sqrt[n]{A} using the Newton Raphson method
// @param: x_0 a initial guess
// @param: someFunction a string that represent the expression to get x 
// @param: tolerance a number to set how exact you want a root
// @param: MaximumIterations a number of maximum iterations
// @return: estimation

// @Author: Rosas Hernandez Oscar Andres
// @Author: Alarcón Alvarez Aylin Yadira Guadalupe
// @Author: Laurrabaquio Rodríguez Miguel Salvador
// @Author: Pahua Castro Jesús Miguel Ángel

function [estimation] = NRootNewtonRaphson(x0, n, A, tolerance, MaximumIterations)
    iterations = 0;
    estimation = x0;
    
    while ((abs(estimation**n - A) > tolerance) && (iterations < MaximumIterations))
        oldEstimation = estimation;
        estimation = ((n-1) * estimation**n + A) / (n * estimation**(n-1));

        if (RelativeDifference(oldEstimation, estimation) < tolerance) 
            break;
        end

        iterations = iterations + 1;
    end
endfunction
