#include <functional>
#include <vector>

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/**
 *
 * You have an array (starting with 0 or you can use buildFromArray),
 * you can use FenwickTree to get the sum of all elements in a range
 * also, you can increase a position by a value
 *
 */
template <typename element = int, typename index = int>
class FenwickTree {
 private:
  const int MAX_SIZE;
  std::vector<element> bit {};

  static auto getNext(index i) -> index { return i | (i + 1); }

 public:
  FenwickTree(int MAX_SIZE = 100000) : MAX_SIZE {MAX_SIZE}, bit(MAX_SIZE, 0) {}

  auto buildFromArray(const std::vector<element>& data) -> void {
    for (index i {}; i < MAX_SIZE; ++i) {
      bit[i] = bit[i] + data[i];
      const auto nextIndex {getNext(i)};
      if (nextIndex < MAX_SIZE) bit[nextIndex] = bit[i] + bit[nextIndex];
    }
  }

  // get the sum from [0, end]
  auto sum(int end) -> element const {
    element answer {};
    while (end >= 0) {
      answer = answer + bit[end];
      end = (end & (end + 1)) - 1;
    }
    return answer;
  }

  // get the sum from [start, end]
  auto sum(index start, index end) -> element const {
    return sum(end) - sum(start - 1);
  }

  // increase the position by a value
  auto increase(index position, element value) -> void {
    while (position < MAX_SIZE) {
      bit[position] = bit[position] + value;
      position = getNext(position);
    }
  }

  void showArray() {
    cout << "[";
    for (int i {}; i < MAX_SIZE; ++i) cout << sum(i, i) << ", ";
    cout << "]" << endl;
  }

  void showPrefixArray() {
    cout << "[";
    for (int i {}; i < MAX_SIZE; ++i) cout << sum(i) << ", ";
    cout << "]" << endl;
  }
};

int main() {
  const int sizeOfRange {5};
  auto f = FenwickTree<> {sizeOfRange};
  f.increase(0, 4);
  f.showArray();
  f.showPrefixArray();

  cout << f.sum(0, 4) << endl;

  return 0;
}