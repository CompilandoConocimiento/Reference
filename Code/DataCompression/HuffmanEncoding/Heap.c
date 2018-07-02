/*===================================================================
==================    PRIORITY QUEUE - HEAP     =====================
===================================================================*/
/**
 * @author  Rosas Hernandez Oscar Andres
 * @author  Alan Enrique Ontiveros Salazar
 * @author  Laura Andrea Morales 
 * @version 0.1
 * @team    CompilandoConocimiento
 * @date    1/06/2018
 */
#include <stdio.h>                                                                  //Put library
#include <stdlib.h>                                                                 //Put library
#include <limits.h>                                                                 //Put library

/*=============================================
============     NODE & HEAP        ===========
=============================================*/
typedef struct MinHeap {                                                            //Create a MinHeap type
    Node** Data;                                                                    //The data
    unsigned int Capacity;                                                          //And Now the capacity
    unsigned int CurrentSize;                                                       //Now the current size
} MinHeap;                                                                          //We will call it MinMinHeap

/*=============================================
============     ESSENCIAL          ===========
=============================================*/
void Initialize(MinHeap * Heap, int Capacity);                                      //Function Definition
void Insert(MinHeap* Heap, Node* Element);                                          //Function Definition
void MakeMinHeapFromArray(MinHeap* Heap, Node** Data, int DataSize);                //Function Definition
void Heapify(MinHeap* Heap, int i);                                                 //Function Definition
void Destroy(MinHeap * Heap);                                                       //Function Definition
Node* ExtractMin(MinHeap * Heap);                                                   //Function Definition

/*=============================================
============     HELPERS            ===========
=============================================*/
int Left(int i)   {return (i << 1) + 1;}                                            //Where is the left node 
int Right(int i)  {return (i << 1) + 2;}                                            //Where is the right node
int Parent(int i) {return (i - 1) >> 1;}                                            //Where is the parent node
    
Node* GetMin(MinHeap * Heap) {return Heap->Data[0];}                                //Get the minimun of Heap
int GetSize(MinHeap* Heap)   {return Heap->CurrentSize;}                            //Get the size
int Bigger(Node* A, Node* B) {return A->Frequency < B->Frequency;}                  //Select who is better
void Swap(Node* A, Node* B)  {Node Temporal = *A; *A = *B; *B = Temporal;}          //Swap 2 nodes
int MySonIsSmaller(MinHeap* H, int i) {                                             //Check: my son is < than me
    return Bigger(H->Data[i], H->Data[Parent(i)]);                                  //Using comparations
}

/*=============================================
============     ESSENCIAL          ===========
=============================================*/
void Initialize(MinHeap* Heap, int Capacity) {                                      //Create the Heap
    Heap->Capacity = Capacity;                                                      //Get the capacity
    Heap->CurrentSize = 0;                                                          //Now 1 have nothing
    Heap->Data = (Node**) calloc(Capacity, sizeof(Node*));                          //Create the data
}

void Destroy(MinHeap* Heap) {                                                       //Destroy the Heap
    for (int i = 0; i < Heap->CurrentSize; ++i) free(Heap->Data[i]);                //Destroy all the nodes data
    free(Heap->Data);                                                               //And the array
    free(Heap);                                                                     //And the struct
}

Node* ExtractMin(MinHeap * Heap) {                                                  //Extract the minimun
    Node* Element = Heap->Data[0];                                                  //Now save the element

    Heap->Data[0] = Heap->Data[Heap->CurrentSize - 1];                              //Put a new value
    Heap->CurrentSize--;                                                            //Remove in size

    Heapify(Heap, 0);                                                               //Call Heapify
    return Element;                                                                 //Now return the element
}

void Insert(MinHeap* Heap, Node* Element) {                                         //Insert a element
    if(Heap->CurrentSize == Heap->Capacity) return;                                 //If we are full no insert
                    
    int i = Heap->CurrentSize;                                                      //Put a node
    Heap->Data[Heap->CurrentSize] = Element;                                        //Put the element
    Heap->CurrentSize += 1;                                                         //Add the size
    
    while(i > 0 && MySonIsSmaller(Heap, i)) {                                       //Check if my son is smallest
        Swap(Heap->Data[i], Heap->Data[Parent(i)]);                                 //Swap key
        i = Parent(i);                                                              //get me the parent
    }
}

void MakeMinHeapFromArray(MinHeap * Heap, Node** Data, int DataSize) {              //Make a heap from an array
    Heap->Data = Data;                                                              //Put the data
    Heap->CurrentSize = Heap->Capacity = DataSize;                                  //Now set the size
    for(int i = Parent(DataSize - 1); i >= 0; i--)Heapify(Heap, i);                 //Put with Heapify
}

void Heapify(MinHeap* Heap, int i) {                                                //Recursive Function
    int Largest = i;                                                                //Start largest

    if(Left(i) < Heap->CurrentSize)                                                 //We can go there?    
        if (Bigger(Heap->Data[Left(i)], Heap->Data[Largest])) Largest = Left(i);    //Is bigger?
    if(Right(i) < Heap->CurrentSize)                                                //We can go there?    
        if (Bigger(Heap->Data[Right(i)], Heap->Data[Largest])) Largest = Right(i);  //Is bigger?
    
    if(i != Largest) {                                                              //If we find another largest
        Swap(Heap->Data[i], Heap->Data[Largest]);                                   //Swap it!
        Heapify(Heap, Largest);                                                     //Check it!
    }
}
