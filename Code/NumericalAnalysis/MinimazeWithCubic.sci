
function [a, b, c, d] = MinimazeWithCubic(a, b, c, f, MaxIterations, tolerance)
    iterations = 0

    while (iterations < MaxIterations)
        [min, _] = EstimateCubic(a, b, c, d, f, 0)
        oldEstimation = abs(b - c);

        if (a < min && min < b) 
            d = c
            c = b
            b = min
            a = a
        elseif (b < min && min < c) 
            b = min
        else
            a = b
            b = c
            c = min
            d = d
        end

        if (abs(abs(b-c) - oldEstimation) < tolerance) then break end
        iterations = iterations + 1;
    end
endfunction


function [min, points] = EstimateCubic(a, b, c, d, f, points)

    A = [
        a^3 a^2 a^1 1;
        b^3 b^2 b^1 1;
        c^3 c^2 c^1 1;
        d^3 d^2 d^1 1;
    ]

    solutions = [
        f(a);
        f(b);
        f(c);
        f(d);
    ]

    [x] = LeastSquares(A, solutions);

    A = x(1)
    B = x(2)
    C = x(3)
    D = x(4)

    disp(x)

    points = A * (points)^3 + B * (points)^2 + C * points + D

    pointOfInflection1 = (-2*B + sqrt(4*B^2 - 12*A*C))/(6*A)
    pointOfInflection2 = (-2*B - sqrt(4*B^2 - 12*A*C))/(6*A)

    if (pointOfInflection1 < a || pointOfInflection1 > d) min = pointOfInflection2
    else min = pointOfInflection1 end

endfunction