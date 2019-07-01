#include <numeric>
#include <vector>

template <typename T>
class DisjointSet {
 private:
  std::vector<T> parent, count, rank;

 public:
  DisjointSet(int N, bool initializeNodes = true)
      : parent(N), count(N, 0), rank(N, 0) {
    if (initializeNodes) {
      for (T i {}; i < N; ++i) createNode(i);
    }
  }

  inline auto createNode(T node) -> void {
    count[node] = 1;
    parent[node] = node;
  }

  auto areSameSet(T nodeA, T nodeB) -> bool {
    return findParentNode(nodeA) == findParentNode(nodeB);
  }

  // Returns the representative of the disjoint set containing node
  auto findParentNode(T node) -> int {
    T& nodeParent = parent[node];
    if (node != nodeParent) {
      nodeParent = findParentNode(nodeParent);
    }

    return nodeParent;
  }

  auto joinSets(T nodeA, T nodeB) -> void {
    const T parentA {findParentNode(nodeA)};
    const T parentB {findParentNode(nodeB)};

    if (parentA == parentB) return;

    if (rank[parentA] < rank[parentB]) {
      parent[parentA] = parentB;
      count[parentB] += count[parentA];
    } else {
      parent[parentB] = parentA;
      count[parentA] += count[parentB];
      if (rank[parentA] == rank[parentB]) ++rank[parentA];
    }
  }
};