// Function to aproximate a function using the Lagrange method
// @param: points a vector of points
// @param: valuations a vector such valuations(i) = f(points(i))
// @param: pointsToEvaluate a vector of points to evaluate
// @return: pointsEvaluated such pointsEvaluated(i) = f(pointsToEvaluate(i))

// @Author: Rosas Hernandez Oscar Andres
// @Author: Alarcón Alvarez Aylin Yadira Guadalupe
// @Author: Pahua Castro Jesús Miguel Ángel

function [pointsEvaluated] = HermiteInterpolant(points, valuations, derivatives, pointsToEvaluate)
    n = length(points)

    numberOfEvaluations = length(pointsToEvaluate)
    pointsEvaluated = zeros(numberOfEvaluations, 1)

    HermiteEvaluations = zeros(numberOfEvaluations,  n)
    HermiteEvaluationsHat = zeros(numberOfEvaluations,  n)

    for evaluation = (1 : numberOfEvaluations)
        for i = (1 : n)
            HermiteEvaluationsHat(:, i) = HermiteHatPolynomial(points, i, pointsToEvaluate)
            HermiteEvaluations(:, i) = HermitePolynomial(points, i, pointsToEvaluate)
        end
    end

    for evaluation = (1 : numberOfEvaluations)
        temporal = 0
        for i = (1 : n)
            temporal = temporal + valuations(i)  * HermiteEvaluations(evaluation, i)
            temporal = temporal + derivatives(i) * HermiteEvaluationsHat(evaluation, i)
        end
        pointsEvaluated(evaluation) = temporal
    end
endfunction

function [pointsEvaluated] = HermitePolynomial(points, j, pointsToEvaluate)
    numberOfEvaluations = length(pointsToEvaluate)
    pointsEvaluated = zeros(numberOfEvaluations, 1)
    
    for evaluation = (1 : numberOfEvaluations)
        temporal = (LagrangePolynomial(points, j, points(j) + 0.0001) - LagrangePolynomial(points, j, points(j))) / (0.0001)
        pointsEvaluated(evaluation) = 1 - 2 * (pointsToEvaluate(evaluation) - points(j)) * temporal
        pointsEvaluated(evaluation) = pointsEvaluated(evaluation) * LagrangePolynomial(points, j, pointsToEvaluate(evaluation))^2
    end
endfunction

function [pointsEvaluated] = HermiteHatPolynomial(points, j, pointsToEvaluate)
    numberOfEvaluations = length(pointsToEvaluate)
    pointsEvaluated = zeros(numberOfEvaluations, 1)

    numberOfEvaluations = length(pointsToEvaluate)
    for evaluation = (1 : numberOfEvaluations)
        pointsEvaluated(evaluation) = (pointsToEvaluate(evaluation) - points(j)) * LagrangePolynomial(points, j, pointsToEvaluate(evaluation))^2
    end
endfunction

     