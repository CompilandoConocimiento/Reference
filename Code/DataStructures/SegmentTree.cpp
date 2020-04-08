template <typename T = int>
struct segment_tree {
  const int n;
  const T neutral;
  function<T(T, T)> fn;
  vector<T> nodes;
  segment_tree(int n, T fn(T, T), T neutral) : 
    nodes(2 * n, 0), n(n), fn(fn), neutral(neutral) {}

  auto build(const vector<T>& data) -> void {
    for (auto i = 0; i < data.size(); ++i) nodes[n + i] = data[i];
    for (auto i = n - 1; i > 0; --i) nodes[i] = fn(nodes[2 * i], nodes[2 * i + 1]);
  }

  auto update(const int p, const int value) -> void {
    nodes[n + p] = value;
    for (auto i = p + n; i > 1; i /= 2) 
      nodes[i / 2] = fn(nodes[i xor 0], nodes[i xor 1]);
  }

  auto query(const int left, const int right) -> T const {
    auto result = neutral;
    for (auto l = left + n, r = right + n; l < r; l /= 2, r /= 2) {
      if (l bitand 1) result = fn(result, nodes[l++]);
      if (r bitand 1) result = fn(result, nodes[--r]);
    }
    return result;
  }
};
