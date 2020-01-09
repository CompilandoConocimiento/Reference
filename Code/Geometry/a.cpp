#include <iostream>
#include "Decimal.cpp"
#include "Point.cpp"

using namespace std;

using ld = long double;

enum class result {
  no_points = 0,
  one_points = 1,
  infinity_points = -1,
};

auto main() -> int {
  auto x = point<ld> {3, 0};
  auto y = point<ld> {4, 0};

  cout << (x < y) << endl;
}