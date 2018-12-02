
function [pointsEvaluated] = NewtonInterpolant(points, valuations, pointsToEvaluate)
    n = length(points)

    pointsEvaluated = zeros(numberOfEvaluations, 1)
    Differences = NewtonInterpolantCoefficients(points, valuations)

    disp(Differences)
    disp(n)
    disp(numberOfEvaluations)

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
    for evaluation = (1 : numberOfEvaluations)

        temporal = Differences(1)
        for i = (2 : n)
            temporal2 = Differences(i)
            for j = (1 : i - 1)
                temporal2 * (pointsToEvaluate(evaluation) - points(j))
            end
            temporal = temporal + temporal2
        end

        disp(temporal)
        
        //temporal = Differences(n)
        //for j = (n - 1 : -1 : 2)
        //    temporal = temporal * ( pointsToEvaluate(i) - points(j) ) + Differences(j-1)
        //end
        pointsEvaluated(evaluation) = temporal
    end
endfunction





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
