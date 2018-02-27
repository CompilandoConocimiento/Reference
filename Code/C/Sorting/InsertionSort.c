/*===================================================================
==================      INSERTION SORT          =====================
===================================================================*/

/**
 * This is a really intuitive sorting algorithm, to do so we say
 * that we will create a new subarray.
 * So the subarray [0, 1] is already sorted, now:
 * Take the next element contiguos to the subarray an put it where it
 * belongs and move all the other 1 place.
 * Now my new subarray is from [0, 2], and repeat, you get the point
 * 
 * @param Data      A pointer to the array of int to sort
 * @param DataSize  The size of the Data array
 * @return          Nothing...I'm modifying the raw data
 */
void InsertionSort(int Data[], int DataSize){                       //=== SELECTION SORT =====

    for (int i = 1; i < DataSize; ++i) {                            //Traverse each element 

        int Key = Data[i];                                          //Lets put the key
        int j = i - 1;                                              //Let m = Datasize[0..i-1]

        while (j >= 0 && Key < Data[j]) {                           //Move elements of m
            Data[j + 1] = Data[j];                                  //to one element ahead
            j--;                                                    //for each element of m
        }

        Data[j + 1] = Key;                                          //Put there Datasize
    }
}