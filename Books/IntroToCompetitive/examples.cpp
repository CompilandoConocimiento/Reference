#include <iomanip>
#include <iostream>
#include <vector>

template <typename T>
using matrix = std::vector<std::vector<T>>;

int main() {
  auto m = matrix<int> {};  // m is an vector of vector of int
}