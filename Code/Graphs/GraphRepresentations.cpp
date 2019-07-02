#include <iostream>
#include <vector>

using namespace std;

template <typename nodeID, typename fn>
class GraphAdjacencyList {
 private:
  std::vector<std::vector<nodeID>> adjacencyLists;

 public:
  const bool isBidirectional;

  GraphAdjacencyList(nodeID numOfNodes, bool isBidirectional = true)
      : isBidirectional(isBidirectional), adjacencyLists(numOfNodes) {}

  void addEdge(nodeID fromThisNode, nodeID toThisNode) {
    adjacencyLists[fromThisNode].push_back(toThisNode);
    if (not isBidirectional) return;
    adjacencyLists[toThisNode].push_back(fromThisNode);
  }

  void addConections(const vector<pair<nodeID, nodeID>>& conections) {
    for (const auto& edge : conections) addEdge(edge.first, edge.second);
  }

  void show() {
    nodeID node {};
    for (auto& adjacencyList : adjacencyLists) {
      cout << "Node ID = " << node++ << ": [";
      for (auto& node : adjacencyList) cout << node << " ";
      cout << "]" << '\n';
    }
  }

  auto BFS(nodeID initialNode, fn functionToCall) -> void;
  auto DFS(nodeID initialNode, fn functionToCall) -> void;
};

template <typename nodeID, typename weight>
struct node {
  nodeID from, nodeID to;
  weight w;
};

template <typename nodeID, typename weight>
class PonderateGraph {
 private:
  std::vector<node<nodeID, weight>> edges;

 public:
  void addEdge(nodeID fromThisNode, nodeID toThisNode, weight w) {
    edges.push_back({fromTo, toThisNode, weight});
  }

  auto KruskalMinimumExpansionTree(nodeID maxNodeID)
      -> std::pair<set<nodeID>, weight>;
};