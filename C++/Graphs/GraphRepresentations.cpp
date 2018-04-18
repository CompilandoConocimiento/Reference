/*======================================================================================================
=============================          GRAPHS REPRESENTATIONS        ===================================
======================================================================================================*/
#include <iostream>                                                             //Include Libraries
#include <vector>                                                               //Include Libraries
#include <queue>                                                                //Include Libraries
#include <stack>                                                                //Include Libraries

using namespace std;                                                            //Bad practice dont do

/*===================================================================
============          GRAPH AS AJDACENT LIST           ==============
===================================================================*/
/* ******************* INFORMATION   **********************
    Info:
    - All the node names are naturals from 0 to NumberOfNodes
    */
class GraphAdjacencyList {

  //===================================
  //========   PRIVATE    =============
  //===================================
  private:
    bool IsBidireccional;                                                       //Is bidireccional graph
    std::vector< std::vector<int> > AdjacencyList;                              //The Adjacency List

  //===================================
  //========    PUBLIC     ============
  //===================================
  public:

    GraphAdjacencyList(int NumberOfNodes, bool IsBidireccional = true):         //Inicializace
        IsBidireccional(IsBidireccional),                                       //Set for directional graph
        AdjacencyList(NumberOfNodes)                                            //Set the adj list to n
    {}                                                                          //Nothing to do


    void AddEdge(int FromThisNode, int ToThisNode) {                            //Add an Edge to the Graph 
        AdjacencyList[FromThisNode].push_back(ToThisNode);                      //Either way, add the info
        if (IsBidireccional) AdjacencyList[ToThisNode].push_back(FromThisNode); //Either way, add the info
    }

    void AddConections(vector< pair<int,int> > Conections) {                    //Add many edges to graph
        for(auto &Edge : Conections)                                            //Foreach edge
            AddEdge(Edge.first, Edge.second);                                   //Add it like normal
    }

    void ShowConsoleInformation() {                                             //Show the information
        for (int i = 0; i < AdjacencyList.size(); ++i) {                        //Foreach Node    
            cout << "Node " << i << ": [";                                      //Show the Node Name
            for (auto &AdjacentNode: AdjacencyList[i])                          //For each conections
                cout << AdjacentNode << " ";                                    //Show each adjacent node
            cout << "]\n";                                                      //Add the space
        }
    }

    //===================================
    //=======    NEW FUNCTIONS    =======
    //===================================
    vector<int> BFS(int InitialNode);                                           //Definition of the BFS!
    vector<int> DFS(int InitialNode);                                           //Definition of the BFS!
};
           





/*===================================================================
============          GRAPH AS AJDACENT LIST           ==============
===================================================================*/
class PonderateGraph {

  //===================================
  //========   PRIVATE    =============
  //===================================
  private:
    int NumberOfNodes;                                                          //Number of nodes
    vector< pair<double, pair<int, int> > > Edges;                              //Get the edges

  //===================================
  //========    PUBLIC     ============
  //===================================
  public:

    PonderateGraph(int NumberOfNodes) {                                         //Graph Constructor
        this->NumberOfNodes = NumberOfNodes;                                    //Add the Number of Nodes
    }                                                                           //Nothing to do

    void AddEdge(int FromThisNode, int ToThisNode, double Weight) {             //Add an Edge to the Graph 
       Edges.push_back({Weight, {FromThisNode, ToThisNode}});                   //Add to vector
    }

    //===================================
    //=======    NEW FUNCTIONS    =======
    //===================================
    pair<double, vector<pair<int, int> > > KruskalMST();                        //Minimal Spanning Tree
};


