#include <iostream>                         
#include <vector>                           
#include <stdexcept>                        
#include <algorithm>                        
#include <functional>                        

#include "./MatrixClass.cpp"
#include "./LUDecomposition.cpp"
#include "./SolveTriangularSystem.cpp"
using namespace std;

int main(void) {

    Matrix<double> A({
        {1 ,  1,  1},
        {4 ,  3, -1},
        {4 ,  5 , 3},
    });

    Matrix<double> b({
        {1},
        {6},
        {4},
    });

    auto [L, U] = BasicLUDecomposition(A);
    cout << A << endl;
    
    cout << L << endl;
    cout << U << endl;
    cout << endl;

    cout << L * U << endl;
    cout << endl;

    auto y = SolveLowerTriangular(L, b);

    cout << "y" << y << endl;
    cout << L * y << endl;
    cout << b << endl;

    cout << endl;

    auto x = SolveUpperTriangular(U, y);
    cout << U * x << endl;
    cout << y << endl;

    cout << endl;

    cout << x << endl;

    cout << A * x << endl;

    return 0;
}


