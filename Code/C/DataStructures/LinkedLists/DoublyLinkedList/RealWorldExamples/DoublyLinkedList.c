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
++++++++++++++              LISTS FUNTIONS FILE            ++++++++++++++++++++
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include <stdio.h>                                              //Library that we are going to use
#include <stdlib.h>                                             //Library that we are going to use
#include <math.h>                                               //Library that we are going to use
#include <string.h>                                             //Library that we are going to use

#include "DoublyLinkedList.h"                                   //Our beloved List



/*==========================================================
============ FUNTIONS OF A LIST IN C     ===================
==========================================================*/

// ===========================================
// ==      NOT ESSENCIAL BY DEFINITION      ==
// ==  BUT ESSENCIAL FOR MY IMPLEMENTATION  ==
// ===========================================
List* CreateList(){                                             // ==== CREATE-INITIALIZE A LIST =====
    Node *NewNode = (Node*) malloc(sizeof(Node));               //Reserve memory for memory
    NewNode = NULL;                                             //Make ir point to NULL
    return NewNode;                                             //Go, you are now a list :')
}

Node* CreateNode(Item *NewItem){                                // ==== CREATE A NEW NODE OF A LIST ==
    Node *NewNode = (Node*) malloc(sizeof(Node));               //Reserve memory for memory
    NewNode->NodeItem = NewItem;                                //The info is there
    NewNode->Next = NULL;                                       //You are the last element
    NewNode->Prev = NULL;                                       //You are also the first element
    return NewNode;                                             //Go, you're complete
}


// ===========================================
// ==       ESSENCIAL BY DEFINITION         ==
// ===========================================

// ==============================
// =====  INSERT AN ELEMENT =====
// ==============================
void InsertAtHead(List **ListX, Item *ItemX){                   // ==== INSERT AT THE HEAD OF THE LIST ==
    Node *NewNode = CreateNode(ItemX);                          //Create a new node
    NewNode->Next = Head;                                       //This is what a head looks like
    NewNode->Prev = NULL;                                       //This is what a head looks like
    if (Head != NULL) Head->Prev = NewNode;                     //If we have elements also we have to give a prev to prev head
    Head = NewNode;                                             //Now, you are the head
}

void InsertAtTail(List **ListX, Item *ItemX){                   // ==== INSERT AT THE TAIL OF THE LIST ==
    Node *NewNode = CreateNode(ItemX);                          //Create a new node
    if (Head == NULL) {Head = NewNode; return;}                 //Empty list? NTP, we have only have to do one thing
    
    Node *CurrentNode = Head;                                   //Make it a counter
    while (NextNode != NULL) GoNextNode;                        //Go to the end and add the pointer
    NextNode = NewNode;                                         //The last element points to the newNode
    NewNode->Prev = CurrentNode;                                //And now the current node is almost the last, so it have a prev
}

void Insert(List **ListX, Item *ItemX, int Place){              // ==== INSERT AT POSITION OF THE LIST ==
    if(Place == 0) {InsertAtHead(ListX, ItemX); return;}        //Special case
    if (ListX == NULL || Place < 0) return;                     //Funny, very funny :/

    Node *CurrentNode = Head; int i;                            //Let's make a pointer to travel the list (and a i)
    for (i = 0; i < (Place-1); GoNextNode, i++)                 //Lets move until we are almost where we want
        if (CurrentNode == NULL) return;                        //If touch the end of the list

    Node *NewNode = CreateNode(ItemX);                          //Create a new node
    NewNode->Next = NextNode;                                   //I point to the list (all of after)
    NewNode->Prev = CurrentNode;                                //I point to the list (all of before)
    if (NextNode != NULL)NextNode->Prev = NewNode;              //The list (future) now point at me (if it can :D)
    NextNode = NewNode;                                         //The list now point at me (past)
}

