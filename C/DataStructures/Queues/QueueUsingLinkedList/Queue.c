/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
++++++++++++++              QUEUE FUNTIONS FILE            ++++++++++++++++++++
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include <stdio.h>                                              //Library that we are going to use
#include <stdlib.h>                                             //Library that we are going to use
#include <math.h>                                               //Library that we are going to use
#include <string.h>                                             //Library that we are going to use

#include "Queue.h"                                              //Our beloved Queue


/*==========================================================
============ FUNTIONS OF A QUEUE IN C    ===================
==========================================================*/

// ===========================================
// ==      NOT ESSENCIAL BY DEFINITION      ==
// ==  BUT ESSENCIAL FOR MY IMPLEMENTATION  ==
// ===========================================
Queue* CreateQueue(){                                           // ==== CREATE-INITIALIZE A QUEUE =====
    Queue *NewQueue = (Queue*) malloc(sizeof(Queue));           //Reserve memory for this Queue
    NewQueue->Front = NULL;                                     //Make it point to NULL
    NewQueue->Rear = NULL;                                      //Make it point to NULL
    return NewQueue;                                            //return it!
}

Node* CreateNode(Item *NewItem){                                // ==== CREATE A NEW NODE OF A QUEUE ==
    Node *NewNode = (Node*) malloc(sizeof(Node));               //Reserve memory for this node
    NewNode->NodeItem = NewItem;                                //You will protect this info with your life
    NewNode->Next = NULL;                                       //And maybe you're the last element of the Queue
    return NewNode;                                             //Go, go NewNode, you are complete :')
}


// ===========================================
// ==       ESSENCIAL BY DEFINITION         ==
// ===========================================
void Enqueue(Queue *QueueX, Item *ItemX){                       // ==== PUSH A NEW ITEM TO THE QUEUE ===
    Node *NewNode = CreateNode(ItemX);                          //Create a new node this this info

    if (QueueX->Front == NULL)                                  //If our Queue front is empty
        QueueX->Front = QueueX->Rear = NewNode;                 //Everything point to the NewItem, after all it's the only one
    else {                                                      //If there it something there
        QueueX->Rear->Next = NewNode;                           //Add the item at the back
        QueueX->Rear = NewNode;                                 //And make the rear point at me NewNode
    }
}

Item* Dequeue(Queue *QueueX){                                   // ==== POP AN ITEM FROM THE QUEUE =====
    Node *NodeToEliminate;                                      //This is just for keep the adress of the info
    if (QueueX->Front == NULL) return NULL;                     //If it's empty I can't do anything

    NodeToEliminate = QueueX->Front;                            //If not, then I have to remove the Front of the Queue
    QueueX->Front = QueueX->Front->Next;                        //And make the new Front my 2nd element

    if (QueueX->Front == NULL)  QueueX->Rear = NULL;            //If I had no items left make ALL point at NULL
    Item *ItemtoDequeue = NodeToEliminate->NodeItem;            //But I will need this
    free(NodeToEliminate);                                      //And free the memory of this thing
    return ItemtoDequeue;                                       //But maybe you will need this, so take it!
}

// ===========================================
// ==      NOT ESSENCIAL BY DEFINITION      ==
// ==       BUT JUST REALLY REALLY COOL     ==
// ===========================================

void ShowQueue(Queue *QueueX){                                  // ==== SHOW ALL THE ELEMENTS OF A QUEUE =====
    Node *CurrentNode = QueueX->Front;                          //Lets make a pointer to travel to the Queue
    for (CurrentNode=CurrentNode;CurrentNode!=NULL;GoNextNode)  //Using a cool for loop, See Queue.h to know how to
        ShowItem(CurrentNode->NodeItem);                        //And for each Node, show me the info inside
}

Item* Peek(Queue *QueueX){                                      // ==== PEEK AN ITEM FROM THE QUEUE =====
    if (QueueX->Front == NULL) return NULL;                     //If it's empty I can't do anything
    return QueueX->Front->NodeItem;                             //Otherwhise, just take the Front element
}

