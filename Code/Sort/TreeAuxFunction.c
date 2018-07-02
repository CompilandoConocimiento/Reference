/*===================================================================
==================    METADATA OF THE FILE      =====================
===================================================================*/
/**
 * @author  Rosas Hernandez Oscar Andres
 * @author  Alan Enrique Ontiveros Salazar
 * @author  Laura Andrea Morales 
 * @version 0.1
 * @team    CompilandoConocimiento
 * @date    4/03/2018
 */

// ====================================
// ==== DECLARATION OF A BINARYTREE  ==
// ====================================
typedef struct Node {                                               //=== NODE ===
   int  NodeItem;                                                   //Pointer to the real data
   struct Node *Left;                                               //Pointer to the left node
   struct Node *Right;                                              //Pointer to the left node
} Node;                                                             //We call this struct a node

typedef Node BinaryTree;                                            //New name same functionality




/*===================================================================
===========        CREATE A BINARY TREE         =====================
===================================================================*/
/**
 * Create a Pointer to a Binary Tree that have the data
 * that i give you. Note inline
 * 
 * @param NewItem   The data that the node will save
 * @return          (Node*) A pointer to the new node
 */
extern inline Node* CreateBinaryTree(int NewItem) {                 // ==== CREATE A NEW NODE ==
	Node *NewNode = (Node*) malloc(sizeof(Node));                   //Reserve memory for  node
	NewNode->NodeItem = NewItem;                                    //You will protect this 
	NewNode->Left = NULL;                                           //And maybe you're a leaf
	NewNode->Right = NULL;                                          //And maybe you're a leaf
	return NewNode;                                                 //Go, go NewNode :')
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
 * @param NewItem   The data to be inserted
 * @return          Nothing...
 */
void IterativeInsertBST(BinaryTree **Tree, int NewItem) {           // ==== INSERT IN A TREE ==
	Node **NewNode = Tree;                                          //Let start at root

	while (*NewNode != NULL)                                        //While are not at a leaf
		NewNode = (NewItem < (*NewNode)->NodeItem)?                 //We have to move right
			&((*NewNode)->Left): &((*NewNode)->Right);              //Move left or right    

	(*NewNode) = CreateBinaryTree(NewItem);                         //Create a node at a leaf
}

/*===================================================================
========   IN ORDER TRANSVERSE OF A BINARY SEARCH TREE      =========
===================================================================*/
/**
 * This will give you an array fill with the data of a tree
 * if you transverse it inorder
 * 
 * @param Tree      A pointer to a pointer to a Tree struct
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




