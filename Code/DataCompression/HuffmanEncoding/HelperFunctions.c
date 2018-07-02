/*===================================================================
==================        FUNCTIONS             =====================
===================================================================*/

/*=============================================
============         NODE           ===========
=============================================*/
typedef struct Node {                                                   //Create a node type
    byte Data;                                                          //Have a Data
    unsigned long long int Frequency;                                   //We will call it Node
    struct Node* Left;                                                  //For a tree
    struct Node* Right;                                                 //For a tree
} Node;  

byte GetBit(byte Data, byte Place) {return (Data >> Place) & 1;}        //Get a bit
void SetBit(byte *Data, byte Place) {(*Data) |= (1 << Place);}          //Set a bit

/**
 * Delete a tree, just that
 */
void DeleteTree(Node* Tree) {                                           //Delete a tree
    if (Tree->Right != NULL) DeleteTree(Tree->Right);                   //If child move there
    if (Tree->Left != NULL)  DeleteTree(Tree->Left);                    //If child move there
    free(Tree);                                                         //Free the node
}

/**
 * Delete a tree, just that
 */
void DeleteCodebook(char** Codebook) {                                  //Delete a codebook
    for (int i = 0; i < 256; ++i) {                                     //For each posible value
        if (Codebook[i] != NULL) free(Codebook[i]);                     //If we have something to see
    }
}

/**
 * This create a standard node
 */
Node* CreateNode(byte Data, ull Frequency, Node* Left, Node* Right) {   //Create a node
    Node* NewNode = (Node*) calloc(1, sizeof(Node));                    //Reserve memory
    NewNode->Data = Data;                                               //Put data
    NewNode->Frequency = Frequency;                                     //Put data
    NewNode->Left = Left;                                               //Put data
    NewNode->Right = Right;                                             //Put data

    return NewNode;                                                     //Give the data
}

