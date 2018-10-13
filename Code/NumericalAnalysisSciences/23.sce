getd('/Users/mac/Documents/Projects/Reference/Code/NumericalAnalysis')

clc;

data23 = [
    -1, 1;
    -0.0034, 0.3434;
    10, 230230;
    -1212, 32032032,
];

for i = (1 : 4)
    A23 = grand(8, 8, "unf", data23(i, 1), data23(i, 2));

    disp("Random Matrix");
    disp(A23);

    disp("Real condition");
    disp(cond(A23));

    disp("Estimated condition");
    disp(Condition(A23, 50));
end