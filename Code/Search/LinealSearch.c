/*===================================================================
==================    METADATA OF THE FILE      =====================
===================================================================*/
/**
 * @author  Rosas Hernandez Oscar Andres
 * @author  Alan Enrique Ontiveros Salazar
 * @author  Laura Andrea Morales 
 * @version 0.1
 * @team    CompilandoConocimiento
 * @date    2/04/2018
 */


/*===================================================================
==================      LINEAL SEARCH           =====================
===================================================================*/
/**
 * Is just lineal search ...
 * 
 * @param Data              A pointer to the array of int to sort
 * @param DataSize          The size of the Data array
 * @param NumberToSearch    The number to search
 * @return                  Nothing...I'm modifying the raw data
 */

int LinealSearch(int Data[], int DataSize, int NumberToSearch) {    //=== LINEAL SEARCH ======

    for (int i = 0; i < DataSize; ++i) {                            //For each item in Data     
        if (Data[i] == NumberToSearch)                              //If find it
            return i;                                               //Go
    }

    return -1;                                                      //Not found

} 


/*===================================================================
============     PARALELL LINEAL SEARCH           ===================
===================================================================*/

/**
 * Is just lineal search ... but I divide the search to N workers
 * 
 * @param Data              A pointer to the array of int to sort
 * @param DataSize          The size of the Data array
 * @param NumberToSearch    The number to search
 * @return                  Nothing...I'm modifying the raw data
 */


/*===================================================
=======    PARALELL AUXILIAR FUNCTIONS     ==========
===================================================*/

typedef struct LinealSearchDataStruct {                             //Parameters to the threads
    int Initial;                                                    //Initial index to found    
    int Final;                                                      //Final index to found
    int *Data;                                                      //Pointer to teh data
    int NumberToSearch;                                             //What I'm searching
    int *FoundIt;                                                   //Flag
} LinealSearchData;

void* LinealSearchRange(void* Parameters) {                         //Thread Function
    LinealSearchData* Data = (LinealSearchData*) Parameters;        //Get the Parameters
    int Initial = Data->Initial;                                    //Unwrap the data
    int Final = Data->Final;                                        //Unwrap the data

    for (int i = Initial; i<=Final && *Data->FoundIt==-1; ++i){     //For each item in Data     
        if (Data->Data[i] == Data->NumberToSearch){                 //If find it
            *Data->FoundIt = i;                                     //Now we have an index :)
            break;
        }
    }

    return NULL;                                                    //I found nothing :(   
}


/*===================================================
=======       PARALELL MAIN FUNCTIONS      ==========
===================================================*/
int ParalellLinealSearch
    (int Data[], int DataSize, int ToSearch, int NumOfWorkers) {    //=== 'LINEAL' SEARCH ======

    pthread_t* Workers = 
        (pthread_t*) malloc(NumOfWorkers * sizeof(pthread_t));      //Now get the array worker

    LinealSearchData* Parameters = (LinealSearchData*) 
                    malloc(NumOfWorkers*sizeof(LinealSearchData));  //Now create the parameters data

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
            (&Workers[i], NULL, LinealSearchRange, &Parameters[i]); //Get the thread working!
    }

    for (int i = 0; i < NumOfWorkers; ++i)                          //For each worker
        pthread_join(Workers[i], NULL);                             //Now wait to the worker

    return FoundIt;                                                 //Return the result

}

