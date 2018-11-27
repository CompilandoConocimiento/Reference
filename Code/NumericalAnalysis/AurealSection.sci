// /**
//  * Function to aproximate a minimum of f(x)
//  *
//  * @param a - a number such f is unimodal in [a, b] 
//  * @param b - a number such f is unimodal in [a, b] 
//  * @param f - a function :v
//  * @param tolerance - a number to set how exact you want a minimum radio
//  * @param MaxIterations - a number of maximum iterations
//  * @return a - a number such that the minimum is in [a, b]
//  * @return b - a number such that the minimum is in [a, b]
//  *
//  * @author: Rosas Hernandez Oscar Andres
//  * @author: Alarcón Alvarez Aylin Yadira Guadalupe
//  * @author: Laurrabaquio Rodríguez Miguel Salvador
//  * @author: Pahua Castro Jesús Miguel Ángel
//  */
function [a, b] = AurealSection(a, b, f, tolerance, MaxIterations)
    iterations = 0;
    tau = 0.61803398874989484
    x1 = a + (1 - tau) * (b - a)
    x2 = a + (tau) * (b - a)

    while (iterations < MaxIterations)

        disp("\item $a = " + string(a)+ "$")
        disp("\item $b = " + string(b)+ "$")
        disp("\item $x_1 = " + string(x1)+ "$")
        disp("\item $x_2 = " + string(x2)+ "$")
        disp("")
        
        if (f(x1) < f(x2))
            disp("Como $f(" + string(x1) + ") < f(" + string(x2) + ")$")
            disp("\item $b = " + string(x2) + "$")
            disp("\item $x_2 = " + string(x1) + "$")
            disp("\item $x_1 = " + string(a) + "+ (1 -tau) * (" + string(b) + " - " + string(a) + ")$")
            b = x2
            x2 = x1
            x1 = a + (1 - tau) * (b - a)
        else 
            disp("Como f(" + string(x1) + ") > f(" + string(x2) + ")$")
            disp("\item $a = " + string(x1) + "$")
            disp("\item $x_1 = " + string(x2) + "$")
            disp("\item $x_2 = " + string(a) + "+ (tau) * (" + string(b) + " - " + string(a) + ")$")
            a = x1
            x1 = x2
            x2 = a + (tau) * (b - a)
        end

        if (b - a < tolerance) break;
        end;

        iterations = iterations + 1;
    end
endfunction
