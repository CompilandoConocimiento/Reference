
function [a, b, c] = MinimazeWithCuadratic(a, b, c, f, MaxIterations, tolerance)
    iterations = 0;

    while (iterations < MaxIterations)
        [minX, minY, _] = EstimateParabola(a, b, c, f, 0)
        oldEstimation = b;

        if (a < minX && minX < b) 
            c = b
            b = minX
            a = a
        else
            a = b
            b = minX
            c = c
        end

        if (abs (oldEstimation - b) < tolerance) then break end

        iterations = iterations + 1;
    end
endfunction


function [minX, minY, pointsOut] = EstimateParabola(a, b, c, f, pointsIn)
    denom = (a - b) * (a - c) * (b - c)
    A = (c * (f(b) - f(a)) + b * (f(a) - f(c)) + a * (f(c) - f(b))) / denom
    B = (c^2 * (f(a) - f(b)) + b^2 * (f(c) - f(a)) + a^2 * (f(b) - f(c))) / denom
    C = (b * c * (b - c) * f(a) + c * a * (c - a) * f(b) + a * b * (a - b) * f(c)) / denom

    pointsOut = A * (pointsIn)^2 + B * (pointsIn) + C
    minX = -B / (2 * A)
    minY = C - B * B / (4 * A)
endfunction