void InsertSort(List **ListX, Item *ItemX){                     // ==== INSERT IN ORDER OF THE LIST =====
    if (ItemX == NULL) return;                                  //very funny :/ 
    if (Head == NULL) {InsertAtHead(ListX, ItemX); return;}     //Upps, special case

    if (CompareItems(ItemX,(Head->NodeItem)) < 1)               //Special case where it dont work
        {InsertAtHead(ListX, ItemX); return;}                   //So call something that do it

    if(Head->Next == NULL){InsertAtTail(ListX, ItemX); return;} //If you didnt fall in the last if 

    Node *CurrentNode = Head;                                   //Make it a counter
    while (CompareItems(ItemX,(NextNode->NodeItem)) == 1){      //While we didn't have found the pointer
        GoNextNode;                                             //Go next node please
        if (NextNode == NULL) break;                            //If we are at the end the list 
    }

    Node *NewNode = CreateNode(ItemX);                          //Create a new node
    NewNode->Next = NextNode;                                   //I point to the list (all of after)
    NewNode->Prev = CurrentNode;                                //I point to the list (all of before)
    if (NextNode != NULL)NextNode->Prev = NewNode;              //The list (future) now point at me (if it can :D)
    NextNode = NewNode;                                         //The list now point at me (past)
}

// ==============================
// ===  ELIMINATE AN ELEMENT ====
// ==============================
Item* EliminateAtHead(List **ListX){                            // ==== ELIMINATE THE HEAD OF THE LIST ==
    if(Head == NULL) return NULL;                               //Funny, very funny

    Node *NodeToEliminate = Head;                               //Save the node to eliminate
    Item *ItemToReturn = Head->NodeItem;                        //Save this too! 
    
    Head = NodeToEliminate->Next;                               //Now the 2nd element is the head of the list
    if (Head != NULL) Head->Prev = NULL;                        //And as a head, it should have this (If posible)
    free(NodeToEliminate);                                      //You are free my beloved pointer
    return ItemToReturn;                                        //Return this item
}

Item* EliminateAtTail(List **ListX){                            // ==== ELIMINATE THE TAIL OF THE LIST ==
    if(Head == NULL) return NULL;                               //Funny, very funny
    if(Head->Next == NULL) return EliminateAtHead(ListX);       //If you only have one item
    
    Node *CurrentNode = Head;                                   //Make it a counter
    while(NextNode->Next != NULL) GoNextNode;                   //Go to the end and add the pointer

    return EliminateNextNode(CurrentNode);                      //Now, just erase this and return me this value before
}

Item* Eliminate(List **ListX, int Place){                       // ==== ELIMINATE POSITION OF THE LIST ==
    if (Head == NULL || Place < 0) return NULL;                 //Funny, very funny :/
    if(Place == 0) return EliminateAtHead(ListX);               //If you want the top (special case)
    
    Node *CurrentNode = Head; int i = 0;                        //Make it a counter
    for (i = 0; i < (Place-1); GoNextNode, i++)                 //Find the Place
        if (NextNode == NULL) return NULL;                      //If we are at the end the list

    if (NextNode == NULL) return NULL;                          //If we are at the end the list (imposible if all ok)
    return EliminateNextNode(CurrentNode);                      //Now, just erase this and return me this value before
}

Item* EliminateItem(List **ListX, Item *ItemX){                 // ==== ELIMINATE AN ITEM OF THE LIST  ==
    if (Head == NULL || ItemX == NULL) return NULL;             //Funny, very funny :/             

    if (CompareItems((Head->NodeItem),ItemX) == 0)              //Special case where it dont work
        return EliminateAtHead(ListX);                          //So call something that do it

    Node *CurrentNode = Head;                                   //Make it a counter
    while (CompareItems((NextNode->NodeItem),ItemX) != 0){      //While we didn't have found the pointer
        GoNextNode;                                             //Go next node please
        if (NextNode == NULL) return NULL;                      //If we are at the end the list 
    }

    if (NextNode == NULL) return NULL;                          //If we are at the end the list (imposible if all ok)
    return EliminateNextNode(CurrentNode);                      //Now, just erase this and return me this value before
}

