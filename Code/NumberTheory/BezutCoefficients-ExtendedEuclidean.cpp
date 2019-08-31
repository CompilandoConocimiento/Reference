#include <iostream>
#include <utility>
#include <vector>
using namespace std;

template <typename T>
using couple = std::pair<T, T>;

template <typename number>
// a = b(q) + (r) return {q, r}
auto divisionAlgorithm(const number a, const number b) -> couple<number> {
  if (b == 0) return {0, a};

  auto q = number {}, r = number {};
  q = a / b;
  r = a % b;

  if (r < 0) {
    q = q + (q >= 0 ? 1 : -1);
    r = a - (b * q);
  }

  return {q, r};
}

// gcd(a, b) = ma + nb return {m, n}
template <typename number>
auto extendedEuclideanAlgorithm(const number _a, const number _b) {
  auto a = _a, b = _b;
  number prev_m = 0, prev_n = 1, prev_prev_m = 1, prev_prev_n = 0;

  auto data = std::vector<std::vector<int>> {};

  if (b == 0) {
    auto [q, r] = divisionAlgorithm(a, b);
    data.push_back({a, b, q, r, 1, 0});
  }

  while (b != 0) {
    auto [q, r] = divisionAlgorithm(a, b);

    // All the magic is here
    auto m = prev_prev_m - prev_m * q;
    auto n = prev_prev_n - prev_n * q;

    data.push_back({a, b, q, r, m, n});

    // Given a = bq + r -> gcd(a, b) = gcd(b, r); Lets find gcd(b, r)
    a = b;
    b = r;

    prev_prev_m = prev_m, prev_prev_n = prev_n;
    prev_m = m, prev_n = n;
  }

  cout << "GCD:" << endl;
  for (auto x : data) {
    cout << " "
         << "('a:" << x[0] << ") = ('b:" << x[1] << ")"
         << "(q:" << x[2] << ") + (r:" << x[3] << ")" << endl;
  }

  cout << endl << "Bezut coefficients:" << endl;

  cout << " "
       << "(a:" << _a << ") = "
       << "(a:" << _a << ")(m:1) + "
       << "(b:" << _b << ")(n:0)\n";

  cout << " "
       << "(b:" << _b << ") = "
       << "(a:" << _a << ")(m:0) + "
       << "(b:" << _b << ")(n:1)" << endl
       << endl;

  for (auto x : data) {
    // (r) = (a) - (b)(q)
    cout << " "
         << "(r:" << x[3] << ") = "
         << "('a:" << x[0] << ") - ";
    cout << "('b:" << x[1] << ")"
         << "(q:" << x[2] << ") = ";

    cout << "(a:" << _a << ")(m:" << x[4] << ") + ";
    cout << "(b:" << _b << ")(n:" << x[5] << ")" << endl;
  }

  // Results
  cout << endl << "gcd(" << _a << ", " << _b << ") = " << abs(a) << endl;
  cout << "bezut(" << _a << ", " << _b << ") = "
       << "(" << prev_prev_m << ", " << prev_prev_n << ")" << endl;

  cout << "bezut indentity: (gcd:" << abs(a) << ") = ";
  cout << "(a:" << _a << ")(m:" << prev_prev_m << ") + ";
  cout << "(b:" << _b << ")(n:" << prev_prev_n << ")" << endl;

  return data;
}

template <typename number>
auto bezutCoefficients(number a, number b) -> couple<number> {
  number prev_m = 0, prev_n = 1, prev_prev_m = 1, prev_prev_n = 0;

  while (b != 0) {
    auto [q, r] = divisionAlgorithm(a, b);

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
  divisionAlgorithm(-1, -3);
  extendedEuclideanAlgorithm(239, 69);

  auto [m, n] = bezutCoefficients(239, 69);
  cout << "m = " << m << " n = " << n << endl;

  return 0;
}
