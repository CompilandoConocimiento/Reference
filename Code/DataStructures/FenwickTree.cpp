template <typename T = int>
class fenwick_tree {
 private:
  const int n;
  vector<T> nodes;

  static auto get_next(const int i) -> int { return i bitor (i + 1); }

 public:
  fenwick_tree(int n) : n(n), nodes(n, 0) {}

  auto build(const vector<T>& data) -> void {
    for (auto i = 0; i < n; ++i) {
      nodes[i] = nodes[i] + data[i];
      const auto next_index = get_next(i);
      if (next_index < n) nodes[next_index] = nodes[i] + nodes[next_index];
    }
  }

  auto sum(int end) -> T const {  // get the sum from [0, end]
    auto answer = T {};
    while (end >= 0) {
      answer = answer + nodes[end];
      end = (end bitand (end + 1)) - 1;
    }
    return answer;
  }

  auto sum(const int start, const int end) -> T const {
    return sum(end) - sum(start - 1);
  }

  auto increase(const int position, const T value) -> void {  // increase the position by a val
    for (auto p = position; p < n; p = get_next(p))
      nodes[p] = nodes[p] + value;
  }
};