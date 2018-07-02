/*===================================================================
==================    METADATA OF THE FILE      =====================
===================================================================*/
/**
 * @author  Rosas Hernandez Oscar Andres
 * @author  Alan Enrique Ontiveros Salazar
 * @author  Laura Andrea Morales 
 * @version 0.1
 * @team    CompilandoConocimiento
 * @date    4/03/2018
 */


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
void InsertionSort(int Data[], int DataSize){                       //= INSERTION SORT ===

	for (int i = 1; i < DataSize; ++i) {                            //Traverse each item

		int j = i;                                                  //A[0..i-1] is already sorted
		int Temp = Data[i];                                         //Let's find next item

		while (j > 0 && Temp < Data[j - 1]) {                       //Move elements of the subarray
			Data[j] = Data[j - 1];                                  //to one element ahead
			j--;                                                    //until we find the correct place
		}

		Data[j] = Temp;                                             //Put there the Temp
	}
}