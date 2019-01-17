#include <iostream>
#include <limits>

using namespace std;

int main() {

    std::cout << "int\t"
              << std::numeric_limits<int>::lowest() << '\t'
              << std::numeric_limits<int>::min() << '\t'
              << std::numeric_limits<int>::max() << '\n';

    std::cout << "int\t"
              << std::numeric_limits<size_t>::lowest() << '\t'
              << std::numeric_limits<size_t>::min() << '\t'
              << std::numeric_limits<size_t>::max() << '\n';

    std::cout << "int\t"
              << std::numeric_limits<long long>::lowest() << '\t'
              << std::numeric_limits<long long>::min() << '\t'
              << std::numeric_limits<long long>::max() << '\n';

    cout << 18446744073709551615 - 9223372036854775807 << endl;

    return 0;
}