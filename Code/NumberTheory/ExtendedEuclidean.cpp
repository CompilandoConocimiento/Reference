#include <iostream>
#include <utility>
#include <vector>
using namespace std;

template <typename T>
using couple = std::pair<T, T>;

// natural means a, b > 0
template <typename natural>
auto extended_euclidean(natural a, natural b) -> couple<natural> {
  natural prev_m = 0, prev_n = 1, prev_prev_m = 1, prev_prev_n = 0;

  while (b != 0) {
    auto q = a / b, r = a % b;
    auto m = prev_prev_m - prev_m * q;
    auto n = prev_prev_n - prev_n * q;

    a = b;
    b = r;

    prev_prev_m = prev_m, prev_prev_n = prev_n;
    prev_m = m, prev_n = n;
  }

  return {prev_prev_m, prev_prev_n};
}

auto main() -> int {
  auto a = 48, b = 25;
  auto [m, n] = extended_euclidean(a, b);
  std::cout << "e_gcd(" << a << ", " << b << "): "
            << "m=" << m << " n=" << n << endl;

  return 0;
}
