#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v {1, 2, 3, 4, 12, 121212, 23, 2, -3};
    std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });
    for_each(v.begin(), v.end(), [](int a) { cout << a << endl; });
    return 0;
}