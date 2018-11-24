function [z, h] = Spline3(t, y)
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

    z(n) = 0;
    for i = (n - 1 : -1 : 2)
        z(i) = (v(i) - h(i) * z(i+1)) / u(i);
    end
    z(1) = 0;
endfunction   

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

function [estimation] = EvaluateSpline3(x, y, z, h, point)
    i = FindPoint(point, x);

    sum1 = z(i + 1) / (6 * h(i)) * (point - x(i))^3;
    sum2 = z(i) / (6 * h(i)) * (x(i+1) - point)^3;
    sum3 = ( y(i+1)/h(i) - z(i+1)/6 * h(i) ) * (point - x(i));
    sum4 = ( y(i)/h(i) - z(i)/6 * h(i) ) * (x(i+1) - point);

    estimation = sum1 + sum2 + sum3 + sum4;

endfunction

function [estimations] = EvaluateSpline3Points(x, y, z, h, points)
    dimension = length(points);
    estimations = zeros(dimension, 1);

    for i = (1 : dimension)
        estimations(i) = EvaluateSpline3(x, y, z, h, points(i));
    end

endfunction