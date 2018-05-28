/*===================================================================
==================    PRIORITY QUEUE - HEAD     =====================
===================================================================*/
/**
 * @author  Rosas Hernandez Oscar Andres
 * @author  Alan Enrique Ontiveros Salazar
 * @author  Laura Andrea Morales 
 * @version 0.1
 * @team    CompilandoConocimiento
 * @date    1/06/2018
 */

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
 

/*=============================================
============     NODE & HEAP        ===========
=============================================*/
typedef struct Node {                                                               //Create a node type
    unsigned int Data;                                                              //Have a Data
    int Frequency;                                                                  //We will call it Node
} Node;

typedef struct MinHeap {                                                            //Create a Heap type
    Node* Data;                                                                     //The data
    unsigned int CurrentSize;                                                       //Now the current size
    unsigned int Capacity;                                                          //And Now the capacity
} MinHeap;                                                                          //We will call it MinHeap
 


/*=============================================
============     NODE & HEAP        ===========
=============================================*/
MinHeap* InitHeap(Size) {                                                           //Now, start all

    MinHeap* Heap = (MinHeap*) malloc(sizeof(MinHeap));                             //First declare space

    Heap->Capacity = Size;                                                          //Now , get the capacity
    Heap->CurrentSize = 0;                                                          //And the current size to 0
    Heap->Data = (Node*) malloc(sizeof(Node) * Size);                               //Now get the space for data
    
    Heap->Data[0].Frequency = -INT_MAX;                                             //Item 0 is -infinity

    return Heap;                                                                    //return the new heap
}
 


/*=============================================
=========    INSERT INTO HEAP       ===========
=============================================*/
void Insert(MinHeap* Heap, Node Element) {                                          //Insert an Item in Heap
    Heap->CurrentSize += 1;                                                         //Add size
    Heap->Data[Heap->CurrentSize] = Element;                                        //Insert in the last place

    int Now = Heap->CurrentSize;                                                    //Aux var
    while (Heap->Data[Now / 2].Frequency > Element.Frequency) {                     //While not place
        Heap->Data[Now] = Heap->Data[Now / 2];                                      //Copy the data
        Now /= 2;                                                                   //Move
    }

    Heap->Data[Now] = Element;                                                      //Add in the current position
}
 


/*=============================================
============     NODE & HEAP        ===========
=============================================*/
Node DeleteMin(MinHeap* Heap) {
    Node MinElement = Heap->Data[1];                                                //Min Element
    Node LastElement = Heap->Data[Heap->CurrentSize--];                             //The last element
    
    int Child, Now;                                                                 //Aux variabls
    for (Now = 1; Now * 2 <= Heap->CurrentSize; Now = Child) {                      //Foreach children

        Child = Now * 2;                                                            //Get the children index
        int FrequencyChild1 = Heap->Data[Child].Frequency;                          //Get child 1 frequency
        int FrequencyChild2 = Heap->Data[Child + 1].Frequency;                      //Get child 2 frequency

        if (Child != Heap->CurrentSize && FrequencyChild2 < FrequencyChild1)        //If we need to keep all =
            Child++;                                                                //Move
        if (LastElement.Frequency > Heap->Data[Child].Frequency)                    //Else if we have to move
            Heap->Data[Now] = Heap->Data[Child];                                    //Move it!
        else break;                                                                 //All is ok!
    }

    Heap->Data[Now] = LastElement;                                                  //Now you are the last
    return MinElement;                                                              //Go min
}
 



/*=============================================
============     NODE & HEAP        ===========
=============================================*/
int main() {
    int Size;

    printf("Size");
    scanf("%d", &Size);
    MinHeap* NHeap = InitHeap(Size); 

    printf("Enter the elements: \n");

    for (int i = 0; i < Size; i++) {
        Node Element;
        Element.Data = 1;
        scanf("%d %d", &Element.Data, &Element.Frequency);
        Insert(NHeap, Element);
    }

    for (int i = 0; i < Size; i++) {
        Node new = DeleteMin(NHeap);
        printf("Element %d has frequency of %d", new.Data, new.Frequency);
    }

    printf("\n");

    return 0;
}