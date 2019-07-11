
#include <iostream>
#include <unordered_map>
#include <vector>

template <typename container>
auto findSecond(const container& data) {
  using element = typename container::value_type;

  enum class found : char { one_time, more_than_1_time };
  auto state = std::unordered_map<element, found> {};

  for (const auto val : data) {
    auto situation = state.find(val);
    if (situation == end(state)) {
      state.insert({val, found::one_time});
    } else if (situation->second == found::one_time)
      situation->second = found::more_than_1_time;
  }

  for (const auto val : data) {
    auto situation = state.find(val);
    if (
      situation != end(state) and 
      situation->second == found::one_time) {
      return val;
    }
  }

  // Maybe throw or something
  return element {};
};

auto main() -> int {
  using namespace std;
  using number = int;

  vector<number> data1 {1, 4, 1, 0};
  cout << findSecond(data1) << endl;  // 1

  return 0;
}
