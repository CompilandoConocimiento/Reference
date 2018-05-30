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
#include "HelperFunctions.c"                                                        //Add library
#include "Heap.c"                                                                   //Add library

/**
 * Just a function to get the frequencies and the number of bits to ignore
 */
ull* GetFrequenciesArray (FILE* TreeFile, byte* IgnoreBits) {                       //Fn: GET FREQUENCIES
    ull* Frequencies = (ull*) calloc(256, sizeof(ull));                             //Where to store it?
    fread(Frequencies, sizeof(ull), 256, TreeFile);                                 //Now read from file
    fread(IgnoreBits, 1, 1, TreeFile);                                              //Now read from file

    return Frequencies;                                                             //Return it!
}


/**
 * This will create a pointer to a Huffman tree, just that
 */
Node* CreateTreeHuffmanTree(const ull Frequencies[]) {                              //Fn: CREATE HUFFMAN TREE
    int NumberOfNodes = 0;                                                          //Number of Nodes
    Node* NodesArray[256];                                                          //Array of Nodes
    memset(NodesArray, 0, 256);
    
    for (int i = 0; i < 256; ++i) {                                                 //For each item in Frequencies
        if (Frequencies[i] == 0) continue;                                          //If no data move
        NodesArray[NumberOfNodes++] = CreateNode(i, Frequencies[i], NULL, NULL);    //Create a node
    }
    MinHeap Heap; MakeMinHeapFromArray(&Heap, NodesArray, NumberOfNodes);           //Create an array

    if (NumberOfNodes < 2) {                                                        //If special case
        Node *SuperNode = (NumberOfNodes == 1)? NodesArray[0] : NULL;               //Create a super node
        int Frequency = (SuperNode)? SuperNode->Frequency : 0;                      //Make it manual
        Node *NewNode = CreateNode(0, Frequency, SuperNode, NULL);                  //Make it manual
        return NewNode;                                                             //Return it!
    }

    while (NumberOfNodes > 1) {                                                     //While we dont have ONE tree
        Node *NewNode, *Left = ExtractMin(&Heap), *Right = ExtractMin(&Heap);       //Create a new node
        NewNode = CreateNode(0, Left->Frequency+Right->Frequency, Left, Right);     //Create the new node
        Insert(&Heap, NewNode);                                                     //Insert where you can
        NumberOfNodes--;                                                            //Create 1, delete 2 .: -1
    }

    return ExtractMin(&Heap);                                                       //Pop the last item
}



void DecodeFile(FILE* EncodedFile, FILE* NewFile, Node* HuffmanTree,                //Fn: CREATE DECODE FILE
    int ChunkSize, int BytesToSend, int IgnoreBits) {                               //Fn: CREATE DECODE FILE

    int PreviousState = ftell(EncodedFile);                                         //Save a previuos sata
    fseek(EncodedFile, 0L, SEEK_END);                                               //Seek to end of file
    
    int FileSize = ftell(EncodedFile);                                              //Now we have a size
    if(FileSize == 0) return;                                                       //Special case
    fseek(EncodedFile, PreviousState, SEEK_SET);                                    //Go back to where we were
    int Cycles = FileSize / ChunkSize, RemainderCycles = FileSize % ChunkSize;      //And read the remainder

    Node* CurrentNode = HuffmanTree;                                                //Save the root
    int CurrentPoint = PreviousState;                                               //And save where you are

    byte StreamInput[ChunkSize];                                                    //Create array of chunck size 
    byte DataToSend[BytesToSend];                                                   //Output buffer
    memset(StreamInput, 0, ChunkSize);                                              //Start in 0
    memset(DataToSend, 0, BytesToSend);                                             //Start in 0

    int StreamOutputIndex = 0;                                                      //Current point in out
    for (int i = 0, ReadSize = ChunkSize; i <= Cycles; ++i) {                       //Read each cycle
        if (i == Cycles) ReadSize = RemainderCycles;                                //If in the last cycle
        fread(StreamInput, sizeof(byte), ReadSize, EncodedFile);                    //Now read from file

        for (int j = 0; j < ReadSize; ++j) {                                        //For each byte
            byte CurrentByte = StreamInput[j];                                      //Cool name pliss
            for (int k = 0; k < 8; ++k) {                                           //For each bit
                if (CurrentPoint + IgnoreBits >= (FileSize * 8)) break;             //If we need to exit
                byte bit = GetBit(CurrentByte, k);                                  //Get the bit
                CurrentNode = (bit)? CurrentNode->Right: CurrentNode->Left;         //Current node

                if (CurrentNode->Left == NULL && CurrentNode->Right == NULL) {      //If is a leaf
                    DataToSend[StreamOutputIndex++] = CurrentNode->Data;            //Get me the data
                    CurrentNode = HuffmanTree;                                      //Start again
                }
                
                if (StreamOutputIndex == BytesToSend) {                             //If we are full
                    fwrite (DataToSend, BytesToSend, 1, NewFile);                   //Write the data
                    StreamOutputIndex = 0;                                          //Start count to 0
                }
                CurrentPoint++;                                                     //Next byte in encoded file
            }
        }
    }

    fwrite (DataToSend, StreamOutputIndex, 1, NewFile);                             //Write the data
    fseek(EncodedFile, PreviousState, SEEK_SET);                                    //Go back to where we were
}

int main(int argc, char const *argv[]) {
    const char* NewFileName      = argv[1];                                         //Necessary files
    const char* EncodedFileName  = argv[2];                                         //Necessary files
    const char* TreeFileName     = argv[3];                                         //Necessary files

    int ChunkSize = 8192, BytesToSend = 8192;                                       //Way to read-send info
    
    FILE* NewFile      = fopen(NewFileName,      "wb");                             //Open file
    FILE* EncodedFile  = fopen(EncodedFileName,  "rb");                             //Open file
    FILE* TreeFile     = fopen(TreeFileName,     "rb");                             //Open file

    byte IgnoreBits;                                                                //Bits to ignore
    ull *Frequencies = GetFrequenciesArray(TreeFile, &IgnoreBits);                  //Get the key
    Node* HuffmanTree = CreateTreeHuffmanTree(Frequencies);                         //Create the key

    DecodeFile                                                                      //Decode the file
        (EncodedFile, NewFile, HuffmanTree, ChunkSize, BytesToSend, IgnoreBits);    //Decode the file

    fclose(NewFile);                                                                //Close the files 
    fclose(TreeFile);                                                               //Close the files
    fclose(EncodedFile);                                                            //Close the files

    return 0;                                                                       //We are happy
}