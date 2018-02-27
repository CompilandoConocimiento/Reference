/*==========================================================
============= DECLARATION OF A STACK IN C    ===============
==========================================================*/
// =================================
// ==  TYPE OF DATA TO STACK      ==
// =================================
typedef struct {                                                		//=== DATA STRUCT ===
   Node *TreeNode;                                          			//For now just a simple number
} StackItem;                                                         	//We call this an item of our Stack

// =================================
// ==== DECLARATION OF A STACK   ===
// =================================
typedef struct StackNode {                                           	//=== NODE ===
   StackItem *StackNodeStackItem;                                   	//Pointer to the real data
   struct StackNode *Next;                                           	//Pointer to the next node
} StackNode;                                                         	//We call this struct a node



// =================================
// ==== SOME THINGS OF SYNTAXIS   ==
// =================================
#define Front *StackX                                          	 		//The head of a stack is just the stack Pointer
#define Stack StackNode                                              	//At the end a stack is just a node
#define GoNextStackNode CurrentStackNode=CurrentStackNode->Next        	//This is what incrementing a StackNode is :3



/*==========================================================
============ FUNTIONS OF A STACK IN C    ===================
==========================================================*/

// ===========================================
// ==      NOT ESSENCIAL BY DEFINITION      ==
// ==  BUT ESSENCIAL FOR MY IMPLEMENTATION  ==
// ===========================================
Stack* CreateStack();                                           		// ==== CREATE-INITIALIZE A STACK =====
StackNode* CreateStackNode(StackItem *NewStackItem);                   	// ==== CREATE A NEW NODE OF A STACK ==

StackItem* CreateStackItem(Node* TreeNode);                             //YOU HAVE TO IMPLEMENT THIS
void ShowStackItem(StackItem *StackItemX);								//YOU HAVE TO IMPLEMENT THIS

// ===========================================
// ==       ESSENCIAL BY DEFINITION         ==
// ===========================================
void Push(Stack **StackX, StackItem *StackItemX);                     	// ==== PUSH A NEW ITEM TO THE STACK ===
StackItem* Pop(Stack **StackX);                                      	// ==== POP AN ITEM FROM THE STACK =====

// ===========================================
// ==      NOT ESSENCIAL BY DEFINITION      ==
// ==       BUT JUST REALLY REALLY COOL     ==
// ===========================================
StackItem* Peek(Stack **StackX);                                     	// === PEEK THE TOP ITEM OF A STACK ==
void ShowStack(Stack **StackX);                                 		// === SHOW ALL THE ELEMENTS OF A STACK == 
void ShowInverseStack(Stack ** StackX);									// ==== SHOW ALL THE ELEMENTS OF A STACK =====