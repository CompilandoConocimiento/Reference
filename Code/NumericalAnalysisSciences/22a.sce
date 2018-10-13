getd('/Users/mac/Documents/Projects/Reference/Code/NumericalAnalysis')

clc;

A22 = [2, 4, -2; 4, 9, -3; -2, -1, 7];
b22 = [2; 8; 10];

disp("Ax = b")

disp("A:")
disp(A22)

disp("b:")
disp(b22)

disp("Solving...")

[x22] = GaussianElimination(A22, b22);

disp("x:")
disp(x22)

disp("Getting the solution: Ax")
disp(A22 * x22)

disp("Expected solution (b)")
disp(b22)

disp("Cheking the error (Ax - b)")
disp(A22 * x22 - b22)
