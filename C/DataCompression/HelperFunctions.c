/*===================================================================
==================        FUNCTIONS             =====================
===================================================================*/

/**
 * Delete a tree, just that
 */
void DeleteTree(Node* Tree) {
  	if (Tree->Right != NULL) DeleteTree(Tree->Right);
  	if (Tree->Left != NULL)  DeleteTree(Tree->Left);
	free(Tree);
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
