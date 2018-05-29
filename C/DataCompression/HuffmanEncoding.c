/*===================================================================
==================    METADATA OF THE FILE      =====================
===================================================================*/
/**
 * @author  Rosas Hernandez Oscar Andres
 * @author  Alan Enrique Ontiveros Salazar
 * @author  Laura Andrea Morales 
 * @version 0.1
 * @team    CompilandoConocimiento
 * @date    1/06/2018
 * @notes   This program can compress up to 2GB files because of GetFileSize (return an int)
 */

typedef unsigned char byte;                                                         //For short names
typedef unsigned long long int ull;                                                 //for short names
typedef unsigned int uint;                                                          //for short names

#include <stdio.h>                                                                  //Add library
#include <stdlib.h>                                                                 //Add library
#include <string.h>                                                                 //Add library
#include <stdbool.h>                                                                //Add library

int IsHex = 0;

/*=============================================
============         NODE           ===========
=============================================*/
typedef struct Node {                                                               //Create a node type
    unsigned int Data;                                                              //Have a Data
    unsigned long long int Frequency;                                               //We will call it Node
    struct Node* Left;                                                              //For a tree
    struct Node* Right;                                                             //For a tree
} Node;                                                                             //Call it Node :v

#include "HelperFunctions.c"                                                        //Fns to simple to show
#include "Heap.c"                                                                   //SEMI implementation of heap

/**
 * This will create a ull array of 256 elements of frequencies in a binary file, 
 * reading it in chunks. Where given a "a" byte Result[a] will tell use how many
 * times exists the byte "a" in the file 
 */
ull* CreateFrequencyOfBytesArray(FILE* FilePointer, int ChunkSize) {                //Fn: CREATE FREQUENCY ARRAY
    ull *Frequencies = (ull*) malloc(256 * sizeof(ull));                            //Create array from heap memory
    memset(Frequencies, 0, 256);                                                    //Start it!

    int FileSize = GetFileSize(FilePointer);                                        //Now we will need a file size
    int Cycles = FileSize / ChunkSize;                                              //Divide it into pieces
    int RemainderCycles = FileSize % ChunkSize;                                     //And read the remainder

    byte StreamInput[ChunkSize];                                                    //Create array of chunck size 
    for (int i = 0, ReadSize = ChunkSize; i <= Cycles; ++i) {                       //Read each cycle
        fread(&StreamInput, sizeof(byte), ReadSize, FilePointer);                   //Now read from file
        PrintAChunk(StreamInput, ReadSize);                                         //Show it!!!!!!!!!!!!!!!!!!!!   
        for (int j = 0; j < ReadSize; ++j) Frequencies[StreamInput[j]] += 1;        //Now add frequencies
        if (i + 1 == Cycles) ReadSize = RemainderCycles;                            //If in the last cycle
    }

    return Frequencies;                                                             //Return the pointer
}


/**
 * This will create a pointer to a Huffman tree, just that
 */
Node* CreateTreeHuffmanTree(ull Frequencies[]) {                                    //Fn: CREATE HUFFMAN TREE
    int NumberOfNodes = 0;                                                          //Number of Nodes
    Node* NodesArray[256];                                                          //Array of Nodes
    
    for (int i = 0; i < 256; ++i) {                                                 //For each item in Frequencies
        if (Frequencies[i] == 0 || i == 0) continue;                                //If no data move
        NodesArray[NumberOfNodes++] = CreateNode(i, Frequencies[i], NULL, NULL);    //Create a node
    }

    MinHeap Heap; MakeMinHeapFromArray(&Heap, NodesArray, NumberOfNodes);           //Create an array
    while (NumberOfNodes > 1) {                                                     //While we dont have ONE tree
        Node *NewNode, *Left = ExtractMin(&Heap), *Right = ExtractMin(&Heap);       //Create a new node
        NewNode = CreateNode(256, Left->Frequency+Right->Frequency, Left, Right);   //Create the new node
        Insert(&Heap, NewNode);                                                     //Insert where you can
        NumberOfNodes--;                                                            //Create 1, delete 2 .: -1
    }

    return ExtractMin(&Heap);                                                       //Pop the last item
}


int main(int argc, char const *argv[]) {

    const char* FileName = argv[1];
    FILE* FilePointer = fopen(FileName, "rb");

    ull *Frequencies = CreateFrequencyOfBytesArray(FilePointer, 16);

    for (int i = 0; i < 256; ++i) {
        if (IsHex) printf("Frequencies %2X is %llu \n", i, Frequencies[i]); 
        else printf("Frequencies %c is %llu \n", i, Frequencies[i]); 
    }

    Node* HuffmanTree = CreateTreeHuffmanTree(Frequencies);


    return 0;
}