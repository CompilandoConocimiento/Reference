/*==========================================================
=====   DECLARATION OF A QUEUE USING AN ARRAY IN C    ======
==========================================================*/


// =================================
// ==  TYPE OF DATA TO QUEUE      ==
// =================================
typedef struct {                                                //=== DATA STRUCT ===
   int number;                                                  //For now just a simple number
} Item;                                                         //We call this an item of our Queue

// =================================
// ==== DECLARATION OF A QUEUE   ===
// =================================
#define CAPACITY 7                                              //Max Size of the Queue
typedef struct {                                                //=== QUEUE ===
    Item* QueueArray[CAPACITY];                                 //An array to store all the pointer to the info
    int PointerToFront;                                         //Simple pointer to index at the top
    int PointerToRear;                                          //Simple pointer to index at the back
} Queue;                                                        //We call this struct a node
 

// =================================
// ==== SOME THINGS OF SYNTAXIS   ==
// =================================
#define Front QueueX->PointerToFront                            //The Front of a Queue is just the this
#define Rear QueueX->PointerToRear                           	//The Rear of a Queue is just the this


/*==========================================================
============ FUNTIONS OF A QUEUE IN C    ===================
==========================================================*/
// ===========================================
// ==      NOT ESSENCIAL BY DEFINITION      ==
// ==  BUT ESSENCIAL FOR MY IMPLEMENTATION  ==
// ===========================================
void CreateQueue(Queue *QueueX);                                // ==== CREATE-INITIALIZE A QUEUE =====
int EmptyQueue(Queue *QueueX);                                  // ==== CHECK IF A QUEUE IS EMPTY =====
int FullQueue(Queue *QueueX);                                   // ===== CHECK IF A QUEUE IS FULL ======

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
void ShowQueue(Queue QueueX);                                  	// === SHOW ALL THE ELEMENTS OF A QUEUE == 
int ShowFreeSpace(Queue *QueueX);                           	// ==== SHOW FREE SPACES OF A QUEUE =====
