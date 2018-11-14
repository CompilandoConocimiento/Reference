// Function to aproximate a root of f(x) using the bisection method
// @param: a a number such f(a)f(b) < 0
// @param: b a number such f(a)f(b) < 0
// @param: someFunction a string that represent the expression to get x 
// @param: tolerance a number to set how exact you want a root
// @param: MaximumIterations a number of maximum iterations
// @return: estimation a number such someFunction(estimation) = 0

// @Author: Rosas Hernandez Oscar Andres
// @Author: Alarcón Alvarez Aylin Yadira Guadalupe
// @Author: Laurrabaquio Rodríguez Miguel Salvador
// @Author: Pahua Castro Jesús Miguel Ángel

function [estimation] = Bisection(a, b, someFunction, tolerance, MaximumIterations)
    deff('y = f(x)', ['y = evstr(someFunction)']);
    iterations = 0;
    estimation = a + (b - a) / 2;
    
    while ((abs(f(estimation)) > tolerance) && (iterations < MaximumIterations))
        oldEstimation = estimation
        estimation = a + (b - a) / 2;

        if (SameSign(f(a), f(estimation)))
            a = estimation;
        else 
            b = estimation;
        end

        if (iterations > 1 && RelativeDifference(oldEstimation, estimation) < tolerance) 
            break 
        end

        iterations = iterations + 1;
    end
endfunction













//Parámetros de salida:
//m=Aproximación a f(m)=0.
//iter=Número de iteraciones realizadas.

//Función que crea la ecuación de la recta mediante 
//la fórmula de punto pendiente
//Parámetros de entrada:
//x:Puntos a evaluar en la recta 
//(x1,y1),(x2,y1): Puntos para crear la ecuación de la recta.
function[y]=lineas(x,x1,x2,y1,y2)
    n=length(x);//Obtenemos el número de puntos a evaluar 
    y=zeros(n,1);
    //Obtenemos los puntos evaluados en la recta 
    for i=(1:n)
        y(i)=((y2-y1)/(x2-x1))*(x(i)-x1)+y1;
    end
endfunction
//Parámatros de salida 
//y: Puntos evaluados en la recta.

