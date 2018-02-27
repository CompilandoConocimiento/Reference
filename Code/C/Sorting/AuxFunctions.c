/*===================================================================
=====================      TEMPORAL SWAP        =====================
===================================================================*/
/**
 * Inline function to no create new function stack call to swap
 * elements 
 * 
 * @param A     A pointer to an int
 * @param B     B pointer to an int
 * @return      Nothing...I'm modifying the raw data
 */
extern inline void Swap(int *A, int *B) {
    int Temporal;

    Temporal = *A;
    *A = *B;
    *B = Temporal;
}

/*===================================================================
=====================      PRINT ARRAY          =====================
===================================================================*/
/**
 * Inline function to no create new function stack call to print
 * the array
 * 
 * @param Data      A pointer to the array of int to sort
 * @param DataSize  The size of the Data array
 * @return          Nothing...I'm modifying the raw data
 */
extern inline void PrintArray(int Data[], int DataSize) {
    for (int i = 0; i < DataSize; ++i) 
        printf("%i ", Data[i]);
    printf("\n");
}