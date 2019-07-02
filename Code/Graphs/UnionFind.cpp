#include <iostream>
#include <numeric>
#include <vector>

class SimpleUnionFind {
 private:
  std::vector<int> nodesInComponent, parent;

 public:
  SimpleUnionFind(int n) : nodesInComponent(n, 1) {
    parent.resize(n);
    while (--n) parent[n] = n;
  }

  auto findParentNode(int u) -> int {
    if (parent[u] == u) return u;
    return parent[u] = findParentNode(parent[u]);
  }

  auto existPath(int u, int v) -> bool {
    return findParentNode(v) == findParentNode(u);
  }

  auto numberOfElementsInAComponent(int u) -> int {
    return nodesInComponent[findParentNode(u)];
  }

  auto joinComponents(int u, int v) -> void {
    int setU = findParentNode(u), setV = findParentNode(v);
    if (setU == setV) return;

    parent[setU] = setV;
    nodesInComponent[setV] += nodesInComponent[setU];
  }
};

#include <map>
#include <unordered_map>

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
  std::vector<numCount> nodesInComponent;
  std::vector<numRank> rank;

  // Get the representant node ID from a component
  auto findParentNode(ID node) -> ID {
    ID& nodeParent = parent[node];
    if (node == nodeParent) return node;

    nodeParent = findParentNode(nodeParent);
    return nodeParent;
  }

 public:
  UnionFind(ID numNodes) : nodesInComponent(numNodes, 1), rank(numNodes, 0) {
    parent.resize(numNodes);  // Delete if parentContainer is a map
    while (--numNodes) parent[numNodes] = numNodes;
  }

  auto existPath(ID nodeA, ID nodeB) -> bool {
    return findParentNode(nodeA) == findParentNode(nodeB);
  }

  auto numberOfElementsInAComponent(ID node) -> numCount {
    return nodesInComponent[findParentNode(node)];
  }

  auto joinComponents(ID nodeA, ID nodeB) -> void {
    ID setA {findParentNode(nodeA)}, setB {findParentNode(nodeB)};

    if (setA == setB) return;
    if (rank[setA] < rank[setB]) std::swap(setA, setB);

    parent[setB] = setA;
    nodesInComponent[setA] += nodesInComponent[setB];

    if (rank[setA] == rank[setB]) ++rank[setA];
  }
};
