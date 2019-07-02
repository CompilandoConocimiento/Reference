#include <algorithm>
#include <set>
#include "GraphRepresentations.cpp"
#include "UnionFind.cpp"

template <typename nodeID, typename weight>
auto PonderateGraph<nodeID, weight>::KruskalMinimumExpansionTree(
    nodeID nodesInGraph) -> std::pair<set<nodeID>, weight> {
  using node = const node<nodeID, weight>;

  auto minimumSpanningTreeWeight = weight {};
  auto nodesInTree = set<nodeID> {};
  auto graphInfo = UnionFind<std::vector<nodeID>, nodeID> {nodesInGraph};
  auto sortNode = [](node& n1, node& n2) { return n1.cost < n2.cost; };
  sort(edges.begin(), edges.end(), sortNode);

  for (node& edge : edges) {
    // check if edge is creating cycle
    if (graphInfo.existPath(edge.to, edge.from)) continue;

    nodesInTree.insert(edge.to);
    nodesInTree.insert(edge.from);

    minimumSpanningTreeWeight += edge.cost;
    graphInfo.joinComponents(edge.to, edge.from);
    if (graphInfo.numberOfElementsInAComponent(edge.to) == nodesInGraph) break;
  }

  return {nodesInTree, minimumSpanningTreeWeight};
}