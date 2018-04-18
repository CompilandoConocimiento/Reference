/*===================================================================
==================    METADATA OF THE FILE      =====================
===================================================================*/
/**
 * @author  Rosas Hernandez Oscar Andres
 * @author  Alan Enrique Ontiveros Salazar
 * @author  Laura Andrea Morales 
 * @version 0.1
 * @team    CompilandoConocimiento
 * @date    2/04/2018
 */

// ====================================
// ==== DECLARATION OF A BINARYTREE  ==
// ====================================
typedef struct Node {                                               //=== NODE ===
   int  NodeItem;                                                   //Pointer to the real data
   struct Node *Left;                                               //Pointer to the left node
   struct Node *Right;                                              //Pointer to the left node
   int Index;                                                       //Index of the original arary
} Node;                                                             //We call this struct a node


typedef Node BinaryTree;                                            //New name same functionality



/*===================================================================
===========              DECLARATION            =====================
===================================================================*/
Node* CreateBST(int Data[], int DataSize);
void FromSortedArray(Node** Tree, int Data[], int i, int j);
Node* CreateBSTFromSortedArray(int Data[], int DataSize);
void IterativeInsertBST(BinaryTree **Tree, int NewItem, int Index);
void IterativeCreateInOrder(Node **Tree, int *Data, int DataSize);


/*===================================================================
===========        CREATE A BINARY TREE         =====================
===================================================================*/
/**
 * Create a Pointer to a Binary Tree that have the data
 * that i give you. Note inline
 * 
 * @param NewItem   The data that the node will save
 * @param Index     The index of the number in the array
 * @return          (Node*) A pointer to the new node
 */
extern inline Node* CreateBinaryTree(int NewItem, int Index) {      // ==== CREATE A NEW NODE ==
    Node *NewNode = (Node*) malloc(sizeof(Node));                   //Reserve memory for  node
    NewNode->NodeItem = NewItem;                                    //You will protect this 
    NewNode->Left = NULL;                                           //And maybe you're a leaf
    NewNode->Right = NULL;                                          //And maybe you're a leaf
    NewNode->Index = Index;                                         //And maybe you're a leaf
    return NewNode;                                                 //Go, go NewNode :')
}





/*===================================================================
===========        CREATE A BINARY SEARCH TREE        ===============
===================================================================*/


/*========================================================
===========        NORMAL FUNCTION         ===============
========================================================*/
/**
 * Create a Pointer to a Seacrh Binary Tree 
 * 
 * @param NewItem   The data that the node will save
 * @param Index     The index of the number in the array
 * @return          (Node*) A pointer to the new node
 */
Node* CreateBST(int Data[], int DataSize) {
    Node* Tree = NULL;                                              //Start with empty tree

    for (int i = 0; i < DataSize; i++)                              //For each element
        IterativeInsertBST(&Tree, Data[i], i);                      //Insert in tree

    return Tree;                                                    //return the pointer to tree
}

/*========================================================
===========        HELPER FUCTION          ===============
========================================================*/
void FromSortedArray(Node** Tree, int Data[], int i, int j) {      
    if (i > j) return;                                              //Break

    int Middle = i + ((j - i) >> 1);                                //Create new middle point

    *Tree = CreateBinaryTree(Data[Middle], Middle);                 //Create the data node    

    FromSortedArray(&((*Tree)->Left), Data, i, Middle - 1);         //Recursion
    FromSortedArray(&((*Tree)->Right), Data, Middle + 1, j);        //Recursion
}


/*========================================================
=======      FROM A SORTED ARRAY FUNCTION         ========
========================================================*/
/**
 * Create a Pointer to a Search Binary Tree from a sorted array
 * 
 * @param NewItem   The data that the node will save
 * @param Index     The index of the number in the array
 * @return          (Node*) A pointer to the new node
 */
Node* CreateBSTFromSortedArray(int Data[], int DataSize) {
    Node* Tree = NULL;                                              //Create a point
    FromSortedArray(&Tree, Data, 0, DataSize - 1);                  //Initial recursion
    return Tree;                                                    //Go
}


/*===================================================================
========          INSERT IN A BINARY SEARCH TREE       ==============
===================================================================*/
/**
 * Create a Pointer to a Binary SEARCH Tree that have the data
 * that i give you, note that this algorithm is an implementation
 *  of a famous algorithm but this is not recursive
 * 
 * @param Tree      A pointer to a pointer to a Tree struct
 * @param Index     The index of the number in the array
 * @param NewItem   The data to be inserted
 * @return          Nothing...
 */
void IterativeInsertBST(BinaryTree **Tree, int NewItem, int Index) {// ==== INSERT IN A TREE ==
    Node **NewNode = Tree;                                          //Let start at root

    while (*NewNode != NULL)                                        //While are not at a leaf
        NewNode = (NewItem < (*NewNode)->NodeItem)?                 //We have to move right
            &((*NewNode)->Left): &((*NewNode)->Right);              //Move left or right    

    (*NewNode) = CreateBinaryTree(NewItem, Index);                  //Create a node at a leaf
}



/*===================================================================
========   IN ORDER TRANSVERSE OF A BINARY SEARCH TREE      =========
===================================================================*/
/**
 * This will give you an array fill with the data of a tree
 * if you transverse it inorder
 * 
 * @param Tree      A pointer to a pointer to a Tree struct
 * @param DataSize  The data size
 * @param Data[]    This is a pointer to an ALREADY reserve Data
                    size dimension
 * @return          Nothing...
 */
void IterativeCreateInOrder(Node **Tree, int *Data, int DataSize) { //= CREATE ARRAY FROM TREE ==
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
            Data[i++] = ActualNode->NodeItem;                       //Now, add to the data array
            ActualNode = ActualNode->Right;                         //And move to right
        }
    }
    while (ActualNode != NULL || StackPointer >= 0);                //Now do this while we can

    free(Stack);                                                    //Bye Stack :)
}

