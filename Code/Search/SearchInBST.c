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

#include "TreeAuxFunction.c"


/*===================================================================
==================           BST SEARCH         =====================
===================================================================*/
/**
 * Just search like in a BTS, note that a node save the number and
 * the index of the number in the original array
 * 
 * @param Tree      A pointer to a node; the root of a tree
 * @param ToSearch  The number to search
 * @return          The index of the number in the Original Array
 */
int SearchWithBST(Node* Tree, int ToSearch) {                       //=== BST SEACH ======
    Node **NewNode = &Tree;                                         //Let start at root

    while (*NewNode != NULL) {                                      //While are not at a leaf

        if ((*NewNode)->NodeItem == ToSearch)                       //If we found it!
            return (*NewNode)->Index;                               //return the index

        NewNode = (ToSearch < (*NewNode)->NodeItem)?                //We have to move right
            &((*NewNode)->Left): &((*NewNode)->Right);              //Move left or right 
    }

    return -1;                                                      //Not found!
}
