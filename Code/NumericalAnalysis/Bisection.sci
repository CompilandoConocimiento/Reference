// /**
//  * Function to aproximate a root of f(x) using the bisection method
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
function [estimation, iterations] = Bisection(a, b, f, tolerance, MaxIterations)
    iterations = 0;
    estimation = a + (b - a) / 2;

    while (iterations < MaxIterations)
        [a, b] = BisectionStep(a, b, f);

        if (RelativeDifference(a, b) < tolerance)
            estimation = a + (b - a) / 2;
            break;
        end

        if (abs(f(a)) < tolerance) 
            estimation = a;
            break;
        elseif (abs(f(b)) < tolerance) 
            estimation = b;
            break;
        end

        iterations = iterations + 1;
    end
endfunction

function [begin, finish] = BisectionStep(begin, finish, f)
    middle = begin + (finish - begin) / 2;

    if (SameSign(f(begin), f(middle)))
        begin = middle;
    else 
        finish = middle;
    end
endfunction
