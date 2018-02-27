/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
++++++++++++++              STACK FUNTIONS FILE            ++++++++++++++++++++
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include <stdio.h>                                                              //Library that we are going to use
#include <stdlib.h>                                                             //Library that we are going to use
#include <math.h>                                                               //Library that we are going to use
#include <string.h>                                                             //Library that we are going to use
#include "BinaryTree.h"                                                         //Our beloved Binary Tree
#include "Stack.h"                                                              //Our beloved Stack


/*==========================================================
============ FUNTIONS OF A STACK IN C    ===================
==========================================================*/

// ===========================================
// ==      NOT ESSENCIAL BY DEFINITION      ==
// ==  BUT ESSENCIAL FOR MY IMPLEMENTATION  ==
// ===========================================
Stack* CreateStack(){                                                           // ==== CREATE-INITIALIZE A STACK =====
    StackNode *NewStackNode = (StackNode*) malloc(sizeof(StackNode));           //Reserve memory for this node
    NewStackNode = NULL;                                                        //Make it point to NULL
    return NewStackNode;                                                        //return it!
}

StackNode* CreateStackNode(StackItem *NewStackItem){                            // ==== CREATE A NEW NODE OF A STACK ==
    StackNode *NewStackNode = (StackNode*) malloc(sizeof(StackNode));           //Reserve memory for this node
    NewStackNode->StackNodeStackItem = NewStackItem;                            //You will protect this info with your life
    NewStackNode->Next = NULL;                                                  //And maybe you're the last element of the stack
    return NewStackNode;                                                        //Go, go NewStackNode, you are complete :')
}


// ===========================================
// ==       ESSENCIAL BY DEFINITION         ==
// ===========================================
void Push(Stack **StackX, StackItem *StackItemX){                               // ==== PUSH A NEW ITEM TO THE STACK ===
    StackNode *NewStackNode = CreateStackNode(StackItemX);                      //Create a new node this this info
    NewStackNode->Next = Front;                                                 //Point to the last Front, now is the 2nd element   
    Front = NewStackNode;                                                       //And the new Front is just the NewStackNode
}

StackItem* Pop(Stack **StackX){                                                 // ==== POP AN ITEM FROM THE STACK =====
    if (Front == NULL) return NULL;                                             //If is empty I just can't do anything
    StackNode *StackNodeToEliminate = Front;                                    //Goodbye Front, i will miss you
    StackItem *StackItemAtFront = StackNodeToEliminate->StackNodeStackItem;                    //But I will need this
    Front = StackNodeToEliminate->Next;                                         //The Stack now start at the 2nd element
    free(StackNodeToEliminate);                                                 //And free the memory of this thing
    return StackItemAtFront;                                                    //But maybe you will need this, so take it!
}

// ===========================================
// ==      NOT ESSENCIAL BY DEFINITION      ==
// ==       BUT JUST REALLY REALLY COOL     ==
// ===========================================
StackItem* Peek(Stack **StackX){                                                // === PEEK THE Front ITEM OF A STACK ==
    if (Front == NULL) return NULL;                                             //If is empty I just can't do anything
    return (Front)->StackNodeStackItem;                                         //Else you need this, so take it!
}

void ShowStack(Stack **StackX){                                                 // ==== SHOW ALL THE ELEMENTS OF A STACK =====
    StackNode *CurrentStackNode = Front;                                        //Lets make a pointer to travel to the stack
    for (CurrentStackNode = Front; CurrentStackNode != NULL; GoNextStackNode)   //Using a cool for loop, See Stack.h to know how to
        ShowStackItem(CurrentStackNode->StackNodeStackItem);                    //And for each Node, show me the info inside
}

void ShowInverseStack(Stack ** StackX){                                         // ==== SHOW ALL THE ELEMENTS OF A STACK =====
    Stack *NewStack = NULL;                                                     //Start a new stack

    StackNode *CurrentStackNode = Front;                                        //Lets make a pointer to travel to the stack
    for (CurrentStackNode = Front; CurrentStackNode != NULL; GoNextStackNode)   //Using a cool for loop, See Stack.h to know how to
        Push(&NewStack, CurrentStackNode->StackNodeStackItem);                  //Push this
    ShowStack(&NewStack);                                                       //Show the info
}

