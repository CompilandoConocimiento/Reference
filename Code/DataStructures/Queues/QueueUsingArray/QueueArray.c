/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
++++++++++++++              QUEUE FUNTIONS FILE            ++++++++++++++++++++
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include <stdio.h>                                              //Library that we are going to use
#include <stdlib.h>                                             //Library that we are going to use
#include <math.h>                                               //Library that we are going to use
#include <string.h>                                             //Library that we are going to use

#include "QueueArray.h"                                         //Our beloved Queue


/*==========================================================
============ FUNTIONS OF A QUEUE IN C    ===================
==========================================================*/

// ===========================================
// ==      NOT ESSENCIAL BY DEFINITION      ==
// ==  BUT ESSENCIAL FOR MY IMPLEMENTATION  ==
// ===========================================
void CreateQueue(Queue *QueueX){                                // ==== CREATE-INITIALIZE A QUEUE =====
    Front = -1;                                                 //We dont have any info, so we are below 0
    Rear = -1;                                                  //We dont have any info, so we are below 0
}

int EmptyQueue(Queue *QueueX){                                  // ==== CHECK IF A QUEUE IS EMPTY =====
    if (Front == -1) return 1;                                  //If the pointer points to -1, yes, it's empty 
    return 0;                                                   //If you reach here, sorry, you are not empty
}

int FullQueue(Queue *QueueX){                                   // ==== CHECK IF A QUEUE IS FULL =====
    if (Front == (Rear + 1) ) return 1;                         //If we're at 1 to touch each other, then I'm full
    if ((Rear == (CAPACITY-1)) && (Front == 0)) return 1;       //If there are there im also full  
    
    return 0;                                                   //If you reach here, sorry, you are not full
}

// ===========================================
// ==       ESSENCIAL BY DEFINITION         ==
// ===========================================
void Enqueue(Queue *QueueX, Item *ItemX){                       // ==== PUSH A NEW ITEM TO THE QUEUE ===
    if(FullQueue(QueueX)) return;                               //If you're full sorry but bye
    if(Front == -1) Front = 0;                                  //If there were no data, there are now data

    Rear = (Rear+1) % CAPACITY;                                 //This is the adress of the new last element
    QueueX->QueueArray[Rear] = ItemX;                           //And there we should store this info
}

Item* Dequeue(Queue *QueueX){                                   // ==== POP AN ITEM FROM THE QUEUE =====
    if(EmptyQueue(QueueX)) return NULL;                         //If you're empty sorry but bye 

    Item *ItemDequeue = QueueX->QueueArray[Front];              //We will need this

    if (Rear == Front) Rear = Front = -1;                       //If there are no more data, return to the beginning
    else Front = (Front+1) % CAPACITY;                          //We move the head of the Queue

    return ItemDequeue;                                         //Regresamos el elemento
}



// ===========================================
// ==      NOT ESSENCIAL BY DEFINITION      ==
// ==       BUT JUST REALLY REALLY COOL     ==
// ===========================================
Item* Peek(Queue *QueueX){                                      // === PEEK THE TOP ITEM OF A QUEUE ==
    if(EmptyQueue(QueueX)) return NULL;                         //If you're empty sorry but bye  
    return QueueX->QueueArray[Front];                           //At least return the value of whatever was there
}

void ShowQueue(Queue QueueX){                                   // ==== SHOW ALL THE ELEMENTS OF A QUEUE =====
    if (EmptyQueue(&QueueX) == 0){                              //As long as it is not empty
        ShowItem(Dequeue(&QueueX));                             //We show the Front of the Queue
        ShowQueue(QueueX);                                      //And now awesome recursion!
    }                
}

int ShowFreeSpace(Queue *QueueX){                               // ==== SHOW FREE SPACES OF A QUEUE =====
    return CAPACITY - (Front + 1);                              //This determine our free space
}