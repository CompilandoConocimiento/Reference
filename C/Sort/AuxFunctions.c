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
=====================      TEMPORAL SWAP        =====================
===================================================================*/
/**
 * Inline function to no create new function stack call to swap
 * elements 
 * 
 * @param A     A pointer to an int
 * @param B     A pointer to an int
 * @return      Nothing...
 */
extern inline void Swap(int *A, int *B) {
	int Temporal;                                               //Create a Temporal var

	Temporal = *A;                                              //Tem <- A
	*A = *B;                                                    //A   <- B
	*B = Temporal;                                              //B   <- Tem
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
 * @param FileName  A pointer to a file to write the array
 * @return          Nothing...
 */
extern inline void fPrintArray(
	int Data[], int DataSize, FILE * FileName) {                    //Long parameters

	for (int i = 0; i < DataSize; ++i)                              //Foreach element:
		fprintf(FileName, "%i \n", Data[i]);                        //Print it!

}