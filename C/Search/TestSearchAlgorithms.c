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
 * @compile "gcc -std=c11 Time.c TestSearchAlgorithms.c -o TestSearchAlgorithms - pthread"
 * @run "./TestSearchAlgorithms DataSize NumAlgorithm NumberOfCases Cases OutputPlace < Input.txt"
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

#include "Time.h"

#include "LinealSearch.c"
#include "BinarySearch.c"
#include "SearchInBST.c"

// ==============================================
// ============     MAIN        =================
// ==============================================
/**
 * This is the control program to check all the other
 * search algorithms.
 * 
 * @param argc      Size of elements of argv
 * @param argv[0]   Name of the program   
 * @param argv[1]   Size of the array to get   
 * @param argv[2]   Algorithm number
 * @param argv[3]   Number of Cases
 * @param argv[4]   Number of Cases File Path 
 * @param argv[5]   Output File Path
 * @return          (Int)A zero if all OK
 */

int main(int argc, char const *argv[]) {

    // GET CONSOLE DATA
    int DataSize = atoi(argv[1]);                                   //Get the DataSize
    int NumAlgorithm = atoi(argv[2]);                               //Get the NumAlgorithm
    int NumberOfCases = atoi(argv[3]);                              //Get the NumberOfCases

    FILE *CasesFile = fopen(argv[4], "r");                          //Cases
    FILE *FileName = fopen(argv[5], "w");                           //Open the file


    // GET CASES DATA
    int NumbersToSearch[NumberOfCases];                             //Get the space
    for (int i = 0; i < NumberOfCases; ++i)                         //Foreach number
        fscanf(CasesFile, "%i", &NumbersToSearch[i]);               //Read the case

    // GET THE ARRAY DATA
    int *Data = 
            (int*) malloc(DataSize*sizeof(int));                    //Reserve data

    for (int i = 0; i < DataSize; ++i)                              //For each number
        scanf("%i", &Data[i]);                                      //Get the number

    // CREATE THE TREE
    Node* Tree = NULL;                                              //Create the Tree    
    if (NumAlgorithm == 4)                                          //Create the Tree
        Tree = CreateBSTFromSortedArray(Data, DataSize);            //Create the BTS tree

    // === NOW SEARCH THE DATA ========
    double UserTimeStart, SysTimeStart, WallTimeStart;              //Start variables
    double UserTimeEnd, SysTimeEnd, WallTimeEnd;                    //End variables

    

    // FOR EACH CASE
    for (int i = 0; i < NumberOfCases; ++i) {                       //For each case

        uswtime(&UserTimeStart, &SysTimeStart, &WallTimeStart);     //START COUNTING

        int Tmp, ToSearch = NumbersToSearch[i];                     //Find the search number

        if (NumAlgorithm == 0)                                      //0 is LinealSearch
            Tmp = LinealSearch(Data, DataSize, ToSearch);           //Lineal Search
        if (NumAlgorithm == 1)                                      //1 is Paralell Lineal Search
            Tmp = ParalellLinealSearch(Data, DataSize, ToSearch,4); //Paralell Lineal Search
        if (NumAlgorithm == 2)                                      //2 is Binary Search
            Tmp = BinarySearch(Data, DataSize, ToSearch);           //Binary Search
        if (NumAlgorithm == 3)                                      //3 is Binary Search
            Tmp = ParalellBinarySearch(Data, DataSize, ToSearch,4); //Search Paralell Binary Search
        if (NumAlgorithm == 4)                                      //4 is BST Search
            Tmp = SearchWithBST(Tree, ToSearch);                    //Search with BST

        uswtime(&UserTimeEnd, &SysTimeEnd, &WallTimeEnd);           //END THE COUNT

        // === NOW SHOW THE DATA ========
        double UserTime = UserTimeEnd - UserTimeStart;              //Get difference     
        double SysTime  = SysTimeEnd - SysTimeStart;                //Get difference
        double RealTime = WallTimeEnd - WallTimeStart;              //Get difference 

        printf("%.10f %.10f %.10f\n", RealTime, UserTime, SysTime); //Print it!

        if (Tmp == -1)                                              //If not find it
            fprintf(FileName,"Do not find %i\n",NumbersToSearch[i]);//Print it!
        else                                                        //If find it!        
            fprintf(FileName, "Find %i at %i\n", 
                                NumbersToSearch[i], Tmp);           //Print it! 
    }

    fclose(FileName);                                               //Close the name

    return 0;                                                       //Bye friends
}