/*================================================================================================
====================     BINARY SEARCH FUNCTION FOR HUMANITY       ===============================
================================================================================================*/

#include <math.h>                                                  			//Include Libraries
#include <stdlib.h>                                                   		//Include Libraries
#include <iostream>                                                   		//Include Libraries
#include <vector>                                                     		//Include Libraries
using namespace std;                                                  		//Bad practice, dont do it kids!

typedef unsigned long long ull;                                       		//Just a so long name, sorry
typedef long long lli;                                                		//Just a so long name, sorry

// ******************* BINARY SEARCH ************************
lli BinarySearch
(lli Initial, lli Final, vector<lli>& List, lli ElementToFind) {			//FN: A classic BinarySearch
	lli SearchPosition = Initial + ((Final - Initial) / 2);					//Find a new SearchPosition

	if (Final == Initial) return -1;										//Ok, there is not elements

	if (ElementToFind < List[SearchPosition])								//If it's in the right part
		return BinarySearch(Initial, SearchPosition, List, ElementToFind);	//Go there
	else if (ElementToFind > List[SearchPosition])							//If it's in the right part
		return BinarySearch(SearchPosition+1, Final, List, ElementToFind);	//Go there
	else return SearchPosition;												//If you find it already
}


lli BinarySearch(vector<lli>& List, lli ElementToFind){						//For comodity
	return BinarySearch(0, List.size()-1, List, ElementToFind);				//Initial Call
}


// ######################################################################
// ##################          MAIN         #############################
// ######################################################################
int main() {

	lli ElementToFind, Size = 100;											//Create variables

	vector<lli> ListForSearch(Size);										//Create the vector and fill it		
	for (lli i = 0; i < Size; ++i) ListForSearch[i] = i;					//Create the vector and fill it

	cout << BinarySearch(ListForSearch, 101);								//Call it!

	return 0;
}