#include <array>
#include <iostream>
#include <vector>

template <typename container>
auto findSecond(const container& data) {
  // We need 2 elements to find the second min :c
  assert(data.size() > 1);

  auto minimum = data[0], almostMin = data[1];
  for (const auto current : data) {
    // If we have found a new min move everything
    if (current < minimum) {
      almostMin = minimum;
      minimum = current;
      // Ok, not new min, but maybe we found a new 2 min
    } else if (current < almostMin)
      almostMin = current;
  }
  return almostMin;
};

auto main() -> int {
  using namespace std;
  using number = const int;

  vector<number> data1 {1, 4, 1};
  cout << findSecond(data1) << endl;  // 1

  array<number, 5> data2 {1, 4, -1, 3, -5};
  cout << findSecond(data2) << endl;  // -1

  return 0;
}
