#include <iostream>

template <typename natural>
auto modular_inverse(natural a, natural mod) -> natural {
  natural prev_m = 0, prev_prev_m = 1, b = mod;

  while (b != 0) {
    auto q = a / b, r = a % b;
    auto m = prev_prev_m - prev_m * q;

    a = b;
    b = r;

    prev_prev_m = prev_m;
    prev_m = m;
  }

  if (a < 0) return -prev_prev_m;
  if (prev_prev_m < 0) return mod + prev_prev_m;

  return prev_prev_m;
}

auto main() -> int {
  auto a = 2, mod = 17;
  auto a_inverse = modular_inverse(a, mod);
  std::cout << "a: " << a << "\t a^-1: " << a_inverse << std::endl;

  return 0;
}
