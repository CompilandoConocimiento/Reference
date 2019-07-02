#include <iostream>
#include <queue>
#include <stack>
#include <vector>

#include "GraphRepresentations.cpp"

template <typename nodeID, typename fn>
auto GraphAdjacencyList<nodeID, fn>::BFS(nodeID initialNode, fn functionToCall) -> void {
  std::vector<bool> visited(adjacencyLists.size(), false);
  std::queue<int> nodesToProcess({initialNode});

  while (not nodesToProcess.empty()) {
    auto node {nodesToProcess.front()};
    nodesToProcess.pop();

    if (not visited[node]) {
      functionToCall(node, visited);
      visited[node] = true;
    }

    for (auto& adjacentNode : adjacencyLists[node])
      if (not visited[adjacentNode]) nodesToProcess.push(adjacentNode);
  }
}
