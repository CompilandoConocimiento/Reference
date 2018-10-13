getd('/Users/mac/Documents/Projects/Reference/Code/NumericalAnalysis')

clc;

A22 = [2, 4, -2; 4, 9, -3; -2, -1, 7];
c22 = [4; 8; -6];

disp("Ax = c")

disp("A:")
disp(A22)

disp("c:")
disp(c22)

disp("Solving...")

[L22, U22] = LUDecomposition(A22);

disp("L:");
disp(L22)

disp("U:");
disp(U22)

disp("Solving Ly = c")
y22 = FowardSubstitution(L22, c22);

disp("y:")
disp(y22)

disp("Solving Ux = y")
x22 = BackwardSubstitution(U22, y22);

disp("x:")
disp(x22)

disp("Getting the solution: Ax")
disp(A22 * x22)

disp("Expected solution (c)")
disp(c22)

disp("Cheking the error (Ax - c)")
disp(A22 * x22 - c22)
