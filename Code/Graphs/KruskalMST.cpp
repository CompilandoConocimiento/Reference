#include <algorithm>
#include <set>
#include "GraphRepresentations.cpp"
#include "UnionFind.cpp"

template <typename nodeID, typename weight>
auto PonderateGraph<nodeID, weight>::KruskalMinimumExpansionTree(
    nodeID maxNodeID) -> std::pair<set<nodeID>, weight> {
  using node = const node<nodeID, weight>&;

  auto sortNode = [](node n1, node n2) { return n1.cost < n1.cost; };
  sort(edges.begin(), edges.end(), sortNode);

  auto minimumSpanningTreeWeight = 0.0;
  auto nodesInTree = set<nodeID> {};
  auto graphInfo = UnionFind<std::vector<nodeID>, nodeID> {maxNodeID};

  for (node edge : edges) {
    // check if edge is creating cycle
    if (not graphInfo.existPath(edge.to, edge.from)) {
      nodesInTree.insert(edge.to);
      nodesInTree.insert(edge.from);

      minimumSpanningTreeWeight += edge.cost;
      graphInfo.joinComponent(edge.to, edge.from);
    }
  }

  return {nodesInTree, minimumSpanningTreeWeight};
}