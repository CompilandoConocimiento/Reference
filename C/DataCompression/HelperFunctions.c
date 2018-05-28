/*===================================================================
==================        FUNCTIONS             =====================
===================================================================*/
int GetFileSize(FILE *FilePointer) {								//Get the file size
    int PreviuosState = ftell(FilePointer);							//Save a previuos sata
    fseek(FilePointer, 0L, SEEK_END);								//Seek to end of file
    
    int FileSize = ftell(FilePointer);								//Now we have a size
    fseek(FilePointer, PreviuosState,SEEK_SET); 					//Go back to where we were

    return FileSize;												//Return the type
}

void PrintAChunk(byte StreamInput[], int ChunkSize) {				//Print a chunck of data
	for (int i = 0; i < ChunkSize; ++i) {							//For each element in chunk
		printf("%02X", StreamInput[i]);								//Show it
		if (i % 2) printf(" ");										//Add space
	}
	printf("\n");													//Newline
}

