#include <iostream>
#include <vector>
#include <valarray>

using namespace std;

int main() {
    vector<const int> numbers {1, 2, 3};
    for (int i {}; i < numbers.size(); ++i) {              // num is const int
        cout << numbers[i] << endl;
    }
}

