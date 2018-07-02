/*=================================================================================================
===========================         DFS: DEPTH FIRST SEARCH          ==============================
=================================================================================================*/


/*===================================================================
=========     AJDACENT DFS: DEPTH FIRST SEARCH          =============
===================================================================*/
/* ******************* INFORMATION   **********************
    Info:
    - In simple terms it will transverse all the graph until it find a leaf or
        a cycle.
        
        That's why we use a stack, so, we will pop the first element
        and left under and under the first nodes at the top.
    */

vector<int> GraphAdjacencyList::DFS(int InitialNode) {                  //Depth Fisrt Search A to B

    vector<bool> VisitedNodes(AdjacencyList.size(), false);             //Visited Nodes 
    stack<int> StackToVisit({InitialNode});                             //Create the Stack
    vector<int> PathSinceTheNode = {};                                  //Supose an empty path

    while(StackToVisit.empty() == false) {                              //While have things to process
        
        int ActualNode = StackToVisit.top();                            //Get the actual node
        StackToVisit.pop();                                             //Now remove the actual node

        if (VisitedNodes[ActualNode] == false) {                        //Now if we have not visited
            PathSinceTheNode.push_back(ActualNode);                     //Then add to the path
            VisitedNodes[ActualNode] = true;                            //We have visited you
        }

        for (auto &ChildNode : AdjacencyList[ActualNode])               //For each Adjacent Node
            if (VisitedNodes[ChildNode] == false)                       //If we have not visited
                StackToVisit.push(ChildNode);                           //Add to the queue
    }

    return PathSinceTheNode;                                            //Go, my friend
}
