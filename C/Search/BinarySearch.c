/*===================================================================
==================      BINARY SEARCH           =====================
===================================================================*/

/**
 * Is just binary search ...
 * 
 * @param Data              A pointer to the array of int to sort
 * @param DataSize          The size of the Data array
 * @param NumberToSearch    The number to search
 * @return                  Nothing...I'm modifying the raw data
 */

int BinarySearch(int Data[], int DataSize, int NumberToSearch) {    //=== BINARY SEARCH ======
    int Initial = 0,  Final = DataSize;                             //Variables that we need

    while (Initial <= Final) {                                      //While find make sense              
        
        int Middle = Initial + ((Final - Initial) / 2);             //Find a new SearchPosition
        
        if (Data[Middle] == NumberToSearch)                         //If all ok!
            return Middle;                                          //If we find it!
        else if (Data[Middle] > NumberToSearch)                     //If we need to go to side
            Final = Middle - 1;                                     //Find the new final position
        else                                                        //If we need to go to side
            Initial = Middle + 1;                                   //Find the new initial position
    }

    return -1;
}

/*===================================================================
============     PARALELL BINARY SEARCH           ===================
===================================================================*/

/**
 * Is just binary search ... but I divide the search to N workers
 * 
 * @param Data              A pointer to the array of int to sort
 * @param DataSize          The size of the Data array
 * @param NumberToSearch    The number to search
 * @return                  Nothing...I'm modifying the raw data
 */

/*===================================================
=======    PARALELL AUXILIAR FUNCTIONS     ==========
===================================================*/

typedef struct BinarySearchDataStruct {                             //Parameters to the threads
    int Initial;                                                    //Initial index to found    
    int Final;                                                      //Final index to found
    int *Data;                                                      //Pointer to teh data
    int NumberToSearch;                                             //What I'm searching
    int *FoundIt;                                                   //Flag
} BinarySearchData;

void* BinarySearchRange(void* Parameters) {                         //Thread Function
    BinarySearchData* Data = (BinarySearchData*) Parameters;        //Get the Parameters
    int Initial = Data->Initial;                                    //Unwrap the data
    int Final = Data->Final;                                        //Unwrap the data
    int Middle;

    while(Initial <= Final && *Data->FoundIt==-1){

        Middle = Initial + ((Final - Initial) / 2);                 //Find a new SearchPosition
        
        if (Data->Data[Middle] == Data->NumberToSearch){            //If we find it!
            *Data->FoundIt = Middle;
            break;
        }

        if (Data->Data[Middle] > Data->NumberToSearch)              //If we need to go to side
            Final = Middle - 1;                                     //Find the new final position
        else                                                        //If we need to go to side
            Initial = Middle + 1;                                   //Find the new initial position
    }

    return NULL;                                                    //I found nothing :(   
}


/*===================================================
=======       PARALELL MAIN FUNCTIONS      ==========
===================================================*/
int ParalellBinarySearch
    (int Data[], int DataSize, int ToSearch, int NumOfWorkers) {    //=== 'BINARY' SEARCH ======

    pthread_t* Workers = 
        (pthread_t*) malloc(NumOfWorkers * sizeof(pthread_t));      //Now get the array worker

    BinarySearchData* Parameters = (BinarySearchData*) 
        malloc(NumOfWorkers*sizeof(BinarySearchData));              //Now create the parameters data

    int SizeOfSearch = DataSize / NumOfWorkers;                     //Get the size of the search

    int FoundIt = -1;                                               //Found it flags
    for (int i = 0; i < NumOfWorkers; ++i) {                        //For each worker:
        
        Parameters[i].Initial = i * SizeOfSearch;                   //Get the initial index to search
        Parameters[i].Final = (i == NumOfWorkers - 1)? 
            (i + 1) * SizeOfSearch - 1: DataSize - 1;               //Get the final index to search

        Parameters[i].Data = Data;                                  //Put the data
        Parameters[i].NumberToSearch = ToSearch;                    //Put the data
        Parameters[i].NumberToSearch = ToSearch;                    //Put the data
        Parameters[i].FoundIt = &FoundIt;                           //Put the data

        pthread_create
            (&Workers[i], NULL, BinarySearchRange, &Parameters[i]); //Get the thread working!
    }

    for (int i = 0; i < NumOfWorkers; ++i)                          //For each worker
        pthread_join(Workers[i], NULL);                             //Now wait to the worker

    return FoundIt;                                                 //Return the result

}

