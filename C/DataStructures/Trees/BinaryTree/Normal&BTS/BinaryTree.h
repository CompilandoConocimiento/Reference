/*==========================================================
============= DECLARATION OF A BINARYTREE IN C      ========
==========================================================*/
// ====================================
// ===  TYPE OF DATA TO BINARYTREE ====
// ====================================
typedef struct {                                                                //=== DATA STRUCT ===
   char Symbol;                                                                 //For now just a simple number
} Item;                                                                         //We call this an item of our BINARYTREE

// ====================================
// ==== DECLARATION OF A BINARYTREE  ==
// ====================================
typedef struct Node {                                                           //=== NODE ===
   Item *NodeItem;                                                              //Pointer to the real data
   struct Node *Left;                                                           //Pointer to the left node
   struct Node *Right;                                                          //Pointer to the left node
} Node;                                                                         //We call this struct a node
 
// ===================================
// ==== SOME THINGS OF SYNTAXIS   ====
// ===================================
typedef Node BinaryTree;                                                        //Recursion, after all a Tree is a SubTrees
#define Root (*TreeX)                                                           //Recursion, after all a Tree is a SubTrees
#define LeftTree (*TreeX)->Left                                                 //Recursion, after all a Tree is a SubTrees
#define RightTree (*TreeX)->Right                                               //Recursion, after all a Tree is a SubTrees
#define PointerToLeftTree &(*TreeX)->Left                                       //Recursion, after all a Tree is a SubTrees
#define PointerToRightTree &(*TreeX)->Right                                     //Recursion, after all a Tree is a SubTrees



/*==========================================================
============ FUNTIONS OF A BINARYTREE IN C    ==============
==========================================================*/

// ===========================================
// ==      NOT ESSENCIAL BY DEFINITION      ==
// ==  BUT ESSENCIAL FOR MY IMPLEMENTATION  ==
// ===========================================
Node* CreateBinaryTree(Item *NewItem);                                          // ==== CREATE A NEW NODE OF A BINARYTREE ==

void ShowItem(Item *ItemX);                                                     //YOU HAVE TO IMPLEMENT THIS
Item* CreateItem();                                                             //YOU HAVE TO IMPLEMENT THIS
Item* CreateNewItem(char Data);                                                 //YOU HAVE TO IMPLEMENT THIS

// ===========================================
// ==       ESSENCIAL BY DEFINITION         ==
// ===========================================
BinaryTree* InsertByLevel(int Index, Item **Data, int Size);                    // ==== CREATE A TREE FROM AN ARRAY  OF ITEMS ==

void InsertBTS(BinaryTree **TreeX, Item *Data);                                 // ==== INSERT IN A TREE LIKE IF IT WAS BTS ====
BinaryTree* SearchItemBTS(BinaryTree **TreeX, Item *Data);                      // ==== SEARCH IN A TREE LIKE IF IT WAS BTS ====
void DeleteItemBTS(BinaryTree **TreeX, Item *Data);                             // ==== DELETE IN A TREE LIKE IF IT WAS BTS ====

void EliminateTree(BinaryTree **TreeX);                                         // ==== DESTROY A BINARY TREE ================== 
int CompareItems(Item *DataLeft, Item *DataRight);                              // === COMPARE FOR BIGGER -1:LEFT, 1:Right =====


// ===========================================
// ==      NOT ESSENCIAL BY DEFINITION      ==
// ==       BUT JUST REALLY REALLY COOL     ==
// ===========================================
int Deepness(BinaryTree**TreeX);

void ShowPreOrder(BinaryTree **TreeX);                                          // ==== SHOW PREORDER BY A BINARY TREE =======
void ShowInOrder(BinaryTree **TreeX);                                           // ==== SHOW INORDER BY A BINARY TREE ======== 
void ShowPostOrder(BinaryTree **TreeX);                                         // ==== SHOW POSTORDER BY A BINARY TREE ====== 

BinaryTree* CreateTreeFromInOrder(char *A, int ShowIt);                         // ==== CREATE EXPRESSION TREE FROM INORDER == 
void ShowPathsToLeafs(BinaryTree **TreeX);                                      // ==== SHOW PATHS OF A BINARY TREE ========== 
void ShowLeverOrder(BinaryTree **TreeX);                                        // ==== SHOW DEEP OF A BINARY TREE ===========
