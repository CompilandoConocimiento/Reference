// Function to aproximate a root of f(x) using the fixed point method , so f(x) can be written as 
// f(x) = g(x) - x = 0
// @param: initialPoint a number
// @param: someFunction a string that represent the g(x)
// @param: tolerance a number to set how exact you want a root
// @param: MaximumIterations a number of maximum iterations
// @return: estimation a number such someFunction(estimation) - estimation = 0

// @Author: Rosas Hernandez Oscar Andres
// @Author: Alarcón Alvarez Aylin Yadira Guadalupe
// @Author: Laurrabaquio Rodríguez Miguel Salvador
// @Author: Pahua Castro Jesús Miguel Ángel

function [estimation] = FixedPoint(initialPoint, someFunction, tolerance, MaximumIterations)
    deff('y = f(x)', ['y = evstr(someFunction)']);
    iterations = 0;
    estimation = f(initialPoint);
    
    while ((abs(norm(f(estimation))) > tolerance) && (iterations < MaximumIterations))
        oldEstimation = estimation;
        estimation = f(estimation);

        if (iterations > 1 && RelativeDifference(oldEstimation, estimation) < tolerance) 
            break;
        end

        iterations = iterations + 1;
    end
endfunction
