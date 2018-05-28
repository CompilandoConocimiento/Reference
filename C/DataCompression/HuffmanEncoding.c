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

typedef unsigned char byte;
typedef unsigned long long int ull;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "HelperFunctions.c"


ull* CreateFrecuencyScale(const char *FileName) {
    FILE *FilePointer;

    FilePointer = fopen(FileName,"rb");
    ull *Frecuencies = (ull*) malloc(256 * sizeof(ull));
    memset(Frecuencies, 0, 256);

    int FileSize = GetFileSize(FilePointer);
    int ChunkSize = 16;
    int Cycles = FileSize / ChunkSize;
    int RemainderCycles = FileSize % ChunkSize;

    byte StreamInput[ChunkSize];
    for (int i = 0; i < Cycles; ++i) {
        fread(&StreamInput, sizeof(byte), ChunkSize, FilePointer);
        PrintAChunk(StreamInput, ChunkSize);
        for (int j = 0; j < ChunkSize; ++j) {
            Frecuencies[StreamInput[j]] += 1;
        }
    }

    fread(&StreamInput, sizeof(byte), RemainderCycles, FilePointer);
    PrintAChunk(StreamInput, RemainderCycles);
    for (int j = 0; j < RemainderCycles; ++j) {
        Frecuencies[StreamInput[j]] += 1;
    }

    return Frecuencies;
}



int main(int argc, char const *argv[]) {

    ull *Frecuencies = CreateFrecuencyScale(argv[1]);

    for (int i = 0; i < 256; ++i) {
        printf("Frecuencies %02X is %llu \n", i, Frecuencies[i]); 
    }

    


    return 0;
}