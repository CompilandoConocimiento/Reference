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
 * @compile "gcc -std=c11 Time.c TestSortAlgorithms.c -o TestSortAlgorithms"
 * @run "./TestSortAlgorithms n NumAlgorithm OutputPlace < Input10Million.txt"
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "Time.h"

#include "AuxFunctions.c"
#include "BubbleSort.c"
#include "SelectionSort.c"
#include "InsertionSort.c"
#include "ShellSort.c"
#include "SortWithBST.c"

// ==============================================
// ============     MAIN        =================
// ==============================================
/**
 * This is the control program to check all the other
 * sort algorithms.
 * 
 * @param argc      Size of elements of argv
 * @param argv[0]   Name of the program   
 * @param argv[1]   Size of the array to get   
 * @param argv[2]   Number of the algorithm
 * @param argv[3]   Output File Path
 * @return          (Int)A zero if all OK
 */

int main(int argc, char const *argv[]) {

	// === READ AND GET THE DATA  ====
	if (argc < 3) exit(0);                              //Simple check
	
	int DataSize = atoi(argv[1]);                       //Get the DataSize
	int Algorithm = atoi(argv[2]);                      //Get the Algorithm

	double UserTimeStart, SysTimeStart, WallTimeStart;  //Start variables
	double UserTimeEnd, SysTimeEnd, WallTimeEnd;        //End variables

	FILE * FileName = fopen (argv[3], "w");             //Open the file

	int *OriginalData = 
			(int*) malloc(DataSize*sizeof(int));        //Reserve data

	for (int i = 0; i < DataSize; ++i)                  //For each number
		scanf("%i", &OriginalData[i]);                  //Get the number

	// === NOW SORT THE DATA ========
	uswtime(&UserTimeStart, 
			&SysTimeStart,
			&WallTimeStart);                            //START COUNTING

	if (Algorithm == 0)                                 //0 is Bubble Sort
		BubbleSortv1(OriginalData, DataSize);           //Bubble Sort
	else if (Algorithm == 1)                            //1 is Bubble Sort v2
		BubbleSortv2(OriginalData, DataSize);           //Bubble Sort v2
	else if (Algorithm == 2)                            //2 is Bubble Sort v3
		BubbleSortv3(OriginalData, DataSize);           //Bubble Sort v3
	else if (Algorithm == 3)                            //3 is SelectionSort
		SelectionSort(OriginalData, DataSize);          //SelectionSort
	else if (Algorithm == 4)                            //4 is InsertionSort
		InsertionSort(OriginalData, DataSize);          //InsertionSort
	else if (Algorithm == 5)                            //5 is ShellSort
		ShellSort(OriginalData, DataSize);              //ShellSort
	else if (Algorithm == 6)                            //6 is SortWithBST
		SortWithBST(OriginalData, DataSize);            //SortWithBST

	uswtime(
		&UserTimeEnd,
		&SysTimeEnd,
		&WallTimeEnd);                                  //END THE COUNT

	// === NOW SHOW THE DATA ========
	double RealTime = WallTimeEnd - WallTimeStart;      //Get difference 
	double UserTime = UserTimeEnd - UserTimeStart;      //Get difference     
	double SysTime  = SysTimeEnd - SysTimeStart;        //Get difference

	printf("%.10f %.10f %.10f", RealTime, UserTime, SysTime);
	
	// === NOW CREATE THE DATA ========
	fPrintArray(OriginalData, DataSize, FileName);      //Now sorted
	fclose(FileName);                                   //Close the name

	return 0;                                           //Bye friends
}