#include <array>
#include <functional>

template <size_t MAX_SIZE, typename element = int, typename index = int,
          typename function = std::plus<int>,
          typename functionInverse = std::minus<int>>

class FenwickTree {
  using elements = std::array<element, MAX_SIZE>;
  static auto getNext(index i) -> index { return i | (i + 1); }

 private:
  elements bit;

 public:
  // build from array in O(n), indexed in 0
  FenwickTree(const elements& data) {
    for (index i {}; i < MAX_N; ++i) {
      bit[i] = data[i];
      const auto nextIndex {getNext(i)};
      if (nextIndex < MAX_N) bit[nextIndex] += bit[i];
    }
  }

  // single element increment
  auto update(index position, element value) -> void {
    while (position <= MAX_SIZE) {
      bit[position] += value;
      position = getNext(position);
    }
  }

  // range query, [0, end]
  auto query(int end) -> element const {
    T answer {};
    while (end >= 0) {
      answer += bit[end];
      end = (end & (end + 1)) - 1;
    }

    return answer;
  }

  // range query, [start, end]
  auto query(index start, index end) -> element const {
    return query(end) - query(start - 1);
  }
};

int main() {
	array<4, 3> {{}}
  auto f = FenwickTree<3> {{gy[]};

  return 0;
}