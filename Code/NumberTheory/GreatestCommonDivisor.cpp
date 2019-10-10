#include <iostream>
#include <cmath>
#include <numeric>

template <typename number>
// Note a, b could be negatie
auto gcd(number a, number b) -> number {
  while (b != 0) {
    auto reminder = a % b;
    a = b;
    b = reminder;
  }

  return std::abs(a);
}

auto main() -> int {
  auto a = 48, b = 20;
  auto result = gcd(a, b);
  std::cout << "gcd(" << a << ", " << b << ") = " << result << std::endl;

  return 0;
}
