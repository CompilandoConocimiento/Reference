// Function to aproximate a function using the Spline (cubic) method
// @param: x a vector of points
// @param: y a vector such valuations(i) = f(x(i))
// @param: pointsToEvaluate a vector of points to evaluate
// @param: type if 0 then Spline natural if [a, b] then spline complete where
//          f(x_0)' = -a and f(x_n)' = -b  
// @return: pointsEvaluated such pointsEvaluated(i) = f(pointsToEvaluate(i))

// @Author: Rosas Hernandez Oscar Andres
// @Author: Alarcón Alvarez Aylin Yadira Guadalupe
// @Author: Pahua Castro Jesús Miguel Ángel


function [pointsEvaluated] = Spline3Interpolant(x, y, pointsToEvaluate, type)
    [z, h] = Spline3Coefficients(x, y, type)

    numberOfEvaluations = length(pointsToEvaluate)
    pointsEvaluated = zeros(numberOfEvaluations, 1)

    for evaluation = (1 : numberOfEvaluations)
        point = pointsToEvaluate(evaluation)
        i = FindPoint(point, x)

        sum1 = z(i + 1) / (6 * h(i)) * (point - x(i))^3
        sum2 = z(i) / (6 * h(i)) * (x(i+1) - point)^3
        sum3 = ( y(i+1)/h(i) - z(i+1)/6 * h(i) ) * (point - x(i))
        sum4 = ( y(i)/h(i) - z(i)/6 * h(i) ) * (x(i+1) - point)

        pointsEvaluated(evaluation) = sum1 + sum2 + sum3 + sum4
    end

endfunction


// Function to get the Z and H for the Spline method :v
// @param: t a vector of points
// @param: y a vector such valuations(i) = f(t(i))
// @return: z a vector of ?? well, of number to the next algorithm step
// @return: h a vector of distances

function [z, h] = Spline3Coefficients(t, y, type)
    n = length(t);      

    h = zeros(n - 1, 1);
    b = zeros(n - 1, 1);
    u = zeros(n - 2, 1);
    v = zeros(n - 2, 1);
    z = zeros(n, 1);

    for i = (1 : n - 1)
        h(i) =  t(i+1) - t(i);
        b(i) = 6 * (y(i+1) - y(i)) / h(i);
    end

    u(2) = 2 * (h(1) + h(2));
    v(2) = b(2) - b(1);

    for i = (3 : n - 1)
        u(i) = 2 * (h(i) + h(i-1)) - h(i-1)**2 / u(i-1);
        v(i) = b(i) - b(i-1) - h(i-1) * v(i-1) / u(i-1);
    end 
    
    if (length(type) == 1) z(n) = 0; else z(n) = type(2); end
    
    for i = (n - 1 : -1 : 2)
        z(i) = (v(i) - h(i) * z(i+1)) / u(i);
    end

    if (length(type) == 1) z(1) = 0; else z(1) = type(1); end

endfunction   

// Function to find a interval in a distribution
// @param: point a point :v
// @param: data a vector of values
// @return: i a number such data(i) <= point <= data(i+1)

function [i] = FindPoint(point, data) 
    middle = 1, start = 1
    final = length(data)

    while (start < final)
        middle = start + floor((final - start) / 2)

        if (point < data(middle)) then final = middle;
        else start = middle + 1;
        end
    end

    i = start - 1;

endfunction

