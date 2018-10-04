#include <iostream>                         
#include <vector>                           
#include <stdexcept>                        
#include <algorithm>                        
#include <functional>                        

#include "./MatrixClass.cpp"
#include "./Algorithms.cpp"
using namespace std;

int main(void) {

    Matrix<double> U({
        {4 , -1, 2, 3 },
        {0 , -2, 7, -4},
        {0 ,  0 , 6, 5},
        {0 ,  0 , 0, 3},
    });

    Matrix<double> b({
        {20},
        {-7},
        {4},
        {6}
    });

    auto x = SolveUpperTriangular(U, b);

    cout << U << endl;
    cout << b << endl;
    cout << U * x << endl;
    cout << x << endl;

    return 0;
}


