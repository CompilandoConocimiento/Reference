// ====================================
// ==== DECLARATION OF A BINARYTREE  ==
// ====================================
typedef struct Node {                                               //=== NODE ===
   int  NodeItem;                                                   //Pointer to the real data
   struct Node *Left;                                               //Pointer to the left node
   struct Node *Right;                                              //Pointer to the left node
} Node;                                                             //We call this struct a node
 
// ===================================
// ==== SOME THINGS OF SYNTAXIS   ====
// ===================================
typedef Node BinaryTree;                                            //New name same functionality

Node* CreateBinaryTree(int NewItem) {                               // ==== CREATE A NEW NODE ==
    Node *NewNode = (Node*) malloc(sizeof(Node));                   //Reserve memory for  node
    NewNode->NodeItem = NewItem;                                    //You will protect this 
    NewNode->Left = NULL;                                           //And maybe you're a leaf
    NewNode->Right = NULL;                                          //And maybe you're a leaf
    return NewNode;                                                 //Go, go NewNode :')
}

void IterativeInsertBST(BinaryTree **Tree, int NewData) {           // ==== INSERT IN A TREE ==
    Node **NewNode = Tree;                                          //Let start at root

    while (*NewNode != NULL)                                        //While are not at a leaf
        NewNode = (NewData < (*NewNode)->NodeItem)?                 //We have to move right
            &((*NewNode)->Left): &((*NewNode)->Right);              //Move left or right    

    (*NewNode) = CreateBinaryTree(NewData);                         //Create a node at a leaf
}


void IterativeCreateInOrder(Node **Tree, int Data[], int DataSize) {//= CREATE ARRAY FROM TREE ==
    Node *ActualNode = *Tree;                                       //Now, use a temporal node 

    Node **Stack = calloc(DataSize, sizeof(Node*));                 //Create a stack like

    int StackPointer = -1, i = 0;                                   //Aux variables          

    do {                                                            //Do the next:
        
        while (ActualNode != NULL) {                                //While we are not a leaf
            Stack[++StackPointer] = ActualNode;                     //Add to stack the node
            ActualNode = ActualNode->Left;                          //Move to the fuck to left
        }

        if (StackPointer >= 0) {                                    //Ok, now while not empty
            ActualNode = Stack[StackPointer--];                     //Start pushing the data
            NewData[i++] = ActualNode->NodeItem;                    //Now, add to the data array
            ActualNode = ActualNode->Right;                         //And move to right
        }
    }
    while (ActualNode != NULL || StackPointer >= 0);                //Now do this while we can

    free(Stack);                                                    //Bye Stack :)
}




