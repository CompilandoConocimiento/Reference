/*================================================================
==============     CLOSEST PAIR OF POINTS    =====================
================================================================*/
#include <stdio.h>                                                      //Include Libraries
#include <set>

using namespace std;                                                        //Bad practice

typedef long long int lli;

template <class T>  
inline void GetNumber(T &Number) {                                      //Super cool way to read llis
    
    Number = 0;                                                         //Set to 0
    T NumberSign = 1;                                                   //Sign all ok
    char CurrentChar = getchar_unlocked();                              //Read a char
 
    while (CurrentChar < '0' or CurrentChar > '9') {                    //If we are not reading numbers
        if (CurrentChar == '-')  NumberSign = -1;                       //If we have found the sign
        CurrentChar = getchar_unlocked();                               //Read the next char
    }

    while (CurrentChar >= '0' and CurrentChar <= '9') {                 //While we read numbers
        Number = (Number << 3) + (Number << 1) + CurrentChar - '0';     //Multiply by 10
        CurrentChar = getchar_unlocked();                               //Read the next char
    }

    Number *= NumberSign;                                               //If negative
}


lli  MergeSort(lli Data[], lli Temporal[], lli Left, lli Right);			//Declarations
lli Merge(lli Data[], lli Temporal[], lli Left, lli Middle, lli Right);		//Declarations
 

lli CountInversions(lli Data[], lli Size) {									//Count the inversions
	lli Temporal[Size];														//Create temporal array
    return MergeSort(Data, Temporal, 0, Size - 1);							//Call merge
}
 
lli MergeSort(lli Data[], lli Temporal[], lli Left, lli Right) {			//Return num of inversions
	
	lli Middle, NumInversions = 0;											//Local vars
  
	if (Right > Left) {														//If all ok
		
		Middle = (Right + Left) / 2;										//Middle

	    NumInversions  = MergeSort(Data, Temporal, Left, Middle);			//Find the left
	    NumInversions += MergeSort(Data, Temporal, Middle + 1, Right);		//Find the right
	 
	    NumInversions += Merge(Data, Temporal, Left, Middle + 1, Right);	//Find in the middle
	}
	
	return NumInversions;													//Return it!

}


lli Merge(lli Data[], lli Temporal[], lli Left, lli Middle, lli Right) {	//Return the middle

	lli NumInversions = 0;													//The return var
	lli i = Left, j = Middle, k = Left;										//Local vars

	while ((i <= Middle - 1) and (j <= Right)) {							//While we can
		if (Data[i] <= Data[j]) Temporal[k++] = Data[i++];					//If no inversions
		else {
			Temporal[k++] = Data[j++];										//Add the inversion
		  	NumInversions += (Middle - i);									//Add it
		}
	}
 
	while (i <= Middle - 1) Temporal[k++] = Data[i++];						//Move the other
 	while (j <= Right) Temporal[k++] = Data[j++];							//Move the others
	
	for (i = Left; i <= Right; i++) Data[i] = Temporal[i];					//Move
 
	return NumInversions;													//Add inversions
}
 



/*========================================
==========        MAIN           =========
========================================*/
int main() {

	lli TestCases;
	GetNumber<lli>(TestCases);

	for (lli i = 0; i < TestCases; ++i) {
		
		lli Size;
		GetNumber<lli>(Size);


		lli Data[Size];
		for (lli j = 0; j < Size; ++j) {
			GetNumber<long long int>(Data[j]);
		}

		printf("%lld\n", CountInversions(Data, Size));
	}

    return 0;
}