#include <iostream>
#include <vector>

using namespace std;

template <typename number = int>
auto stupidFibonacci(number n) -> number {
  if (n == 0) return 0;
  if (n == 1) return 1;
  else return stupidFibonacci(n - 1) + stupidFibonacci(n - 2);
}

template <typename number = int, typename index = unsigned int>
struct topBottomFibonacci {
  std::vector<number> memorized;

  topBottomFibonacci(index maxValue = 100, number baseCase = -1)
      : memorized(maxValue, baseCase) {}

  auto getN(number n) -> number {
    if (n == 0) return 0;
    if (n == 1) return 1;
    else return getN(n - 1) + getN(n - 2);
  }
};

template <typename number = int, typename index = unsigned int>
struct bottomUpFibonacci {
  std::vector<number> memorized;

  bottomUpFibonacci(index maxValue = 100, number baseCase = -1)
      : memorized(maxValue, baseCase) {}

  auto getN(number n) -> number {
    memorized[0] = 0;
    memorized[1] = 1;

    for (index i {2}; i <= n; i++)
      memorized[i] = memorized[i - 1] + memorized[i - 2];

    return memorized[n];
  }
};

auto main() -> int {
  auto n = int {45};
  cout << topBottomFibonacci<> {}.getN(n) << endl;
  cout << bottomUpFibonacci<> {}.getN(n) << endl;
  cout << stupidFibonacci(n) << endl;

  return 0;
}