getd('/Users/mac/Documents/Projects/Reference/Code/NumericalAnalysis')

clc;

A24 = [
    1 0 0 0 1;
    -1 1 0 0 1;
    -1 -1 1 0 1;
    -1 -1 -1 1 1;
    -1 -1 -1 -1 1;
]


for i = (1 : 5)

    b24 = grand(5, 1, "uin", -20, 20);

    disp("Ax = b")

    disp("A:")
    disp(A24)

    disp("b:")
    disp(b24)

    disp("Solving...")

    [x24] = GaussianElimination(A24, b24);

    disp("x:")
    disp(x24)

    disp("Getting the solution: Ax")
    disp(A24 * x24)

    disp("Expected solution (b)")
    disp(b24)

    disp("Cheking the error (Ax - b)")
    disp(A24 * x24 - b24)

end

disp("Real condition of A")
disp(cond(A24))

disp("Estimated condition of A")
disp(Condition(A24, 50))