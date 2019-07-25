
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

template <typename container, typename index = int>
auto firstUnique(const container& values) -> index {
  using element = typename container::value_type;
  auto seen = std::unordered_map<element, char> {};

  for (auto value : values) {
    auto& timesSeen = seen[value];
    if (timesSeen < 2) ++timesSeen;
  }

  index result {};
  for (auto value : values) {
    if (seen[value] == 1) return result;
    result++;
  }

  return -1;
}

auto main() -> int {
  auto values = std::vector<int> {1, 4, 1, 0};
  cout << firstUnique(values, false) << endl;  // 4
  return 0;
}
