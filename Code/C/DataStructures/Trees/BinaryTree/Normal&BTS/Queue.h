/*==========================================================
============= DECLARATION OF A QUEUE IN C    ===============
==========================================================*/

// =================================
// ==  TYPE OF DATA TO QUEUE      ==
// =================================
typedef struct {                                                	//=== DATA STRUCT ===
   Node *TreeNode;                                          		//For now just a simple number
} QueueItem;                                                        //We call this an item of our Queue

// =================================
// ==== DECLARATION OF A NODE    ===
// =================================
typedef struct QueueNode {                                          //=== NODE ===
   QueueItem *QueueNodeQueueItem;                                   //Pointer to the real data
   struct QueueNode *Next;                                          //Pointer to the next node
} QueueNode;                                                        //We call this struct a node

// =================================
// ==== DECLARATION OF A QUEUE   ===
// =================================
typedef struct {                                                	//=== QUEUE ===
   QueueNode *Front;                                                //Pointer to the front node
   QueueNode *Rear;                                                 //Pointer to the back node
} Queue;                                                        	//We call this struct a Queue

 
// =================================
// ==== SOME THINGS OF SYNTAXIS   ==
// =================================
#define GoNextQueueNode CurrentQueueNode=CurrentQueueNode->Next 	//This is what incrementing a QueueNode is :3



/*==========================================================
============ FUNTIONS OF A QUEUE IN C    ===================
==========================================================*/

// ===========================================
// ==      NOT ESSENCIAL BY DEFINITION      ==
// ==  BUT ESSENCIAL FOR MY IMPLEMENTATION  ==
// ===========================================
Queue* CreateQueue();                                           	// ==== CREATE-INITIALIZE A QUEUE =====
QueueNode* CreateQueueNode(QueueItem *NewQueueItem);                // ==== CREATE A NEW NODE OF A QUEUE ==

void ShowQueueItem(QueueItem *QueueItemX);                          //YOU HAVE TO IMPLEMENT THIS
QueueItem* CreateQueueItem(Node* SomeTreeNode);                    	//YOU HAVE TO IMPLEMENT THIS

// ===========================================
// ==       ESSENCIAL BY DEFINITION         ==
// ===========================================
void Enqueue(Queue *QueueX, QueueItem *QueueItemX);              	// ==== PUSH A NEW ITEM TO THE QUEUE ===
QueueItem* Dequeue(Queue *QueueX);                                  // ==== POP AN ITEM FROM THE QUEUE =====

// ===========================================
// ==      NOT ESSENCIAL BY DEFINITION      ==
// ==       BUT JUST REALLY REALLY COOL     ==
// ===========================================
QueueItem* QueuePeek(Queue *QueueX);                           		// === PEEK THE TOP ITEM OF A QUEUE ==
void ShowQueue(Queue *QueueX);                                  	// === SHOW ALL THE ELEMENTS OF A QUEUE == 

