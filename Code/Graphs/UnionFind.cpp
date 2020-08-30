#include <utility>
#include <vector>

/**
 * You have many nodes connected (ie, node 2 with 4 and 8).
 * Use UnionFind to find if 2 nodes are connected or and
 * how many nodes can I go to from a given node.
 */
template <typename id = int>
class union_find {
  vector<id> num_connected_nodes_of, parent_of, rank_of;

 public:
  union_find(const id num_nodes)
      : num_connected_nodes_of(num_nodes, 1), parent_of(num_nodes), rank_of(num_nodes, 0) {
    for (id i = 0; i < num_nodes; ++i) { parent_of[i] = i; }
  }

  auto get_component_id(const int u) -> int {
    if (parent_of[u] != u) { parent_of[u] = get_component_id(parent_of[u]); }
    return parent_of[u];
  }

  auto join_components(const id u, const id v) -> void {
    auto id_of_u = get_component_id(u), id_of_v = get_component_id(v);
    if (id_of_u == id_of_v) return;

    if (rank_of[id_of_u] > rank_of[id_of_v]) swap(id_of_u, id_of_v);

    parent_of[id_of_u] = parent_of[id_of_v];
    num_connected_nodes_of[id_of_v] += num_connected_nodes_of[id_of_u];
    if (rank_of[id_of_u] == rank_of[id_of_v]) ++rank_of[id_of_v];
  }

  auto num_elements_connected_to(const id u) -> int {
    return num_connected_nodes_of[get_component_id(u)];
  }
};