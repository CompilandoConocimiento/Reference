/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
++++++++++++++              STACK FUNTIONS FILE            ++++++++++++++++++++
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include <stdio.h>                                              //Library that we are going to use
#include <stdlib.h>                                             //Library that we are going to use
#include <math.h>                                               //Library that we are going to use
#include <string.h>                                             //Library that we are going to use

#include "Stack.h"                                              //Our beloved Stack


/*==========================================================
============ FUNTIONS OF A STACK IN C    ===================
==========================================================*/

// ===========================================
// ==      NOT ESSENCIAL BY DEFINITION      ==
// ==  BUT ESSENCIAL FOR MY IMPLEMENTATION  ==
// ===========================================
Stack* CreateStack(){                                           // ==== CREATE-INITIALIZE A STACK =====
    Node *NewNode = (Node*) malloc(sizeof(Node));               //Reserve memory for this node
    NewNode = NULL;                                             //Make it point to NULL
    return NewNode;                                             //return it!
}

Node* CreateNode(Item *NewItem){                                // ==== CREATE A NEW NODE OF A STACK ==
    Node *NewNode = (Node*) malloc(sizeof(Node));               //Reserve memory for this node
    NewNode->NodeItem = NewItem;                                //You will protect this info with your life
    NewNode->Next = NULL;                                       //And maybe you're the last element of the stack
    return NewNode;                                             //Go, go NewNode, you are complete :')
}


// ===========================================
// ==       ESSENCIAL BY DEFINITION         ==
// ===========================================
void Push(Stack **StackX, Item *ItemX){                         // ==== PUSH A NEW ITEM TO THE STACK ===
    Node *NewNode = CreateNode(ItemX);                          //Create a new node this this info
    NewNode->Next = Front;                                      //Point to the last Front, now is the 2nd element   
    Front = NewNode;                                            //And the new Front is just the NewNode
}

Item* Pop(Stack **StackX){                                      // ==== POP AN ITEM FROM THE STACK =====
    if (Front == NULL) return NULL;                             //If is empty I just can't do anything
    Node *NodeToEliminate = Front;                              //Goodbye Front, i will miss you
    Item *ItemAtFront = NodeToEliminate->NodeItem;              //But I will need this
    Front = NodeToEliminate->Next;                              //The Stack now start at the 2nd element
    free(NodeToEliminate);                                      //And free the memory of this thing
    return ItemAtFront;                                         //But maybe you will need this, so take it!
}

// ===========================================
// ==      NOT ESSENCIAL BY DEFINITION      ==
// ==       BUT JUST REALLY REALLY COOL     ==
// ===========================================
Item* Peek(Stack **StackX){                                      // === PEEK THE Front ITEM OF A STACK ==
    if (Front == NULL) return NULL;                              //If is empty I just can't do anything
    return (Front)->NodeItem;                                    //Else you need this, so take it!
}

void ShowStack(Stack **StackX){                                  // ==== SHOW ALL THE ELEMENTS OF A STACK =====
    Node *CurrentNode = Front;                                   //Lets make a pointer to travel to the stack
    for (CurrentNode = Front; CurrentNode != NULL; GoNextNode)   //Using a cool for loop, See Stack.h to know how to
        ShowItem(CurrentNode->NodeItem);                         //And for each Node, show me the info inside
}
