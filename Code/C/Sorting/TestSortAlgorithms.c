#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "AuxFunctions.c"
#include "SortWithBST.c"

// ==============================================
// ============     MAIN        =================
// ==============================================
int main() {

    int OriginalData[] = {1, 4, 2, 5, 3, 12, 0};    //This is the Data
    int DataSize = 7;                               //Size

    PrintArray(OriginalData, DataSize);             //Show the data
    SortWithBST(OriginalData, DataSize);                  //Bubble Sort

    printf("\n\n\n");                               //Now space
    PrintArray(OriginalData, DataSize);             //Now sorted

    return 0;                                        //Bye friends
}
