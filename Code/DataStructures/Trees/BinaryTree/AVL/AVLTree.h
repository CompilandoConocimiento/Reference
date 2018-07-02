/*==========================================================
============= DECLARATION OF A AVL TREE IN C        ========
==========================================================*/
// ====================================
// ===  TYPE OF DATA TO AVL TREE   ====
// ====================================
typedef struct {                                                                //=== DATA STRUCT ===
   int Symbol;                                                                  //For now just a simple number
} Item;                                                                         //We call this an item of our BINARYTREE

// ====================================
// ==== DECLARATION OF A AVL TREE    ==
// ====================================
typedef struct Node {                                                           //=== NODE ===
   Item *NodeItem;                                                              //Pointer to the real data
   int Height;                                                              	//The Height of the node
   struct Node *Left;                                                           //Pointer to the left node
   struct Node *Right;                                                          //Pointer to the left node
} AVLTreeNode;                                                               	//We call this struct a node
 
// ===================================
// ==== SOME THINGS OF SYNTAXIS   ====
// ===================================
typedef AVLTreeNode AVLTree;													//A node is a tree after all
#define AVLRoot (*AVLTreeX)                                             		//Sorry hate those *
#define LeftAVLSubTree (*AVLTreeX)->Left                                     	//Sorry hate those *
#define RightAVLSubTree (*AVLTreeX)->Right                                     	//Sorry hate those *
#define GoLeftAVLSubTree &(*AVLTreeX)->Left                               		//Sorry hate those *
#define GoRightAVLSubTree &(*AVLTreeX)->Right                            		//Sorry hate those *



/*==========================================================
============ FUNTIONS OF A AVL TREE IN C      ==============
==========================================================*/

// ===========================================
// ==      NOT ESSENCIAL BY DEFINITION      ==
// ==  BUT ESSENCIAL FOR MY IMPLEMENTATION  ==
// ===========================================
AVLTree* CreateAVLTree(Item *NewItem);                                 			// ==== CREATE A NEW NODE OF AN AVL TREE =======

Item* CreateItem();                                                             //YOU HAVE TO IMPLEMENT THIS
Item* CreateNewItem(int Data);                                                 	//YOU HAVE TO IMPLEMENT THIS
void ShowItem(Item *ItemX);                                                     //YOU HAVE TO IMPLEMENT THIS

// ===========================================
// ==       ESSENCIAL BY DEFINITION         ==
// ===========================================

// =================================
// ==     THE BALANCE PART        ==
// =================================
int Deepness(AVLTree *AVLTreeX);
int GetHeight(AVLTree *AVLTreeX);

int CompareItems(Item *DataLeft, Item *DataRight);								// === COMPARE FOR BIGGER -1:LEFT, 1:Right =====
AVLTree* SearchItemAVL(AVLTree *AVLTreeX, Item *Data);							// ==== SEARCH IN A BALANCE TREE ===============

void InsertInAVL(AVLTree **AVLTreeX, Item *Data);								// ==== INSERT IN A BALANCE TREE ===============
void DeleteInAVL(AVLTree **AVLTreeX, Item *Data);								// ==== INSERT IN A BALANCE TREE ===============




// ===========================================
// ==      NOT ESSENCIAL BY DEFINITION      ==
// ==       BUT JUST REALLY REALLY COOL     ==
// ===========================================

void ShowPreOrder(AVLTree *AVLTreeX);                                          // ==== SHOW PREORDER BY A BINARY TREE =========
void ShowInOrder(AVLTree *AVLTreeX);                                          	// ==== SHOW INORDER BY A BINARY TREE ==========
void ShowPostOrder(AVLTree *AVLTreeX);                                        	// ==== SHOW POSTORDER BY A BINARY TREE ========
