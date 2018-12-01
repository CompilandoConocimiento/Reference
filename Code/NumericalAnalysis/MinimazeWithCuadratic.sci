

function [a, b, c] = MinimazeWithCuadratic(a, b, c, f, MaxIterations, tolerance)
    iterations = 0;

    while (iterations < MaxIterations)
        disp("a = " + string(a))
        disp("b = " + string(b))
        disp("c = " + string(c))
        disp("")

        plot(a, f(a), ".b")
        plot(b, f(b), ".b")
        plot(c, f(c), ".b")

        x = linspace(a, c)
        [yParabola, minX, minY] = EstimateParabola(a, b, c, f, x)
        plot(x, yParabola, "-blue")
        plot(minX, minY, "*black")

        oldEstimation = b;

        if (a < minX && minX < b) 
            a = a
            b = minX
            c = b
        else
            a = b
            b = minX
            c = c
        end

        if (abs (oldEstimation - b) < tolerance) then break end

        iterations = iterations + 1;
    end
endfunction


function [points, minX, minY] = EstimateParabola(a, b, c, f, points)
    denom = (a - b)*(a - c)*(b - c)
    A = (c * (f(b) - f(a)) + b * (f(a) - f(c)) + a * (f(c) - f(b))) / denom
    B = (c^2 * (f(a) - f(b)) + b^2 * (f(c) - f(a)) + a^2 * (f(b) - f(c))) / denom
    C = (b * c * (b - c) * f(a) + c * a * (c - a) * f(b) + a * b * (a - b) * f(c)) / denom

    points = A*(points)^2 + B*(points) + C
    minX = -B / (2*A)
    minY = C - B*B / (4*A)
endfunction