#ifndef priorityqueue
#define priorityqueue

/*=============================================
============     NODE & HEAP        ===========
=============================================*/
typedef struct Node {                                                               //Create a node type
    unsigned int Data;                                                              //Have a Data
    unsigned long long int Frequency;                                               //We will call it Node
} Node;

typedef struct MinHeap {                                                            //Create a MinHeap type
    Node** Data;                                                                    //The data
    unsigned int Capacity;                                                          //And Now the capacity
    unsigned int CurrentSize;                                                       //Now the current size
} MinHeap;                                                                          //We will call it MinMinHeap
 


/*=============================================
============     ESSENCIAL          ===========
=============================================*/
void Initialize(MinHeap * Heap, int Capacity);
void Destroy(MinHeap * Heap);

int GetSize(MinHeap* Heap);
int IsEmpty(MinHeap* Heap);

void Heapify(MinHeap* Heap, int i);

Node* getMax(MinHeap* Heap);
Node* extractMax(MinHeap* Heap);

void increaseKey(MinHeap* Heap, int i, Node * e);
void insert(MinHeap* Heap, Node * e);
void delete(MinHeap* Heap, int i);

void MakeMinHeap(MinHeap* Heap, Node ** Data, int n);

#endif