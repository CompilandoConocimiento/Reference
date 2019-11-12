template <typename integer>
auto binaryExponentation(const integer x, const integer n) -> integer {
  if (n == 0) return 1;
  if (n == 1) return x;

  if (n % 2 == 0) return binaryExponentation(x * x, n / 2);
  return x * binaryExponentation(x * x, (n - 1) / 2);
}

template <typename integer>
auto binaryExponentation(integer base, integer exponent) -> integer {
  auto solution = integer {1};

  while (exponent > 0) {
    if (exponent % 2 == 1) solution *= base;

    base = base * base;
    exponent = exponent / 2;
  }

  return solution;
}

template <typename integer>
auto binaryExponentation(integer base, integer exponent) -> integer {
  auto solution = integer {1};

  while (exponent > 0) {
    if (exponent & 1) solution *= base;

    base = base * base;
    exponent = exponent >> 1;
  }

  return solution;
}

template <typename integer>
auto modularBinaryExponentation(integer base, integer exponent, integer n)
    -> integer {
  auto solution = integer {1};
  base = base % n;

  while (exponent > 0) {
    if (exponent & 1) solution = (base * solution) % n;

    base = (base * base) % n;
    exponent = exponent >> 1;
  }

  return solution;
}