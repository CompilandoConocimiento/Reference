// /**
//  * Function to aproximate a root of f(x) using the Regular Falsi method
//  *
//  * @param a - a number 
//  * @param b - a number 
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
function [estimation, iterations] = RegulaFalsi(a, b, f, tolerance, MaximumIterations)
    iterations = 0;
    estimation = a + (b - a) / 2;

    while (iterations < MaximumIterations)
        c = SecantStep(a, b, f);
        if (SameSign(f(c), f(a)))
            a = c;
        else 
            b = c;
        end

        if (abs(f(a)) < tolerance) 
            estimation = a;
            break;
        elseif (abs(f(b)) < tolerance) 
            estimation = b;
            break;
        elseif (RelativeDifference(a, b) < tolerance) 
            estimation = a + (b - a) / 2;
            break;
        end

        iterations = iterations + 1;
    end

endfunction
