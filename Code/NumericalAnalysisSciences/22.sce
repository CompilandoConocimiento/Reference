getd('/Users/mac/Documents/Projects/Reference/Code/Matrix')

clc;

A22 = [2, 4, -2; 4, 9, -3; -2, -1, 7];
b22 = [2; 8; 10];
c22 = [4; 8; -6];

disp("Solving A")
[L22, U22] = LUDecomposition(A22);
disp(A22)

disp("L");
disp(L22)

disp("U");
disp(U22)

disp("Solving Ly = c")
y22 = FowardSubstitution(L22, c22);
disp(y22)

disp("Solving Ux = y")
x22 = BackwardSubstitution(U22, y22);
disp(x22)

disp("Getting the solution")
disp(A22 * x22)

disp("Expected solution")
disp(c22)

disp("Cheking the error")
disp(A22 * x22 - c22)
