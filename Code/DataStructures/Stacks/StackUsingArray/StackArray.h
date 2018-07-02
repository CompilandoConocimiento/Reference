/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
+++++++++     DECLARATION OF A STACK USING AN ARRAY IN C           ++++++++++++
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

// =================================
// ==  TYPE OF DATA TO STACK      ==
// =================================
typedef struct {                                                //=== DATA STRUCT ===
   int number;                                                  //For now just a simple number
} Item;                                                         //We call this an item of our Stack

// =================================
// ==== DECLARATION OF A STACK   ===
// =================================
#define CAPACITY 7                                              //Max Size of the Stack
typedef struct {                                                //=== STACK ===
    Item* StackArray[CAPACITY];                                 //An array to store all the pointer to the info
    int PointerToFront;                                         //Simple pointer to index at the top
} Stack;                                                        //We call this struct a node
 
// =================================
// ==== SOME THINGS OF SYNTAXIS   ==
// =================================
#define Front StackX->PointerToFront                           	//The Front of a stack is just this 

/*==========================================================
============ FUNTIONS OF A STACK IN C    ===================
==========================================================*/

// ===========================================
// ==      NOT ESSENCIAL BY DEFINITION      ==
// ==  BUT ESSENCIAL FOR MY IMPLEMENTATION  ==
// ===========================================
void CreateStack(Stack *StackX);                               // ==== CREATE-INITIALIZE A STACK =====
int EmptyStack(Stack *StackX);                                 // ==== CHECK IF A STACK IS EMPTY =====
int FullStack(Stack *StackX);                                  // ===== CHECK IF A STACK IS FULL ======

void ShowItem(Item *ItemX);                                     //YOU HAVE TO IMPLEMENT THIS
Item* CreateItem();                                             //YOU HAVE TO IMPLEMENT THIS

// ===========================================
// ==       ESSENCIAL BY DEFINITION         ==
// ===========================================
void Push(Stack *StackX, Item *ItemX);                          // ==== PUSH A NEW ITEM TO THE STACK ===
Item* Pop(Stack *StackX);                                       // ==== POP AN ITEM FROM THE STACK =====

// ===========================================
// ==      NOT ESSENCIAL BY DEFINITION      ==
// ==       BUT JUST REALLY REALLY COOL     ==
// ===========================================
Item* Peek(Stack *StackX);                                      // === PEEK THE TOP ITEM OF A STACK ==
void ShowStack(Stack *StackX);                                  // === SHOW ALL THE ELEMENTS OF A STACK == 
int ShowFreeSpace(Stack *StackX);                               // ==== SHOW FREE SPACES OF A STACK =====


