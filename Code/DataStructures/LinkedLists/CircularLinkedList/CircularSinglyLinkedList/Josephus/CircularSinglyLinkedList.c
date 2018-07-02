/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
++++++++++++++              LISTS FUNTIONS FILE            ++++++++++++++++++++
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include <stdio.h>                                              //Library that we are going to use
#include <stdlib.h>                                             //Library that we are going to use
#include <math.h>                                               //Library that we are going to use
#include <string.h>                                             //Library that we are going to use

#include "CircularSinglyLinkedList.h"                           //Our beloved List


/*==========================================================
============ FUNTIONS OF A LIST IN C    ===================
==========================================================*/

// ===========================================
// ==      NOT ESSENCIAL BY DEFINITION      ==
// ==  BUT ESSENCIAL FOR MY IMPLEMENTATION  ==
// ===========================================
List* CreateList(){                                             // ==== CREATE-INITIALIZE A STACK =====
    Node *NewList = (Node*) malloc(sizeof(Node));               //Reserve memory for memory
    NewList = NULL;                                             //You should point to yourself
    return NewList;                                             //Go, you are now a list :')
}

Node* CreateNode(Item *NewItem){                                // ==== CREATE A NEW NODE OF A STACK ==
    Node *NewNode = (Node*) malloc(sizeof(Node));               //Reserve memory for memory
    NewNode->NodeItem = NewItem;                                //The info is there
    NewNode->Next = NULL;                                       //(we will alway change this)
    return NewNode;                                             //Go, you're complete
}


// ===========================================
// ==       ESSENCIAL BY DEFINITION         ==
// ===========================================

// ==============================
// =====  INSERT AN ELEMENT =====
// ==============================

void InsertAtTail(List **ListX, Item *ItemX){                   // ==== INSERT AT THE TAIL OF THE LIST ==
    Node *NewNode = CreateNode(ItemX);                          //Create a new node

    if (Head == NULL){                                          //If there is nothing
        Head = NewNode;                                         //Get the info
        NewNode->Next = NewNode;                                //And bucle!
        return;                                                 //Lets return!
    }

    Node *CurrentNode = Head;                                   //Make it a counter
    while (NextNode != Head) GoNextNode;                        //Go to the end and add the pointer

    NextNode = NewNode;                                         //The next node is now the penultime node
    NewNode->Next = Head;                                       //And as a tail you should point to head
}

// ==============================
// ===  ELIMINATE AN ELEMENT ====
// ==============================
Item* EliminateNextNode(Node *CurrentNode){                     // ==== ELIMINATE A SPECIFIC NODE   =====
    Node *NodeToEliminate = NextNode;                           //Save the node to eliminate
    Item *ItemToReturn = NodeToEliminate->NodeItem;             //Save this too! 
    
    NextNode = NextNode->Next;                                  //The "nextnode" is going to die, so...

    free(NodeToEliminate);                                      //You are free my beloved pointer
    return ItemToReturn;                                        //Return this item
}

Item* EliminateItem(List **ListX, Item *ItemX){                 // ==== ELIMINATE AN ITEM OF THE LIST  ==
    if (Head == NULL || ItemX == NULL) return NULL;             //Funny, very funny :/             

    Node *CurrentNode = Head;                                   //You are a crawler

    if (CompareItems((CurrentNode->NodeItem),ItemX) == 0){      //Special Case ¡Head!
        for (; NextNode != Head; GoNextNode){}                  //Lets go to the last element!
        Head = NextNode->Next;                                  //Repair the head
        if (Head == NextNode) Head = NULL;                      //Special case if onely one element
        return EliminateNextNode(CurrentNode);                  //Eliminate it!
    }

    while( (NotAtStart) && (CompareItems(TwoItems) != 0) )      //Find we have not arrive
        GoNextNode;                                             //Keep going!

    if (NextNode == Head) return NULL;                          //But if you do not find anything
    return EliminateNextNode(CurrentNode);                      //Eliminate it!
}




// ===========================================
// ==      NOT ESSENCIAL BY DEFINITION      ==
// ==       BUT JUST REALLY REALLY COOL     ==
// ===========================================

void ShowList(List **ListX){                                    // ==== SHOW ALL THE ELEMENTS OF A LIST =====
    if (Head == NULL){ ShowItem(NULL); return; }

    Node *CurrentNode = Head;                                   //Lets make a pointer to travel to the stack

    for (; NextNode != Head ; GoNextNode){                      //Using a cool for loop, See Stack.h to know how to
        ShowItem(CurrentNode->NodeItem);                        //And for each Node, show me the info inside
    }
    ShowItem(CurrentNode->NodeItem);                            //And for each Node, show me the info inside
}

int EmptyList(List **ListX){                                    // ==== SHOW ALL THE ELEMENTS OF A LIST =====
    if (Head == NULL) return 1;                                 //if there are nothing
    return 0;                                                   
}

void SwipeList(List **ListX){                                   // ==== SWIPE THE ELEMENTS OF A LIST =====
    Head = Head->Next;
}



Item* PeekTop(List **ListX){
    return Head->NodeItem;
}


int Longitud(List **ListX){
    if (Head == NULL){ return 3; }
    int contador = 0;

    Node *CurrentNode = Head;                                   //Lets make a pointer to travel to the stack

    for (; NextNode != Head ; GoNextNode){                      //Using a cool for loop, See Stack.h to know how to
        contador += (3 + (strlen(CurrentNode->NodeItem->nombre)));     
    }
    contador += (3 + (strlen(CurrentNode->NodeItem->nombre)));    
    return contador;
}

