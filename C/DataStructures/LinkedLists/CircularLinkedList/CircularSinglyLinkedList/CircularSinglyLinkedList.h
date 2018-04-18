/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
+++++++++     		DECLARATION OF A LINKED LIST IN C       	   ++++++++++++
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

// =================================
// ==  TYPE OF DATA TO LIST      ==
// =================================
typedef struct {                                                //=== DATA STRUCT ===
   int number;                                                  //For now just a simple number
} Item;                                                         //We call this an item of our Stack

// =================================
// ==== DECLARATION OF A LIST   ===
// =================================
typedef struct Node {                                           //=== NODE ===
   Item *NodeItem;                                              //Pointer to the real data
   struct Node *Next;                                           //Pointer to the next node
} Node;                                                         //We call this struct a node
 
// =================================
// ==== SOME THINGS OF SYNTAXIS   ==
// =================================
#define Head (*ListX)                                         	//The head of a list is just the pointer
#define List Node                                              	//The list is just a Node at the end
#define GoNextNode CurrentNode=CurrentNode->Next                //This is what I mean when I increment a pointer
#define NextNode CurrentNode->Next                				//This is what I mean when I use a NextNode
#define NotAtStart CurrentNode->Next!=(*ListX)                	//This is not the start
#define TwoItems (NextNode->NodeItem),ItemX				        //Are we at the correct item

/*==========================================================
============ FUNTIONS OF A LIST IN C    ===================
==========================================================*/

// ===========================================
// ==      NOT ESSENCIAL BY DEFINITION      ==
// ==  BUT ESSENCIAL FOR MY IMPLEMENTATION  ==
// ===========================================
List* CreateList();                                             // ==== CREATE-INITIALIZE A LIST =====
Node* CreateNode(Item *NewItem);                                // ==== CREATE A NEW NODE OF A LIST ==

void ShowItem(Item *ItemX);                                     //YOU HAVE TO IMPLEMENT THIS
Item* CreateItem();                                             //YOU HAVE TO IMPLEMENT THIS
int CompareItems(Item *A, Item *B);								//YOU HAVE TO IMPLEMENT THIS 1=IGUAL 0=NOT

// ===========================================
// ==       ESSENCIAL BY DEFINITION         ==
// ===========================================

// =====  INSERT AN ELEMENT =====
void InsertAtTail(List **ListX, Item *ItemX);					// ==== INSERT AT THE TAIL OF THE LIST ==

// =====  ELIMINATE AN ELEMENT =====
Item* EliminateItem(List **ListX, Item *ItemX);					// ==== ELIMINATE AN ITEM OF THE LIST  ==
Item* EliminateNextNode(Node *CurrentNode);           			// ==== ELIMINATE A SPECIFIC NODE   =====

// ===========================================
// ==      NOT ESSENCIAL BY DEFINITION      ==
// ==       BUT JUST REALLY REALLY COOL     ==
// ===========================================
void ShowList(List **ListX);                                 	// === SHOW ALL THE ELEMENTS OF A LIST == 
int EmptyList(List **ListX);
void SwipeList(List **ListX);


