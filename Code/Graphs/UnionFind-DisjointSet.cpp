
// =======================================================
// =====       UNION FIND (DISJOINT SET)         =========
// =======================================================
#include <vector>
#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

// ================================================
// =====     UNION FIND (DISJOINT SET)     ========
// ================================================
/*
    Remember:
        UnionFind needs the number of nodes
        at creation
*/

struct UnionFind {
    std::vector<int> SizeComponents;
    std::vector<int> Parent;
    int NumberOfNodes;

    UnionFind(int n) : 
        SizeComponents(n, 1), Parent(n) {
        NumberOfNodes = n;
        while (--n) Parent[n] = n;
    }

    int SuperParent(int u) {
        if (Parent[u] == u) return u;
        return Parent[u] = SuperParent(Parent[u]);
    }

    bool ExistPath(int u, int v) {
        return SuperParent(v) == SuperParent(u);
    }

    void Join(int u, int v) {
        int SuperParentU = SuperParent(u);
        int SuperParentV = SuperParent(v);

        if (SuperParentU == SuperParentV) return;

        Parent[SuperParentU] = SuperParentV;
        SizeComponents[SuperParentV] += SizeComponents[SuperParentU];
    }

    int SizeComponent(int u) {
        return SizeComponents[SuperParent(u)];
    }

};
