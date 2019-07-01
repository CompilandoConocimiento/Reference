#include <vector>

template <typename T>
class SegmentTree {
 private:
  const int N;
  std::vector<T> data;

  son1(int i) { return i << 1; }
  son2(int i) { return i << 1 | 1; }

 public:
  // build from an array in O(n)
  SegmentTree(const vector<T>& originalData) {
    N {originalData.size()};
    data.resize(N << 1);

    for (int i {}; i < N; ++i) data[N + i] = originalData[i];
    for (int i {N - 1}; i > 0; --i) data[i] = data[son1(i)] + data[son2(i)];
  }

  // single element update in i
  auto update(int index, T value) -> void {
    data[index += N] = value;  // update the element accordingly
    while (index >>= 1) data[index] = data[son1(index)] + data[son2(index)];
  }

  // single element update in [start, end]
  auto update(int start, int end, T value) -> void {
    start += N, end += N;
    
    for (int i = start; i <= end; ++i) data[i] = value;
    start >>= 1, end >>= 1;

    while (start >= 1) {
      for (int i = end; i >= start; --i) data[i] = data[i << 1] + data[i << 1 | 1];
      start >>= 1, end >>= 1;
    }
  }

  // range query, [start, end]
  auto query(int start, int end) -> T {
    T answer {};

    start += N, end += N;
    while (start <= end) {
      if (start & 1) answer += data[start++];
      if (end & 1) answer += data[--end];

      start >>= 1, end >>= 1;
    }

    return answer;
  }
};