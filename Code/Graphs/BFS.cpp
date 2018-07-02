/*===================================================================================================
===========================         BFS: BREADTH FIRST SEARCH        ================================
===================================================================================================*/


/*===================================================================
=========     AJDACENT BFS: BREADTH FIRST SEARCH        =============
===================================================================*/

vector<int> GraphAdjacencyList::BFS(int InitialNode) {                  //Beadth Fisrt Search A to B

    vector<bool> VisitedNodes(AdjacencyList.size(), false);             //Visited Nodes 
    queue<int> AuxiliarQueue({InitialNode});                            //Create a Queue for BFS
    vector<int> PathSinceTheNode = {};                                  //Supose an empty path

    while(AuxiliarQueue.empty() == false) {                             //While have things to process

        int ActualNode = AuxiliarQueue.front();                         //Get the actual node
        AuxiliarQueue.pop();                                            //Now remove the actual node

        if (VisitedNodes[ActualNode] == false) {                        //Now if we have not visited
            PathSinceTheNode.push_back(ActualNode);                     //Then add to the path
            VisitedNodes[ActualNode] = true;                            //We have visited you
        }

        for (auto &ChildNode : AdjacencyList[ActualNode])               //For each Adjacent Node
            if (VisitedNodes[ChildNode] == false)                       //If we have not visited
                AuxiliarQueue.push(ChildNode);                          //Add to the queue
    }

    return PathSinceTheNode;                                            //Show me the nodes
}   
