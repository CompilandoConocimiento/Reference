// Function to aproximate a root of f(x) using the secant method
// @param: x_0 a initial guess to the root
// @param: x_1 a initial guess to the root
// @param: someFunction a string that represent the expression to get x 
// @param: tolerance a number to set how exact you want a root
// @param: MaximumIterations a number of maximum iterations
// @return: estimation a number such someFunction(estimation) = 0

// @Author: Rosas Hernandez Oscar Andres
// @Author: Alarcón Alvarez Aylin Yadira Guadalupe
// @Author: Laurrabaquio Rodríguez Miguel Salvador
// @Author: Pahua Castro Jesús Miguel Ángel

function [estimation] = Secant(x0, x1, someFunction, tolerance, MaximumIterations)
    deff('y = f(x)', ['y = evstr(someFunction)']);
    iterations = 0;
    oldEstimation = x0;
    estimation = x1;
    
    while ((abs(f(estimation)) > tolerance) && (iterations < MaximumIterations))
        fk = f(estimation);
        fk1 = (f(estimation) - f(oldEstimation)) / (estimation - oldEstimation)
        
        oldEstimation = estimation;
        estimation = estimation - (fk / fk1);

        if (RelativeDifference(oldEstimation, estimation) < tolerance) 
            break 
        end

        iterations = iterations + 1;
    end
endfunction

function [evaluation] = EvaluateDerivate(f, point)
    dx = 10^-8;
    evaluation = (f(point + dx) - f(point)) / dx; 
endfunction