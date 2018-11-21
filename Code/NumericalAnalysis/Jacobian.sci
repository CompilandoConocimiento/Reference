// /**
//  * Function to aproximate a Jacobian of f(\vec x) at a point
//  *
//  * @param f - a function :v
//  * @param point - a point to calculate the Jacobian
//  *
//  * @author: Rosas Hernandez Oscar Andres
//  * @author: Alarcón Alvarez Aylin Yadira Guadalupe
//  * @author: Laurrabaquio Rodríguez Miguel Salvador
//  * @author: Pahua Castro Jesús Miguel Ángel
//  */
function [jacobian] = Jacobian(f, point)
    [n, _] = size(point)
    [m, _] = size(f(point))

    jacobian = eye(m, n)
    fPoint = f(point)
    dx = 10^-7

    for fun = (1 : m)
        for var = (1 : n)
            newPoint = point
            newPoint(var) = point(var) + dx
            jacobian(fun, var) = ( f(newPoint)(fun) - f(point)(fun) ) / dx 
        end
    end

endfunction