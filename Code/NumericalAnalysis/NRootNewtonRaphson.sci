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

function [estimation] = NRootNewtonRaphson(A, n, tolerance, MaximumIterations)
    iterations = 0;
    estimation = A;
    
    while ((abs(estimation**n - A) > tolerance) && (iterations < MaximumIterations))
        oldEstimation = estimation;
        estimation = ((n-1) * estimation**n + A) / (n * estimation**(n-1));

        if (RelativeDifference(oldEstimation, estimation) < tolerance) 
            break;
        end

        iterations = iterations + 1;
    end
endfunction


function [estimation] = Roots(A, n)
    if (A == 0) then estimation = 0
    elseif (A > 0)
        estimation = NRootNewtonRaphson(A, n, 10e-7, 50)
    else
        estimation = -NRootNewtonRaphson(A * -1, n, 10e-7, 50)
        if (modulo(n, 2) == 0) then
            theta = %pi / n
            real = estimation * cos(theta)  
            imaginary = estimation * sin(theta) * %i
            estimation = real + imaginary
        else
            estimation = estimation * -1
        end
    end
endfunction
