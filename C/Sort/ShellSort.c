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
=====================      SHELL SORT           =====================
===================================================================*/

/**
 * ShellSort is mainly a variation of Insertion Sort. 
 * In insertion sort, we move elements only one position ahead.
 * When an element has to be moved far ahead, many movements are involved.
 * The idea of shellSort is to allow exchange of far items. In shellSort, we
 * make the array h-sorted for a large value of h. We keep reducing the value
 * of h until it becomes 1. 
 * 
 * An array is said to be h-sorted if all sublists of every h’th element is sorted.
 * 
 * @param Data      A pointer to the array of int to sort
 * @param DataSize  The size of the Data array
 * @return          Nothing...I'm modifying the raw data
 */

void ShellSort(int Data[], int DataSize) {                          //=== SHELL SORT ======
	int Gap = DataSize >> 1;                                        //Let jump = DataSize / 2
																	
	while (Gap > 0) {                                               //Until entire data sort 

		for(int i = Gap; i < DataSize; i++) {                       //For each subarray
			
			int j = i;                                              //Let j = i to modify j
			int Temporal = Data[i];                                 //Temp. will be the next
			
			while (j >= Gap && Temporal < Data[j - Gap]) {          //shift earlier gap-sort
				Data[j] = Data[j - Gap];                            //until correct place
				j -= Gap;                                           //is found for Data[i]
			}

			Data[j] = Temporal;                                     //Temp. find their place
		}

		Gap >>= 1;                                                  //Reduce gap in half
	}
}