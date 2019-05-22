#include <iostream>
#include <vector>
using namespace std;

auto print = [](const int& x) { cout << x << endl; };
int main() {
    vector <int > numbers {1 , 2 , 3 , 4};
    for ( int & number : numbers ) {
        number *= 3;
    }
    for_each(numbers.begin(), numbers.end(), print);
    return 0;
}