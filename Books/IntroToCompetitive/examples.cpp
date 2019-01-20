#include <iostream>
#include <vector>

using namespace std;

int main() {

    std::vector<int> someIntegers {1, 2, 3, 4, 20, 5};
    std::size_t numberOfElements = {someIntegers.size()};

    cout << numberOfElements << endl;

    return 0;
}