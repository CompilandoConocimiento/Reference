/*==========================================================
============= DECLARATION OF A STACK IN C    ===============
==========================================================*/

// =================================
// ==  TYPE OF DATA TO STACK      ==
// =================================
typedef struct {                                                //=== DATA STRUCT ===
   int number;                                                  //For now just a simple number
} Item;                                                         //We call this an item of our Stack

// =================================
// ==== DECLARATION OF A STACK   ===
// =================================
typedef struct Node {                                           //=== NODE ===
   Item *NodeItem;                                              //Pointer to the real data
   struct Node *Next;                                           //Pointer to the next node
} Node;                                                         //We call this struct a node
 
// =================================
// ==== SOME THINGS OF SYNTAXIS   ==
// =================================
#define Front *StackX                                           //The head of a stack is just the stack Pointer
#define Stack Node                                              //At the end a stack is just a node
#define GoNextNode CurrentNode=CurrentNode->Next                //This is what incrementing a Node is :3



/*==========================================================
============ FUNTIONS OF A STACK IN C    ===================
==========================================================*/

// ===========================================
// ==      NOT ESSENCIAL BY DEFINITION      ==
// ==  BUT ESSENCIAL FOR MY IMPLEMENTATION  ==
// ===========================================
Stack* CreateStack();                                           // ==== CREATE-INITIALIZE A STACK =====
Node* CreateNode(Item *NewItem);                                // ==== CREATE A NEW NODE OF A STACK ==

void ShowItem(Item *ItemX);                                     //YOU HAVE TO IMPLEMENT THIS
Item* CreateItem();                                             //YOU HAVE TO IMPLEMENT THIS

// ===========================================
// ==       ESSENCIAL BY DEFINITION         ==
// ===========================================
void Push(Stack **StackX, Item *ItemX);                         // ==== PUSH A NEW ITEM TO THE STACK ===
Item* Pop(Stack **StackX);                                      // ==== POP AN ITEM FROM THE STACK =====

// ===========================================
// ==      NOT ESSENCIAL BY DEFINITION      ==
// ==       BUT JUST REALLY REALLY COOL     ==
// ===========================================
Item* Peek(Stack **StackX);                                     // === PEEK THE TOP ITEM OF A STACK ==
void ShowStack(Stack **StackX);                                 // === SHOW ALL THE ELEMENTS OF A STACK == 

