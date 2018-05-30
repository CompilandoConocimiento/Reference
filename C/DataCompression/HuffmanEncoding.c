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

int IsHex = 1;


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
ull* CreateFrequencyOfBytesArray(FILE* OriginalFile, int ChunkSize) {               //Fn: CREATE FREQUENCY ARRAY
    ull *Frequencies = (ull*) malloc(256 * sizeof(ull));                            //Create array from heap memory
    memset(Frequencies, 0, 256);                                                    //Start it!

    int PreviuosState = ftell(OriginalFile);                                        //Save a previuos sata
    fseek(OriginalFile, 0L, SEEK_END);                                              //Seek to end of file
    
    int FileSize = ftell(OriginalFile);                                             //Now we have a size
    fseek(OriginalFile, PreviuosState, SEEK_SET);                                   //Go back to where we were
    int Cycles = FileSize / ChunkSize, RemainderCycles = FileSize % ChunkSize;      //And read the remainder

    byte StreamInput[ChunkSize];                                                    //Create array of chunck size 
    for (int i = 0, ReadSize = ChunkSize; i <= Cycles; ++i) {                       //Read each cycle
        if (i == Cycles) ReadSize = RemainderCycles;                                //If in the last cycle
        fread(&StreamInput, sizeof(byte), ReadSize, OriginalFile);                  //Now read from file
        PrintAChunk(StreamInput, ReadSize);                                         //Show it!!!!!!!!!!!!!!!!!!!!   
        for (int j = 0; j < ReadSize; ++j) Frequencies[StreamInput[j]] += 1;        //Now add frequencies
    }

    fseek(OriginalFile, PreviuosState, SEEK_SET);                                   //Go back to where we were
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



/**
 * This will create a file with a codebook, the return is the number of BITS
 * you have to ingore at the end
 */
byte CreateEncodedFile (FILE* EncodedFile, FILE* OriginalFile, char** Codebook,     //Fn: CREATE THE ENCODED
    int ChunkSize, int BytesToSend) {                                               //Fn: FILE

    int PreviuosState = ftell(OriginalFile);                                        //Save a previuos sata
    fseek(OriginalFile, 0L, SEEK_END);                                              //Seek to end of file
    
    int FileSize = ftell(OriginalFile);                                             //Now we have a size
    fseek(OriginalFile, PreviuosState, SEEK_SET);                                   //Go back to where we were
    int Cycles = FileSize / ChunkSize, RemainderCycles = FileSize % ChunkSize;      //And read the remainder

    byte StreamInput[ChunkSize];                                                    //Create array of chunck size 
    byte DataToSend[BytesToSend];                                                   //Create an array to send data
    int CurrentPoint = 0;                                                           //Just a counter form 0 to NOBTS

    for (int i = 0, ReadSize = ChunkSize; i <= Cycles; ++i) {                       //Read each cycle
        if (i == Cycles) ReadSize = RemainderCycles;                                //If in the last cycle
        fread(&StreamInput, sizeof(byte), ReadSize, OriginalFile);                  //Now read from file
        
        for (int j = 0; j < ReadSize; ++j) {                                        //For each byte we read
            char* String = Codebook[StreamInput[j]];                                //Get me the codebook string

            for (int k = 0, Size = strlen(String); k < Size; ++k, ++CurrentPoint) { //For each bit in the string

                if (String[k] == '1')                                               //If we need to set a bit
                    DataToSend[CurrentPoint / 8] |= 1 << (7 - (CurrentPoint % 8));  //Put in the data to send

                if (CurrentPoint == (BytesToSend * 8) - 1) {                        //If we have enough data to send
                    fwrite (&DataToSend, BytesToSend, 1, EncodedFile);              //Write the data
                    memset(DataToSend, 0, BytesToSend);                             //Start it!
                    CurrentPoint = -1;                                              //-1. Next iteration return to 0
                }    
            }
        }
    }

    int Remainder = CurrentPoint % 8;
    if (Remainder != 0) CurrentPoint = (CurrentPoint / 8) + 1; 
    else CurrentPoint = CurrentPoint / 8;

    fwrite (&DataToSend, CurrentPoint, 1, EncodedFile);

    return 8 - Remainder;
}


/**
 * This will create an array were for example in Codebook[b] will find a
 * string that represent the huffman encode of the letter 
 */
void CreateTreeFile(FILE* TreeFile, ull Frequencies[], byte IgnoreBits) {           //Fn: CREATE TREE FILE
    for (int i = 0; i < 256; ++i) fwrite (&Frequencies[i], 8, 1, TreeFile);         //Write the data
    fwrite (&IgnoreBits, 1, 1, TreeFile);                                           //Write the data
}

int main(int argc, char const *argv[]) {
    
    const char* OriginalFileName = argv[1];
    const char* EncodedFileName  = argv[2];
    const char* TreeFileName     = argv[3];

    char* Codebook[256] = {NULL}, TemporalString[257];
    
    int ChunkSize = 16, BytesToSend = 4;
    
    FILE* OriginalFile = fopen(OriginalFileName, "rb");
    FILE* EncodedFile  = fopen(EncodedFileName,  "wb");
    FILE* TreeFile     = fopen(TreeFileName,     "wb");

    ull *Frequencies  = CreateFrequencyOfBytesArray(OriginalFile, ChunkSize);
    Node* HuffmanTree = CreateTreeHuffmanTree(Frequencies);

    GetCodeBook(Codebook, HuffmanTree, TemporalString, 0);
    DeleteTree(HuffmanTree);

    byte IgnoreBits = CreateEncodedFile
            (EncodedFile, OriginalFile, Codebook, ChunkSize, BytesToSend);
    DeleteCodebook(Codebook);

    printf("Remainder is %i\n", IgnoreBits);
    CreateTreeFile(TreeFile, Frequencies, IgnoreBits);

    fclose(TreeFile);
    fclose(EncodedFile);
    fclose(OriginalFile);

    return 0;
}