/*
    INSTITUTO POLITÉCNICO NACIONAL
    ESCUELA SUPERIOR DE CÓMPUTO
    ESTRUCTURAS DE DATOS
    GRUPO: 1CV8
    ALUMNOS:
         Jose Manuel Ramirez Vivez
         Oscar Andrés Rosas

    PROFESOR: BENJAMÍN LUNA BENOSO
    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    ARCHIVO DE IMPLEMENTACION REGISTRO DE TEMPERATURA
    FECHA: 23 DE ABRIL
*/


/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
+++++++++     		DECLARATION OF A LINKED LIST IN C       	   ++++++++++++
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

// =================================
// ==  TYPE OF DATA TO LIST      ==
// =================================
typedef struct {                                                //=== DATA STRUCT ===
   int minuto;                                            		//minuto
   int hora;                                            		//hora
   int dia;                                            			//dia
   int mes;														//mes
   int año;														//año
} Fecha;       													//Esto es la fecha


typedef struct {                                                //=== DATA STRUCT ===
   int Temperatura;                                            	//Temperatura de este item
   Fecha *FechaDelItem;											//Fecha de esta temperatura
} Item;                                                         //We call this an item of our Stack

// =================================
// ==== DECLARATION OF A LIST   ===
// =================================
typedef struct Node {                                           //=== NODE ===
   Item *NodeItem;                                              //Pointer to the real data
   struct Node *Next;                                           //Pointer to the next node
   struct Node *Prev;                                           //Pointer to the previous node
} Node;                                                         //We call this struct a node
 
// =================================
// ==== SOME THINGS OF SYNTAXIS   ==
// =================================
#define Head (*ListX)                                         	//The head of a list is just the pointer
#define List Node                                              	//The list is just a Node at the end
#define GoNextNode CurrentNode=CurrentNode->Next                //This is what I mean when I increment a pointer
#define GoPrevNode CurrentNode=CurrentNode->Prev                //This is what I mean when I decrement a pointer
#define NextNode CurrentNode->Next                				//This is what I mean when I use a NextNode
#define PrevNode CurrentNode->Prev                				//This is what I mean when I use a PrevNode

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
int CompareItems(Item *A, Item *B);								//YOU HAVE TO IMPLEMENT THIS 0=equal 1=a big -1= b big

// ===========================================
// ==       ESSENCIAL BY DEFINITION         ==
// ===========================================

// =====  INSERT AN ELEMENT =====
void InsertAtHead(List **ListX, Item *ItemX);					// ==== INSERT AT THE HEAD OF THE LIST ==
void InsertAtTail(List **ListX, Item *ItemX);					// ==== INSERT AT THE TAIL OF THE LIST ==
void Insert(List **ListX, Item *ItemX, int Place);				// ==== INSERT AT POSITION OF THE LIST ==
void InsertSort(List **ListX, Item *ItemX);						// ==== INSERT IN ORDER OF THE LIST =====

// =====  ELIMINATE AN ELEMENT =====
Item* EliminateAtHead(List **ListX);							  // ==== ELIMINATE THE HEAD OF THE LIST ==
Item* EliminateAtTail(List **ListX);							  // ==== ELIMINATE THE TAIL OF THE LIST ==
Item* Eliminate(List **ListX, int Place);						  // ==== ELIMINATE POSITION OF THE LIST ==
Item* EliminateItem(List **ListX, Item *ItemX);					// ==== ELIMINATE AN ITEM OF THE LIST  ==
Item* EliminateNextNode(Node *CurrentNode);           			// ==== ELIMINATE A SPECIFIC NODE   =====

// ===========================================
// ==      NOT ESSENCIAL BY DEFINITION      ==
// ==       BUT JUST REALLY REALLY COOL     ==
// ===========================================
Item* Peek(List **ListX, int Place);							// ==== PEEK POSITION OF THE LIST ==
Item* PeekAtHead(List **ListX);									// ==== PEEK THE HEAD OF THE LIST ==
Item* PeekAtTail(List **ListX);									// ==== PEEK THE TAIL OF THE LIST ==
Item* PeekItem(List **ListX, Item *ItemX);						// ==== PEEK AN ITEM OF THE LIST  ==

void ShowList(List **ListX);                                 	// === SHOW ALL THE ELEMENTS OF A LIST == 
void Reverse(List **ListX);										// === REVERSE ALL THE POINTER OF A LIST ==

