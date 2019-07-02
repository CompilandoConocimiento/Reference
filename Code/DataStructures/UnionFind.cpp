#include <iostream>
#include <numeric>

#include <unordered_map>
#include <vector>

/**
 *
 * You have many nodes (with ID's as numbers) and the nodes are connected (ie,
 * node 2 with node 4, 5, 8) Use UnionFind to find if 2 nodes are connected
 * or how many nodes are in a connected to a given node.
 *
 */
template <typename parentContainer, typename ID = int, typename numCount = int,
          typename numRank = int>
class UnionFind {
 private:
  parentContainer parent;
  std::vector<numCount> count;
  std::vector<numRank> rank;

  // Get the representant node ID from a set
  auto findParentNode(ID node) -> ID {
    ID& nodeParent = parent[node];
    if (node == nodeParent) return node;

    nodeParent = findParentNode(nodeParent);
    return nodeParent;
  }

 public:
  UnionFind(ID numNodes) : count(numNodes, 1), rank(numNodes, 0) {
    parent.resize(numNodes);  // Delete if parentContainer is a unordered_map
    for (ID i {}; i < numNodes; ++i) parent[i] = i;
  }

  auto areConnected(ID nodeA, ID nodeB) -> bool {
    return findParentNode(nodeA) == findParentNode(nodeB);
  }

  auto numberOfElementsInSet(ID node) -> numCount {
    return count[findParentNode(node)];
  }

  auto joinSets(ID nodeA, ID nodeB) -> void {
    ID setA {findParentNode(nodeA)}, setB {findParentNode(nodeB)};

    if (setA == setB) return;
    if (rank[setA] < rank[setB]) std::swap(setA, setB);

    parent[setB] = setA;
    count[setA] += count[setB];

    if (rank[setA] == rank[setB]) ++rank[setA];
  }
};
