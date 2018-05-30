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

#include <bitset> 
#include <iostream>

#include <stdio.h>                                                                  //Add library
#include <stdlib.h>                                                                 //Add library
#include <string.h>                                                                 //Add library

int IsHex = 0;

using namespace std;

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

    int PreviuosState = ftell(FilePointer);                                         //Save a previuos sata
    fseek(FilePointer, 0L, SEEK_END);                                               //Seek to end of file
    
    int FileSize = ftell(FilePointer);                                              //Now we have a size
    fseek(FilePointer, PreviuosState, SEEK_SET);                                    //Go back to where we were

    int Cycles = FileSize / ChunkSize;                                              //Divide it into pieces
    int RemainderCycles = FileSize % ChunkSize;                                     //And read the remainder

    byte StreamInput[ChunkSize];                                                    //Create array of chunck size 
    for (int i = 0, ReadSize = ChunkSize; i <= Cycles; ++i) {                       //Read each cycle
        fread(&StreamInput, sizeof(byte), ReadSize, FilePointer);                   //Now read from file
        PrintAChunk(StreamInput, ReadSize);                                         //Show it!!!!!!!!!!!!!!!!!!!!   
        for (int j = 0; j < ReadSize; ++j) Frequencies[StreamInput[j]] += 1;        //Now add frequencies
        if (i + 1 == Cycles) ReadSize = RemainderCycles;                            //If in the last cycle
    }

    fseek(FilePointer, PreviuosState, SEEK_SET);                                    //Go back to where we were
    return Frequencies;                                                             //Return the pointer
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

/**
 * This will create an array were for example in Codebook[b] will find a
 * string that represent the huffman encode of the letter 
 */
void GetCodeBook(char** Codebook, Node* HuffmanTree, char* Temporal, int i) {       //Fn: CREATE A CODE BOOK
    if (HuffmanTree == NULL) return;                                                //If end point seen
    if (HuffmanTree->Right == NULL && HuffmanTree->Left == NULL) {                  //If it's a leaf
        Temporal[i] = '\0';                                                         //End the string
        Codebook[HuffmanTree->Data] = (char*) malloc(i);                            //Call malloc to put space
        memcpy(Codebook[HuffmanTree->Data], Temporal, i);                           //Reserve memory
        printf("%c is %s\n", HuffmanTree->Data, Codebook[HuffmanTree->Data]);       //!!!!!!!!!!!!!!!!!!!!!!!
        return;                                                                     //End this call stack
    }
    Temporal[i] = '0'; GetCodeBook(Codebook, HuffmanTree->Left,  Temporal, i + 1);  //Recursive call wiii!
    Temporal[i] = '1'; GetCodeBook(Codebook, HuffmanTree->Right, Temporal, i + 1);  //Recursive call wiii!
}








int main(int argc, char const *argv[]) {

    const char* FileName = argv[1];
    FILE* FilePointer = fopen(FileName, "rb");

    ull *Frequencies = CreateFrequencyOfBytesArray(FilePointer, 16);

    Node* HuffmanTree = CreateTreeHuffmanTree(Frequencies);

    char* Codebook[256], TemporalString[257];
    GetCodeBook(Codebook, HuffmanTree, TemporalString, 0);
    DeleteTree(HuffmanTree);










    FILE* NewFile = fopen ("Encoded.bin", "wb");
    int ChunkSize = 16;

    int PreviuosState = ftell(FilePointer);                                         //Save a previuos sata
    fseek(FilePointer, 0L, SEEK_END);                                               //Seek to end of file
    
    int FileSize = ftell(FilePointer);                                              //Now we have a size
    fseek(FilePointer, PreviuosState, SEEK_SET);                                    //Go back to where we were

    int Cycles = FileSize / ChunkSize;                                              //Divide it into pieces
    int RemainderCycles = FileSize % ChunkSize;                                     //And read the remainder





    byte StreamInput[ChunkSize];                                                    //Create array of chunck size 
    ull Temporal = 0;
    int Start = 63;
    int CurrentPoint = 0;
    for (int i = 0, ReadSize = ChunkSize; i <= Cycles; ++i) {                       //Read each cycle
        fread(&StreamInput, sizeof(byte), ReadSize, FilePointer);                   //Now read from file
        for (int j = 0; j < ReadSize; ++j) {

            int k = 0;
            char* String = Codebook[StreamInput[j]];

            for (int Size = strlen(String); k < Size; ++k, ++CurrentPoint) {
                if (String[k] == '1') Temporal = Temporal | 1ULL << (Start - k);



                printf("%c shifting %d - ", String[k], Start - k);
                bitset<64> bitset1{Temporal};   // the bitset representation of 4  
                cout << bitset1 << endl;  // 0000000000000100  

                if (CurrentPoint == 23) {
                    printf("Vamos a escribir\n");
                    Temporal = Temporal >> (32 + 8);

                    bitset<24> bitset1{Temporal};   // the bitset representation of 4  
                    cout << bitset1 << endl;  // 0000000000000100  


                    printf("%llu\n", Temporal);
                    fwrite (&Temporal, 3, 1, NewFile);
                    Start = 63;
                    Temporal = 0;

                    printf("Escribtura lista\n");
                    
                    return 0;
                    CurrentPoint = 0;
                }    
            }
            
            Start = Start - k;
            
        }
        if (i + 1 == Cycles) ReadSize = RemainderCycles;                            //If in the last cycle
    }


    fclose(NewFile);


    return 0;
}