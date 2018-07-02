/*================================================================================================
====================     BINARY SEARCH FUNCTION FOR HUMANITY       ===============================
================================================================================================*/

#include <iostream>                                                     //Include Libraries
#include <vector>                                                       //Include Libraries
using namespace std;                                                    //Bad practice, dont do it kids!


// ******************* BINARY SEARCH ************************
int BinarySearch
(int Initial, int Final, vector<int>& List, int ElementToFind) {        //FN: A classic BinarySearch

    if (Final < Initial) return -1;                                     //Ok, there is not elements
    
    int Middle = Initial + (Final - Initial) / 2;                       //Find a new SearchPosition
    if (ElementToFind == List[Middle]) return Middle;                   //I find it daddy!

    if (ElementToFind < List[Middle])                                   //If it's in the right part
        return BinarySearch(Initial, Middle - 1, List, ElementToFind);  //Go there
    
    if (ElementToFind > List[Middle])                                   //If it's in the right part
        return BinarySearch(Middle + 1, Final, List, ElementToFind);    //Go there
}


int BinarySearch(vector<int>& List, int ElementToFind){                 //For comodity
    return BinarySearch(0, List.size() - 1, List, ElementToFind);       //Initial Call
}


// ######################################################################
// ##################          MAIN         #############################
// ######################################################################
int main() {

    int ElementToFind, Size = 100;                                      //Create variables

    vector<int> ListForSearch(Size);                                    //Create the vector and fill it 
    for (int i = 0; i < Size; ++i) ListForSearch[i] = i;                //Create the vector and fill it

    cout << BinarySearch(ListForSearch, 101);                           //Call it!

    return 0;
}