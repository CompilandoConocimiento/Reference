// Function to aproximate a function using the Newton method
// @param: points a vector of points
// @param: valuations a vector such valuations(i) = f(points(i))
// @param: pointsToEvaluate a vector of points to evaluate
// @return: pointsEvaluated such pointsEvaluated(i) = f(pointsToEvaluate(i))

// @Author: Rosas Hernandez Oscar Andres
// @Author: Alarcón Alvarez Aylin Yadira Guadalupe
// @Author: Pahua Castro Jesús Miguel Ángel

function [pointsEvaluated] = NewtonInterpolant(points, valuations, pointsToEvaluate)
    n = length(points)
    Differences = NewtonInterpolantCoefficients(points, valuations)

    data = "I(x) = " + string(Differences(1))
    for i = (2 : n)
        data = data + " + " + string(Differences(i))
        for j = (1 : i - 1)
            if (points(j) > 0)
                data = data + "(x - " + string(points(j)) + ")"
            else
                data = data + "(x + " + string(-1 * points(j)) + ")"
            end
        end
    end

    disp(data)

    numberOfEvaluations = length(pointsToEvaluate)
    pointsEvaluated = zeros(numberOfEvaluations, 1)

    for evaluation = (1 : numberOfEvaluations)
        temporal = Differences(n)
        for j = (n - 1 : -1 : 1)
            temporal = temporal * ( pointsToEvaluate(evaluation) - points(j) ) + Differences(j)
        end
        pointsEvaluated(evaluation) = temporal
    end
endfunction

// Function to aproximate a function using the Newton method but the points should be 
// from a homogenues partition
// @param: points a vector of points
// @param: valuations a vector such valuations(i) = f(points(i))
// @param: pointsToEvaluate a vector of points to evaluate
// @return: pointsEvaluated such pointsEvaluated(i) = f(pointsToEvaluate(i))

function [pointsEvaluated] = NewtonHomogeneousInterpolant(points, valuations, pointsToEvaluate)
    n = length(points)
    Differences = NewtonInterpolantCoefficients(points, valuations)

    numberOfEvaluations = length(pointsToEvaluate)
    pointsEvaluated = zeros(numberOfEvaluations, 1)
    h = points(2) - points(1)

    for evaluation = (1 : numberOfEvaluations)
        s = ( pointsToEvaluate(evaluation) - points(1) ) / h

        temporal = Differences(1)
        for k = (2 : n)
            temporal2 = Differences(k) * h^(k-1)
            for term = (0 : k - 2)
                temporal2 = temporal2 * (s - term) 
            end
            temporal = temporal + temporal2
        end
        pointsEvaluated(evaluation) = temporal
    end
endfunction


// Function get all the Divided Differences for the Newton interpolant
// @param: points a vector of points
// @param: valuations a vector such valuations(i) = f(points(i))
// @return: Differences such Differences(i) = f[x_0 ... x_i]

function [Differences] = NewtonInterpolantCoefficients(points, valuations)
    n = length(points)

    for i = (1 : n)
        Differences(i) = valuations(i)
    end

    for order = (1 : n - 1)
        for i = (n : -1 : order + 1)
            numerator = Differences(i) - Differences(i-1)
            denominator = points(i) - points(i-order)
            Differences(i) = numerator / denominator
        end
    end

endfunction
