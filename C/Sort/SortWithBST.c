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

#include "TreeAuxFunction.c"
/*===================================================================
==================           BST SORT           =====================
===================================================================*/

/**
 * Ok, i don't have much to say, we will put it in a Binary Search Tree
 * ant the transverse it, that's it!
 * 
 * @param Data      A pointer to the array of int to sort
 * @param DataSize  The size of the Data array
 * @return          Nothing...I'm modifying the raw data
 */
void SortWithBST(int Data[], int DataSize) {                        //=== BST SORT ======
	Node* Tree = NULL;                                              //Start with empty tree

	for(int i = 0; i < DataSize; i++)                               //For each element
		IterativeInsertBST(&Tree, Data[i]);                         //Insert in tree

	IterativeCreateInOrder(&Tree, Data, DataSize);                  //Transverse it!
}