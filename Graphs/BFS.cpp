/*=============================================================================================================
====================================  BFS: BREADTH FIRST SEARCH      ==========================================
=============================================================================================================*/

#include <math.h>                                                               //Include Libraries
#include <iostream>                                                             //Include Libraries
#include <vector>                                                               //Include Libraries
#include <set>                                                                  //Include Libraries
#include <map>                                                                  //Include Libraries
#include <list>                                                                 //Include Libraries
#include "GraphRepresentations.cpp"                                             //Include Libraries
using namespace std;                                                            //Bad practice, dont do it kids!

typedef unsigned long long ull;                                                 //Just a so long name, sorry
typedef long long lli;                                                          //Just a so long name, sorry


/*===================================================================
==============          BFS: BREADTH FIRST SEARCH       =============
===================================================================*/
vector<string> CoolGraphUsingList::BFS(string InitialNode) {                    //Beadth Fisrt Search from A to B

    vector<string> PathToNode = { };                                            //Supose an empty path
    list<string> AuxiliarQueue = {InitialNode};                                 //Create a Queue for BFS with the 1

    map<string, bool> VisitedNodes;                                             //Visited Nodes 
    for (auto& InfoNode : AdjacencyList) VisitedNodes[InfoNode.first] = false;  //Put all nodes to not visited
    VisitedNodes[InitialNode] = true;                                           //Mark the Actual node as visited

    for (; !AuxiliarQueue.empty(); AuxiliarQueue.pop_front()){                  //For each element in the Queue
        cout << AuxiliarQueue.front() << " ";                                   //Show it!

        for (auto Node : AdjacencyList[AuxiliarQueue.front()]) {                //For each Adjacent Node
            if (VisitedNodes[Node] == false) {                                  //If we have not visited
                AuxiliarQueue.push_back(Node);                                  //Add to the queue
                VisitedNodes[Node] = true;                                      //Now visited
            }
        }
    }

    return PathToNode;
}   


///*

int main() {

    CoolGraphUsingList SomeGraph;

    SomeGraph.AddEdge("0", {"1", "2"});
    SomeGraph.AddEdge("1", {"2"});
    SomeGraph.AddEdge("2", {"0", "3"});
    SomeGraph.AddEdge("3", {"3"});
    SomeGraph.ShowInformation();

    SomeGraph.BFS("2");

    return 0;

}


//*/

