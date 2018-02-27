/*===================================================================
=====================      BUBBLE SORT          =====================
===================================================================*/

/**
 * This is the most stupid (not counting stupid sort) no optimization
 * nothing, the raw algorithm.
 * 
 * For each element in the Array check if there are 2 contiguos 
 * elements that are in the wrong order, to swap it!
 * 
 * @param Data      A pointer to the array of int to sort
 * @param DataSize  The size of the Data array
 * @return          Nothing...I'm modifying the raw data
 */
void BubbleSortv1(int Data[], int DataSize) {                           //=== BUBBLE SORT ======
    for (int i = 1; i < DataSize; ++i) {                                //Do this Size - 1 times
        for (int j = 0; j < DataSize; ++j) {                            //Do this Size - 1 times
            if (Data[j - 1] > Data[j])                                  //If we need to swap it
                Swap(&Data[j - 1], &Data[j]);                           //Swap it!
        }
    }
}



/*===================================================================
=====================      BUBBLE SORT          =====================
===================================================================*/
/**
 * This is the most important optimization, reduce the second
 * loop because last i elements are already in place 
 *
 * @see BubbleSortv1
 */
void BubbleSortv2(int Data[], int DataSize) {
    for (int i = 0; i < DataSize - 1; i++) {                            //Do this Size - 1 times
        for (int j = 0; j < DataSize - i - 1; j++) {                    //All n-i-1 are sorted
            if (Data[j] > Data[j + 1])                                  //If we need to swap it
                Swap(&Data[j], &Data[j + 1]);                           //Swap it!
        }
    }
}


/*===================================================================
=====================      BUBBLE SORT          =====================
===================================================================*/
/**
 * This is the next most important optimization, break the seach
 * if is already sorted 
 *
 * @see BubbleSortv1
 */
void BubbleSortv3(int Data[], int DataSize) {

    for (int i = 0; i < DataSize - 1; i++) {                            //Do this Size - 1 times
        bool Swapped = false;                                           //Suposse no swap

        for (int j = 0; j < DataSize - i - 1; j++) {                    //Do this Size - 1 times
            if (Data[j] > Data[j + 1]) {                                //If we need to swap it
                Swap(&Data[j], &Data[j + 1]);                           //Swap it!
                Swapped = true;                                         //Upps! swap
            }
        }

        if (!Swapped) break;                                            //Break, is sorted!
    }
}
