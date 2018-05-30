/*===================================================================
==================       HUFFMAN DECODING       =====================
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


/*=============================================
============         NODE           ===========
=============================================*/
typedef struct Node {                                                               //Create a node type
    unsigned int Data;                                                              //Have a Data
    unsigned long long int Frequency;                                               //We will call it Node
    struct Node* Left;                                                              //For a tree
    struct Node* Right;                                                             //For a tree
} Node;  

int IsHex = 0;

#include "HelperFunctions.c"
#include "Heap.c"

/**
 */
ull* GetFrequenciesArray (FILE* TreeFile) {
    ull* Frequencies = (ull*) calloc(256, sizeof(ull));
    fread(Frequencies, sizeof(ull), 256, TreeFile);                  				//Now read from file

    return Frequencies;
}

/**
 * This will create a pointer to a Huffman tree, just that
 */
Node* CreateTreeHuffmanTree(const ull Frequencies[]) {                              //Fn: CREATE HUFFMAN TREE
    int NumberOfNodes = 0;                                                          //Number of Nodes
    Node* NodesArray[256];                                                          //Array of Nodes
    
    for (int i = 0; i < 256; ++i) {                                                 //For each item in Frequencies
        if (Frequencies[i] == 0) continue;                                          //If no data move
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

    FILE* TreeFile = fopen("Tree.key", "rb");
    ull *Frequencies = GetFrequenciesArray(TreeFile);

    for (byte i = 0; i != 255; ++i) {
        if (Frequencies[i] != 0) printf("New %c is %llu\n", i, Frequencies[i]);
    }

    Node* HuffmanTree = CreateTreeHuffmanTree(Frequencies);

	return 0;
}