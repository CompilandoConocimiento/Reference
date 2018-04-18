/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
++++++++++++++              STACK FUNTIONS FILE            ++++++++++++++++++++
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include <stdio.h>                                              //Library that we are going to use
#include <stdlib.h>                                             //Library that we are going to use
#include <math.h>                                               //Library that we are going to use
#include <string.h>                                             //Library that we are going to use

#include "StackArray.h"                                         //Our beloved Stack


/*==========================================================
============ FUNTIONS OF A STACK IN C    ===================
==========================================================*/

// ===========================================
// ==      NOT ESSENCIAL BY DEFINITION      ==
// ==  BUT ESSENCIAL FOR MY IMPLEMENTATION  ==
// ===========================================
void CreateStack(Stack *StackX){                                // ==== CREATE-INITIALIZE A STACK =====
    Front = -1;                                                 //We dont have any info, so we are below 0
}

int EmptyStack(Stack *StackX){                                  // ==== CHECK IF A STACK IS EMPTY =====
    if (Front == -1) return 1;                                  //If the pointer points to -1, yes, it's empty 
    return 0;                                                   //If you reach here, sorry, you are not empty
}

int FullStack(Stack *StackX){                                   // ==== CHECK IF A STACK IS FULL =====
    if (Front == (CAPACITY-1)) return 1;                        //If the pointer is at the last index of array
    return 0;                                                   //If you reach here, sorry, you are not full
}

// ===========================================
// ==       ESSENCIAL BY DEFINITION         ==
// ===========================================
void Push(Stack *StackX, Item *ItemX){                          // ==== PUSH A NEW ITEM TO THE STACK ===
    if(FullStack(StackX)) return;                               //If you're full sorry but bye
    Front++;                                                    //Increment the pointer
    StackX->StackArray[Front] = ItemX;                          //Place the new data where it belongs
}

Item* Pop(Stack *StackX){                                       // ==== POP AN ITEM FROM THE STACK =====
    if(EmptyStack(StackX)) return NULL;                         //If you're empty sorry but bye 
    Front--;                                                    //Decrement the pointer   
    return StackX->StackArray[(Front)+1];                       //At least return the value of whatever was there
}



// ===========================================
// ==      NOT ESSENCIAL BY DEFINITION      ==
// ==       BUT JUST REALLY REALLY COOL     ==
// ===========================================
Item* Peek(Stack *StackX){                                      // === PEEK THE TOP ITEM OF A STACK ==
    if(EmptyStack(StackX)) return NULL;                         //If you're empty sorry but bye   
    return StackX->StackArray[Front];                           //At least return the value of whatever was there
}

void ShowStack(Stack *StackX){                                  // ==== SHOW ALL THE ELEMENTS OF A STACK =====
    int i;                                                      //Our little variable
    for (i = Front; i > -1; i--)                                //Recorre la Pila              
        ShowItem(StackX->StackArray[i]);                        //And for each Node, show me the info inside
}

int ShowFreeSpace(Stack *StackX){                               // ==== SHOW FREE SPACES OF A STACK =====
    return CAPACITY - (Front + 1);                              //This determine our free space
}


