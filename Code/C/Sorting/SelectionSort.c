/*===================================================================
==================      SELECTION SORT          =====================
===================================================================*/

/**
 * Select the lowest value for each index
 * Ok, so it in escence we find the smallest data, then we put it
 * at the begging, next me only have to sort the array starting
 * in the next position, so we do the same thing another time
 * 
 * @param Data      A pointer to the array of int to sort
 * @param DataSize  The size of the Data array
 * @return          Nothing...I'm modifying the raw data
 */

void SelectionSort(int Data[], int DataSize){                       //=== SELECTION SORT =====

    for (int i = 0; i < DataSize - 1; ++i) {                        //For each index in the Size
        int TiniestIndex = i;                                       //Check the actual index
        for (int j = i + 1; j < DataSize; ++j)                      //Lets check if is the tinest
            if (Data[j] < Data[TiniestIndex])                       //If there's someone smallest
                TiniestIndex = j;                                   //Change the index
                
        Swap(&Data[TiniestIndex], &Data[i]);                        //Swap the tiniest data
    }
}
