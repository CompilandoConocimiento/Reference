//  /**
//  * Function to aproximate a root of f(x) using the fixed point method , so f(x) can be written as 
//  * f(x) = g(x) - x = 0
//  *
//  * @param a - a number such f(a)f(b) < 0
//  * @param b - a number such f(a)f(b) < 0
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

function [estimation] = FixedPoint(initialPoint, f, tolerance, MaximumIterations)
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
