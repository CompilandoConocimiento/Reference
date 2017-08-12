/*=============================================================================================================
====================================   GRAPHS REPRESENTATIONS        ==========================================
=============================================================================================================*/
#include <math.h>                                                                       //Include Libraries
#include <iostream>                                                                     //Include Libraries
#include <vector>                                                                       //Include Libraries
#include <set>                                                                          //Include Libraries
#include <map>                                                                          //Include Libraries
#include <list>                                                                         //Include Libraries
using namespace std;                                                                    //Bad practice, dont do

typedef unsigned long long ull;                                                         //Just a long name, sorry
typedef long long lli;                                                                  //Just a long name, sorry

/*===================================================================
======      GRAPH CLASS USING A LIST AND STRINGS NODES       ========
===================================================================*/

/* ******************* INFORMATION   **********************
        Info:
        -   This class represent a Directed Graph using Adjencency list 
            representation.
        
        -   This is a map, so the first element is a the Node, 
            and the Set is all the other Node that are avaible for visit

        -   The advantage of this Implementation is that the Nodes can be any 
            string
        */

class CoolGraphUsingList {

  private:
    map<string, set<string> >AdjacencyList;                                         //The Adjacency List

  public:
    void AddEdge(string FromThisNode, set<string> Nodes) {                          //Add an Edge to the Graph 
        for (auto& FinalNode : Nodes)                                               //For each Node in Final Nodes
            if (AdjacencyList.count(FinalNode) == false)                            //If  isn't this node in list
                AdjacencyList.insert({FinalNode, {}});                              //Add final node to the graph

        AdjacencyList[FromThisNode].insert(Nodes.begin(), Nodes.end());             //Either way, add the info
    }

    void ShowInformation() {                                                        //Show the information
        for (auto& InfoNode : AdjacencyList){                                       //For each Entrade in the List
            auto NodeName = InfoNode.first; auto AdjacentNodes = InfoNode.second;   //Create var's for clarity
            
            cout << "Node Name " << NodeName << ": ";                               //Show the Node Name
            for (auto AdjacentNode: AdjacentNodes) cout << AdjacentNode << ", ";    //Show each adjacent node
            cout << "\n";                                                           //Add the space
        }
    }

    vector<string> BFS(string InitialNode);                                         //Definition of the BFS!
};
           



