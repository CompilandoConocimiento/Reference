/*==========================================================
============= DECLARATION OF A QUEUE IN C    ===============
==========================================================*/

// =================================
// ==  TYPE OF DATA TO QUEUE      ==
// =================================
typedef struct {                                                //=== DATA STRUCT ===
   int number;                                                  //For now just a simple number
} Item;                                                         //We call this an item of our Queue

// =================================
// ==== DECLARATION OF A NODE    ===
// =================================
typedef struct Node {                                           //=== NODE ===
   Item *NodeItem;                                              //Pointer to the real data
   struct Node *Next;                                           //Pointer to the next node
} Node;                                                         //We call this struct a node

// =================================
// ==== DECLARATION OF A QUEUE   ===
// =================================
typedef struct {                                                //=== QUEUE ===
   Node *Front;                                                 //Pointer to the front node
   Node *Rear;                                                  //Pointer to the back node
} Queue;                                                        //We call this struct a Queue

 
// =================================
// ==== SOME THINGS OF SYNTAXIS   ==
// =================================
#define GoNextNode CurrentNode=CurrentNode->Next                //This is what incrementing a Node is :3



/*==========================================================
============ FUNTIONS OF A QUEUE IN C    ===================
==========================================================*/

// ===========================================
// ==      NOT ESSENCIAL BY DEFINITION      ==
// ==  BUT ESSENCIAL FOR MY IMPLEMENTATION  ==
// ===========================================
Queue* CreateQueue();                                           // ==== CREATE-INITIALIZE A QUEUE =====
Node* CreateNode(Item *NewItem);                                // ==== CREATE A NEW NODE OF A QUEUE ==

void ShowItem(Item *ItemX);                                     //YOU HAVE TO IMPLEMENT THIS
Item* CreateItem();                                             //YOU HAVE TO IMPLEMENT THIS

// ===========================================
// ==       ESSENCIAL BY DEFINITION         ==
// ===========================================
void Enqueue(Queue *QueueX, Item *ItemX);                       // ==== PUSH A NEW ITEM TO THE QUEUE ===
Item* Dequeue(Queue *QueueX);                                   // ==== POP AN ITEM FROM THE QUEUE =====

// ===========================================
// ==      NOT ESSENCIAL BY DEFINITION      ==
// ==       BUT JUST REALLY REALLY COOL     ==
// ===========================================
Item* Peek(Queue *QueueX);                                      // === PEEK THE TOP ITEM OF A QUEUE ==
void ShowQueue(Queue *QueueX);                                  // === SHOW ALL THE ELEMENTS OF A QUEUE == 

