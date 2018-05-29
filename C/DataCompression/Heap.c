/*===================================================================
==================    PRIORITY QUEUE - HEAD     =====================
===================================================================*/
#include <stdio.h>                                                                  //Put library
#include <stdlib.h>                                                                 //Put library
#include <limits.h>                                                                 //Put library

#include "Heap.h"                                                                   //Put library

/**
 * @author  Rosas Hernandez Oscar Andres
 * @author  Alan Enrique Ontiveros Salazar
 * @author  Laura Andrea Morales 
 * @version 0.1
 * @team    CompilandoConocimiento
 * @date    1/06/2018
 */



/*=============================================
============     HELPERS            ===========
=============================================*/
int Left(int i)   {return (i << 1) + 1;}                                            
int Right(int i)  {return (i << 1) + 2;}                                    
int Parent(int i) {return (i - 1) >> 1;}                                        
    
Node* GetMin(MinHeap * Heap) {return Heap->Data[0];}
int GetSize(MinHeap* Heap)   {return Heap->CurrentSize;}
int IsEmpty(MinHeap* Heap)   {return Heap->CurrentSize == 0;}
int Bigger(Node* A, Node* B) {return A->Frequency < B->Frequency;}
void Swap(Node* A, Node* B)  {Node Temporal = *A; *A = *B; *B = Temporal;}

void Initialize(MinHeap * Heap, int Capacity) {                                     //Create the Heap
    Heap->Capacity = Capacity;                                                      //Get the capacity
    Heap->CurrentSize = 0;                                                          //Now 1 have nothing
    Heap->Data = calloc(Capacity, sizeof(Node*));                                   //Create the data
}

int MySonIsSmaller(MinHeap* H, int i) {
    return Bigger(H->Data[i], H->Data[Parent(i)]);
}

void Destroy(MinHeap *Heap) {                                                       //Destroy the Heap
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

void IncreaseKey(MinHeap* Heap, int i, Node* Element) {
    Heap->Data[i] = Element;
    
    while(i > 0 && MySonIsSmaller(Heap, i)) {
        Swap(Heap->Data[i], Heap->Data[Parent(i)]);
        i = Parent(i);
    }
}

void insert(MinHeap * Heap, Node * e){
    if(Heap->CurrentSize < Heap->Capacity){
        Heap->CurrentSize++;
        int i = Heap->CurrentSize - 1;
        Heap->Data[i] = e;
        while(i > 0 && MySonIsSmaller(Heap, i)){
            Swap(Heap->Data[i], Heap->Data[Parent(i)]);
            i = Parent(i);
        }
    }
}

void delete(MinHeap * Heap, int i){
    Node * infinity = calloc(1, sizeof(Node));
    infinity->Frequency = -INT_MAX;
    IncreaseKey(Heap, i, infinity);
    ExtractMin(Heap);
}

void MakeMinHeap(MinHeap * Heap, Node ** Data, int n){
    Heap->Data = Data;
    Heap->CurrentSize = Heap->Capacity = n;
    int i;
    for(i = Parent(n - 1); i >= 0; i--){
        Heapify(Heap, i);
    }
}

void Heapify(MinHeap* Heap, int i) {
    int l = Left(i);
    int r = Right(i);
    int largest = i;

    if(l < Heap->CurrentSize && Bigger(Heap->Data[l], Heap->Data[largest]))
        largest = l;
    if(r < Heap->CurrentSize && Bigger(Heap->Data[r], Heap->Data[largest]))
        largest = r;
    if(i != largest) {
        Swap(Heap->Data[i], Heap->Data[largest]);
        Heapify(Heap, largest);
    }
}

/*=============================================
============     NODE & HEAP        ===========
=============================================*/
int main() {
    int Size;

    printf("Size");
    scanf("%d", &Size);

    MinHeap* Heap = calloc(1, sizeof(MinHeap));

    Initialize(Heap, Size); 

    printf("Enter the elements: \n");

    for (int i = 0; i < Size; i++) {
        unsigned int a;
        int b;

        scanf("%d %d", &a, &b);

        Node * e = calloc(1, sizeof(Node));
        e->Data = a;
        e->Frequency = b;
        insert(Heap, e);
    }

    printf("Sli\n");

    for (int i = 0; i < Size; i++) {
        Node* Element = ExtractMin(Heap);
        printf("Element %d has frequency of %llu\n", Element->Data, Element->Frequency);
    }

    Destroy(Heap);

    printf("\n");

    return 0;
}