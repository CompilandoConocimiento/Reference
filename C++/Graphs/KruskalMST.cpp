/*===================================================================================================
===========================         BFS: BREADTH FIRST SEARCH        ================================
===================================================================================================*/
#include <algorithm>                                                       //Include Libraries
#include "UnionFind-DisjointSet";

/*===================================================================
=========     KRUSKAL - MINIMUM SPANNING WEIGHT         =============
===================================================================*/
pair<double, vector< pair<int, int> > > PonderateGraph::KruskalMST() {      //Begin the function

    double MinimumSpanningTree = 0;                                         //Initialize result
    sort(Edges.begin(), Edges.end());                                       //Sort in increasing by cost
    UnionFind SomeDisjointSet(NumberOfNodes);                               //Create disjoint sets
    vector<pair<int, int> > Nodes;                                          //Create the Nodes

    for (auto Edge : Edges) {                                               //Iterate through all sorted edges
        
        int u = Edge.second.first;                                          //Simple name
        int v = Edge.second.second;                                         //Simple name
 
        int SetU = SomeDisjointSet.SuperParent(u);                          //Get the parent
        int SetV = SomeDisjointSet.SuperParent(v);                          //Get the parent
 
        if (SetU != SetV) {                                                 //Check if edge is creating cycle
            Nodes.push_back({u, v});                                        //Add the node
            MinimumSpanningTree += Edge.first;                              //Update MST weight
            SomeDisjointSet.Join(SetU, SetV);                               //Merge two sets
        }

    }

    return {MinimumSpanningTree, Nodes};                                    //Now return the data
}