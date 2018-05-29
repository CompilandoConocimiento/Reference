/*===================================================================
==================        FUNCTIONS             =====================
===================================================================*/

/**
 * This will return the size in bytes of a file using a file pointer
 */
int GetFileSize(FILE *FilePointer) {								//Get the file size
    int PreviuosState = ftell(FilePointer);							//Save a previuos sata
    fseek(FilePointer, 0L, SEEK_END);								//Seek to end of file
    
    int FileSize = ftell(FilePointer);								//Now we have a size
    fseek(FilePointer, PreviuosState,SEEK_SET); 					//Go back to where we were

    return FileSize;												//Return the type
}

/**
 * This will print ChunkSize consecutive byte in a cool way
 */
void PrintAChunk(byte StreamInput[], int ChunkSize) {					//Print a chunck of data
	if (IsHex) {
		for (int i = 0; i < ChunkSize; ++i) {							//For each element in chunk
			printf("%02X", StreamInput[i]);								//Show it
			if (i % 2) printf(" ");										//Add space
		}
	}
	else {
		for (int i = 0; i < ChunkSize; ++i)  							//For each element in chunk
			printf("%c", StreamInput[i]);								//Show it
	}
	printf("\n");														//Newline
}

/**
 * This create a standard node
 */
Node* CreateNode(uint Data, ull Frequency, Node* Left, Node* Right) {	//Create a node
    Node* NewNode = (Node*) calloc(1, sizeof(Node));					//Reserve memory
    NewNode->Data = Data;												//Put data
    NewNode->Frequency = Frequency;										//Put data
    NewNode->Left = Left;												//Put data
    NewNode->Right = Right;												//Put data

    return NewNode;														//Give the data
}

