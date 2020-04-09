template <typename T = int>
struct segment_tree {
  const int n;
  const T neutral;
  T (*fn)(T, T);
  vector<T> nodes;
  segment_tree(int n, T fn(T, T), T neutral)
      : nodes(2 * n, neutral), n(n), fn(fn), neutral(neutral) {}

  auto build(const vector<T>& data) -> void {
    for (auto i = 0; i < data.size(); ++i) nodes[n + i] = data[i];
    for (auto i = n - 1; i > 0; --i) nodes[i] = fn(nodes[2 * i], nodes[2 * i + 1]);
  }

  auto update(const int p, const T value) -> void {
    nodes[n + p] = value;
    for (auto i = p + n; i > 1; i /= 2) nodes[i / 2] = fn(nodes[i xor 0], nodes[i xor 1]);
  }

  auto query(const int left, const int right) -> T const {
    auto result = neutral;
    for (auto l = left + n, r = right + n + 1; l < r; l /= 2, r /= 2) {
      if (l bitand 1) result = fn(result, nodes[l++]);
      if (r bitand 1) result = fn(result, nodes[--r]);
    }
    return result;
  }
};

template <typename T = int>
struct segment_tree {
 private:
  using node = int;
  const int n;
  const T neutral;
  T (*fn)(T, T);
  vector<T> nodes;

  void build(const vector<T>& data, int begin, int end, node current) {
    if (begin == end) {
      nodes[current] = data[begin];
      return;
    }

    auto middle = (begin + end) / 2;
    build(data, begin, middle, current * 2 + 1);
    build(data, middle + 1, end, current * 2 + 2);

    nodes[current] = fn(nodes[current * 2 + 1], nodes[current * 2 + 2]);
  }

  T query(int begin, int end, node current, int left, int right) {
    if (end < left or right < begin) return neutral;
    if (begin >= left and end <= right) return nodes[current];

    auto middle = (begin + end) / 2;
    auto l = query(begin, middle, current * 2 + 1, left, right);
    auto r = query(middle + 1, end, current * 2 + 2, left, right);

    return fn(l, r);
  }

  void update(int begin, int end, node current, int index, const T& val) {
    if (end < index or index < begin) return;

    if (begin == index and end == index) {
      nodes[current] = val;
      do {
        current = (current - 1) / 2;
        nodes[current] = fn(nodes[current * 2 + 1], nodes[current * 2 + 2]);
      } while (current != 0);

      return;
    }

    auto middle = (begin + end) / 2;
    update(begin, middle, current * 2 + 1, index, val);
    update(middle + 1, end, current * 2 + 2, index, val);
  }

 public:
  segment_tree(int n, T fn(T, T), T neutral)
      : nodes(4 * n, neutral), n(n), fn(fn), neutral(neutral) {}

  void build(const vector<T>& data) { build(data, 0, n - 1, 0); }
  T query(int left, int right) { return query(0, n - 1, 0, left, right); }
  void update(int index, const T& val) { update(0, n - 1, 0, index, val); }
};