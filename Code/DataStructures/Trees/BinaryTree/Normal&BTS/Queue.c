/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
++++++++++++++              QUEUE FUNTIONS FILE            ++++++++++++++++++++
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include <stdio.h>                                                                  //Library that we are going to use
#include <stdlib.h>                                                                 //Library that we are going to use
#include <math.h>                                                                   //Library that we are going to use
#include <string.h>                                                                 //Library that we are going to use
#include "BinaryTree.h"                                                             //Our beloved Binary Tree

#include "Queue.h"                                                                  //Our beloved Queue


/*==========================================================
============ FUNTIONS OF A QUEUE IN C    ===================
==========================================================*/

// ===========================================
// ==      NOT ESSENCIAL BY DEFINITION      ==
// ==  BUT ESSENCIAL FOR MY IMPLEMENTATION  ==
// ===========================================
Queue* CreateQueue(){                                                               // ==== CREATE-INITIALIZE A QUEUE =====
    Queue *NewQueue = (Queue*) malloc(sizeof(Queue));                               //Reserve memory for this Queue
    NewQueue->Front = NULL;                                                         //Make it point to NULL
    NewQueue->Rear = NULL;                                                          //Make it point to NULL
    return NewQueue;                                                                //return it!
}

QueueNode* CreateQueueNode(QueueItem *NewQueueItem){                                // ==== CREATE A NEW NODE OF A QUEUE ==
    QueueNode *NewQueueNode = (QueueNode*) malloc(sizeof(QueueNode));               //Reserve memory for this node
    NewQueueNode->QueueNodeQueueItem = NewQueueItem;                                //You will protect this info with your life
    NewQueueNode->Next = NULL;                                                      //And maybe you're the last element of the Queue
    return NewQueueNode;                                                            //Go, go NewQueueNode, you are complete :')
}


// ===========================================
// ==       ESSENCIAL BY DEFINITION         ==
// ===========================================
void Enqueue(Queue *QueueX, QueueItem *QueueItemX){                                 // ==== PUSH A NEW ITEM TO THE QUEUE ===
    QueueNode *NewQueueNode = CreateQueueNode(QueueItemX);                          //Create a new node this this info

    if (QueueX->Front == NULL)                                                      //If our Queue front is empty
        QueueX->Front = QueueX->Rear = NewQueueNode;                                //Everything point to the NewQueueItem, after all it's the 1
    else {                                                                          //If there it something there
        QueueX->Rear->Next = NewQueueNode;                                          //Add the item at the back
        QueueX->Rear = NewQueueNode;                                                //And make the rear point at me NewQueueNode
    }
}

QueueItem* Dequeue(Queue *QueueX){                                                  // ==== POP AN ITEM FROM THE QUEUE =====
    QueueNode *QueueNodeToEliminate;                                                //This is just for keep the adress of the info
    if (QueueX->Front == NULL) return NULL;                                         //If it's empty I can't do anything

    QueueNodeToEliminate = QueueX->Front;                                           //If not, then I have to remove the Front of the Queue
    QueueX->Front = QueueX->Front->Next;                                            //And make the new Front my 2nd element

    if (QueueX->Front == NULL)  QueueX->Rear = NULL;                                //If I had no items left make ALL point at NULL
    QueueItem *QueueItemtoDequeue = QueueNodeToEliminate->QueueNodeQueueItem;       //But I will need this
    free(QueueNodeToEliminate);                                                     //And free the memory of this thing
    return QueueItemtoDequeue;                                                      //But maybe you will need this, so take it!
}

// ===========================================
// ==      NOT ESSENCIAL BY DEFINITION      ==
// ==       BUT JUST REALLY REALLY COOL     ==
// ===========================================

void ShowQueue(Queue *QueueX){                                                      // ==== SHOW ALL THE ELEMENTS OF A QUEUE =====
    QueueNode *CurrentQueueNode = QueueX->Front;                                    //Lets make a pointer to travel to the Queue
    for (CurrentQueueNode=CurrentQueueNode;CurrentQueueNode!=NULL;GoNextQueueNode)  //Using a cool for loop, See Queue.h to know how to
        ShowQueueItem(CurrentQueueNode->QueueNodeQueueItem);                        //And for each QueueNode, show me the info inside
}

QueueItem* QueuePeek(Queue *QueueX){                                                // ==== PEEK AN ITEM FROM THE QUEUE =====
    if (QueueX->Front == NULL) return NULL;                                         //If it's empty I can't do anything
    return QueueX->Front->QueueNodeQueueItem;                                       //Otherwhise, just take the Front element
}