Item* EliminateNextNode(Node *CurrentNode){                     // ==== ELIMINATE A SPECIFIC NODE   =====
    if (CurrentNode == NULL) return NULL;                       //Also, very funny!
    Node *NodeToEliminate = NextNode;                           //Save the node to eliminate
    Item *ItemToReturn = NodeToEliminate->NodeItem;             //Save this too! 
    
    NextNode = NextNode->Next;                                  //The "nextnode" is going to die, so...
    if(NextNode != NULL) NextNode->Prev = CurrentNode;          //If we can, the next->back should be to us

    free(NodeToEliminate);                                      //You are free my beloved pointer
    return ItemToReturn;                                        //Return this item
}

// ===========================================
// ==      NOT ESSENCIAL BY DEFINITION      ==
// ==       BUT JUST REALLY REALLY COOL     ==
// ===========================================

// ==============================
// ===     PEEK AN ELEMENT   ====
// ==============================
Item* PeekAtHead(List **ListX){                                 // ==== PEEK THE HEAD OF THE LIST ==
    if (Head == NULL) return NULL;                              //Funny, very funny :/
    return Head->NodeItem;                                      //Please give me the item at the head
}

Item* PeekAtTail(List **ListX){                                 // ==== PEEK THE TAIL OF THE LIST ==
    if (Head == NULL) return NULL;                              //Funny, very funny :/
    Node *CurrentNode = Head;                                   //Make it a counter
    while(NextNode != NULL) GoNextNode;                         //Go to the end and add the pointer
    return CurrentNode->NodeItem;                               //Please give your info
}

Item* Peek(List **ListX, int Place){                            // ==== PEEK POSITION OF THE LIST ==
    if (Head == NULL || Place < 0) return NULL;                 //Funny, very funny :/  

    Node *CurrentNode = Head; int i = 0;                        //Make it a counter
    for (i = 0; i < Place; GoNextNode, i++)                     //Find the Place
        if (CurrentNode == NULL) return NULL;                   //If we are at the end the list

    return CurrentNode->NodeItem;                               //Return this item
}

Item* PeekItem(List **ListX, Item *ItemX){                      // ==== PEEK AN ITEM OF THE LIST  ==
    if (Head == NULL || ItemX == NULL) return NULL;             //Funny, very funny :/

    Node *CurrentNode = Head;                                   //Make it a counter
    while(CompareItems((CurrentNode->NodeItem),ItemX) != 0){    //Lets travel until the n element
        GoNextNode;                                             //Increment the pointer :3
        if (CurrentNode == NULL) return NULL;                   //If we end the list
    }
    return CurrentNode->NodeItem;                               //Please give your info
}

void ShowList(List **ListX){                                    // ==== SHOW ALL THE ELEMENTS OF A LIST =====
    if (Head == NULL) {ShowItem(NULL); return;}                 //Funny, very funny
    Node *CurrentNode = Head;                                   //Lets make a pointer to travel to the list
    
    for (; NextNode != NULL; GoNextNode)                        //Using a cool for loop, See List.h to know how to
        ShowItem(CurrentNode->NodeItem);                        //And for each Node, show me the info inside
    ShowItem(CurrentNode->NodeItem);                            //And also for the last one, but no increment please
}


void Reverse(List **ListX){                                     // === REVERSE ALL THE POINTER OF A LIST ==
    Node *TemporalNode, *CurrentNode = Head;                    //We will need this
    for (; NextNode != NULL; CurrentNode = TemporalNode){       //lets travel the list
        TemporalNode = NextNode;                                //Swap with a bucket
        NextNode = PrevNode;                                    //Swap with a bucket
        PrevNode = TemporalNode;                                //Swap with a bucket
    }                                                           
    TemporalNode = NextNode;                                    //Swap with a bucket
    NextNode = PrevNode;                                        //Swap with a bucket
    PrevNode = TemporalNode;                                    //Swap with a bucket

    Head = CurrentNode;                                         //You are the new head
}