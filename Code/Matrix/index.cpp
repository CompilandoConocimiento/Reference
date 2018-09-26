#include <iostream>                         
#include <vector>                           
#include <stdexcept>                        
#include <algorithm>                        
#include <functional>                        

#include "./MatrixClass.cpp"
using namespace std;

int main(void) {
    Matrix<double> m1 {3, 3, [] (size_t i, size_t j){return i * j;}};
    cout << m1 << endl;
    Matrix<double> m2 {3, 4, [] (size_t i, size_t j){return 2 + i * j;}};
    cout << m2 << endl;

    cout << m1 * m2 << endl;

    return 0;
}


