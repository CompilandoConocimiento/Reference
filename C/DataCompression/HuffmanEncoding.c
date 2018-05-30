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
#include "HelperFunctions.c"                                                        //Fns to simple to show
#include "Heap.c"                                                                   //SEMI implementation of heap

/**
 * This will create a ull array of 256 elements of frequencies in a binary file, 
 * reading it in chunks. Where given a "a" byte Result[a] will tell use how many
 * times exists the byte "a" in the file 
 */
ull* CreateFrequencyOfBytesArray(FILE* OriginalFile, int ChunkSize) {               //Fn: CREATE FREQUENCY ARRAY
    ull *Frequencies = (ull*) calloc(256, sizeof(ull));                             //Create array from heap memory

    int PreviousState = ftell(OriginalFile);                                        //Save a previuos sata
    fseek(OriginalFile, 0L, SEEK_END);                                              //Seek to end of file
    
    int FileSize = ftell(OriginalFile);                                             //Now we have a size

    fseek(OriginalFile, PreviousState, SEEK_SET);                                   //Go back to where we were
    int Cycles = FileSize / ChunkSize, RemainderCycles = FileSize % ChunkSize;      //And read the remainder

    byte StreamInput[ChunkSize];                                                    //Create array of chunck size 
    for (int i = 0, ReadSize = ChunkSize; i <= Cycles; ++i) {                       //Read each cycle
        if (i == Cycles) ReadSize = RemainderCycles;                                //If in the last cycle
        fread(StreamInput, sizeof(byte), ReadSize, OriginalFile);                   //Now read from file
        for (int j = 0; j < ReadSize; ++j) Frequencies[StreamInput[j]] += 1;        //Now add frequencies
    }

    fseek(OriginalFile, PreviousState, SEEK_SET);                                   //Go back to where we were
    return Frequencies;                                                             //Return the pointer
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

/**
 * This will create an array were for example in Codebook[b] will find a
 * string that represent the huffman encode of the letter 
 */
void GetCodeBook(char** Codebook, Node* HuffmanTree, char* Temporal, int i) {       //Fn: CREATE A CODE BOOK
    if (HuffmanTree == NULL) return;                                                //If end point seen
    if (HuffmanTree->Right == NULL && HuffmanTree->Left == NULL) {                  //If it's a leaf
        if (i == 0) {Temporal[0] = '0'; i = 1;}                                     //Special case
        Temporal[i] = '\0';                                                         //End the string
        Codebook[HuffmanTree->Data] = (char*) malloc(i + 1);                        //Call malloc to put space
        memcpy(Codebook[HuffmanTree->Data], Temporal, i + 1);                       //Reserve memory
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

    int PreviousState = ftell(OriginalFile);                                        //Save a previuos sata
    fseek(OriginalFile, 0L, SEEK_END);                                              //Seek to end of file
    
    int FileSize = ftell(OriginalFile);                                             //Now we have a size
    if(FileSize == 0) return 0;                                                     //Special case
    fseek(OriginalFile, PreviousState, SEEK_SET);                                   //Go back to where we were
    int Cycles = FileSize / ChunkSize, RemainderCycles = FileSize % ChunkSize;      //And read the remainder

    byte StreamInput[ChunkSize];                                                    //Create array of chunck size 
    byte DataToSend[BytesToSend];                                                   //Create an array to send data
    memset(StreamInput, 0, ChunkSize);                                              //Start at 0
    memset(DataToSend, 0, BytesToSend);                                             //Start at 0
    
    int CurrentPoint = 0;                                                           //Counter: [0, 8*BytesToSend]
    for (int i = 0, ReadSize = ChunkSize; i <= Cycles; ++i) {                       //Read each cycle
        if (i == Cycles) ReadSize = RemainderCycles;                                //If in the last cycle
        fread(StreamInput, sizeof(byte), ReadSize, OriginalFile);                   //Now read from file
        
        for (int j = 0; j < ReadSize; ++j) {                                        //For each byte we read
            char* String = Codebook[StreamInput[j]];                                //Get me the codebook string

            for (int k = 0, Size = strlen(String); k < Size; ++k) {                 //For each bit in the string
                if (String[k] == '1')                                               //If we need to set a bit
                    SetBit(&DataToSend[CurrentPoint / 8], CurrentPoint % 8);        //Put in the data to send

                if (CurrentPoint == (BytesToSend * 8) - 1) {                        //If we have enough data to send
                    fwrite (DataToSend, BytesToSend, 1, EncodedFile);               //Write the data
                    memset(DataToSend, 0, BytesToSend);                             //Start it!
                    CurrentPoint = 0;                                               //Return to 0
                    memset(DataToSend, 0, BytesToSend);                             //Reset data
                }    
                else CurrentPoint++;                                                //Continue moving
            }
        }
    }

    int Remainder = CurrentPoint % 8;                                               //The reminder bits
    if (Remainder != 0) CurrentPoint = (CurrentPoint / 8) + 1;                      //If we cant write bytes
    else CurrentPoint = CurrentPoint / 8;                                           //If we can write bytes

    fwrite (DataToSend, CurrentPoint, 1, EncodedFile);                              //Write the last data
    return (Remainder == 0)? 0 : 8 - Remainder;                                     //The bits to ignore
}

/**
 * This will create an array were for example in Codebook[b] will find a
 * string that represent the huffman encode of the letter 
 */
void CreateTreeFile(FILE* TreeFile, ull Frequencies[], byte IgnoreBits) {           //Fn: CREATE TREE FILE
    fwrite (Frequencies, 256, 8, TreeFile);                                         //Write the last data
    fwrite (&IgnoreBits, 1, 1, TreeFile);                                           //Write the data
}

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
 * Given a Huffman tree decode a file an put it in NewFile
 */
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

/**
 * MAIN FOR DECODING
 */
int MainForDecoding(int argc, char const *argv[]) {                                 //MAIN FUNCTION
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

/**
 * MAIN FOR ENCODING
 */
int MainForEncoding(int argc, char const *argv[]) {                                 //MAIN FUNCTION
    
    const char* OriginalFileName = argv[1];                                         //Necessary files
    const char* EncodedFileName  = argv[2];                                         //Necessary files
    const char* TreeFileName     = argv[3];                                         //Necessary files

    char* Codebook[256] = {NULL}, TemporalString[257];                              //Array of string for codebook
    int ChunkSize = 8192, BytesToSend = 8192;                                       //Way to read-send info
    
    FILE* OriginalFile = fopen(OriginalFileName, "rb");                             //Open file
    FILE* EncodedFile  = fopen(EncodedFileName,  "wb");                             //Open file
    FILE* TreeFile     = fopen(TreeFileName,     "wb");                             //Open file

    ull *Frequencies  = CreateFrequencyOfBytesArray(OriginalFile, ChunkSize);       //Create frequencies tables

    Node* HuffmanTree = CreateTreeHuffmanTree(Frequencies);                         //Create huffman tree
    GetCodeBook(Codebook, HuffmanTree, TemporalString, 0);                          //Create codification strings

    DeleteTree(HuffmanTree);                                                        //Delete, need it anymore

    byte IgnoreBits = CreateEncodedFile
            (EncodedFile, OriginalFile, Codebook, ChunkSize, BytesToSend);          //Now encode the file
    DeleteCodebook(Codebook);                                                       //Delete the string codes

    CreateTreeFile(TreeFile, Frequencies, IgnoreBits);                              //Create the tree file

    fclose(TreeFile);                                                               //Close the files
    fclose(EncodedFile);                                                            //Close the files
    fclose(OriginalFile);                                                           //Close the files 

    return 0;                                                                       //All resulted ok
}


int main(int argc, char const *argv[]) {                                            //REAL MAIN
    const char* Files[4];                                                           //Possible parameters
    byte DecodeMode = 0;                                                            //Decode mode?

    Files[2] = "EncodedFile.mini";                                                  //Default values
    Files[3] = "Key.bin";                                                           //Default values

    for (int i = 1; i < argc; ++i) {                                                //For each file
        if (strcmp(argv[i], "-File") == 0)          Files[1] = argv[i+1];           //If custome
        if (strcmp(argv[i], "-EncodedFile") == 0)   Files[2] = argv[i+1];           //If custome
        if (strcmp(argv[i], "-KeyFile") == 0)       Files[3] = argv[i+1];           //If custome
        if (strcmp(argv[i], "-Decode") == 0)        DecodeMode = 1;                 //If decode mode
    }

    if (DecodeMode) return MainForDecoding(argc, Files);                            //Call one
    return MainForEncoding(argc, Files);                                            //Or other program
}