// Function to aproximate a function using the Lagrange method
// @param: points a vector of points
// @param: valuations a vector such valuations(i) = f(points(i))
// @param: pointsToEvaluate a vector of points to evaluate
// @return: pointsEvaluated such pointsEvaluated(i) = f(pointsToEvaluate(i))

// @Author: Rosas Hernandez Oscar Andres
// @Author: Alarcón Alvarez Aylin Yadira Guadalupe
// @Author: Pahua Castro Jesús Miguel Ángel

function [pointsEvaluated] = LagrangeInterpolant(points, valuations, pointsToEvaluate)
    n = length(points)

    numberOfEvaluations = length(pointsToEvaluate)
    pointsEvaluated = zeros(numberOfEvaluations, 1)

    LangrangeEvaluations = zeros(numberOfEvaluations,  n)

    for evaluation = (1 : numberOfEvaluations)
        for i = (1 : n)
            LangrangeEvaluations(:, i) = LagrangePolynomial(points, i, pointsToEvaluate)
        end
    end

    for evaluation = (1 : numberOfEvaluations)
        temporal = 0
        for i = (1 : n)
            temporal = temporal + valuations(i) * LangrangeEvaluations(evaluation, i)
        end
        pointsEvaluated(evaluation) = temporal
    end
endfunction

function [pointsEvaluated] = LagrangePolynomial(points, k, pointsToEvaluate)
    n = length(points)

    numberOfEvaluations = length(pointsToEvaluate)
    for evaluation = (1 : numberOfEvaluations)
        temporal = 1
        for i = (1 : n)
            if (i ~= k) 
                temporal = temporal * (pointsToEvaluate(evaluation) - points(i)) / (points(k) - points(i)) 
            end
        end
        pointsEvaluated(evaluation) = temporal
    end

endfunction

    