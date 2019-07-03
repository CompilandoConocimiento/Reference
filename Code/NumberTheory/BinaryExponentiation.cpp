template <typename integer, typename unsignedInteger>
auto binaryExponentation(integer x, unsignedInteger n) -> integer {
  if (n == 0) return 1;
  if (n == 1) return x;

  if (n % 2 == 0) return binaryExponentation(x * x, n / 2);
  return x * binaryExponentation(x * x, (n - 1) / 2);
}

template <typename integer, typename unsignedInteger>
auto binaryExponentation(integer base, unsignedInteger exponent) -> integer {
  auto solution = integer {1};

  while (exponent > 0) {
    if (exponent & 1) {
      solution = base * solution;
      base = base * base;
    } else {
      base = base * base;
    }

    exponent = exponent / 2;
  }

  return solution;
}

template <typename integer, typename unsignedInteger>
auto binaryExponentation(integer base, unsignedInteger exponent) -> integer {
  auto solution = integer {1};

  while (exponent > 0) {
    if (exponent & 1) solution = base * solution;

    base = base * base;
    exponent = exponent >> 1;
  }

  return solution;
}

template <typename integer, typename uinteger>
auto modularBinaryExponentation(integer base, uinteger exponent, uinteger n)
    -> integer {
  integer solution {1};
  base = base % n;

  while (exponent > 0) {
    if (exponent & 1) solution = (base * solution) % n;

    base = (base * base) % n;
    exponent = exponent >> 1;
  }

  return solution;
}