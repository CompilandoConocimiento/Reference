/*=============================================================================================================
====================================   MATH FUNCTION FOR HUMANITY    ==========================================
=============================================================================================================*/
#include <iostream>                                                                         //Include Libraries
#include <math.h>                                                                           //Include Libraries
#include <vector>                                                                           //Include Libraries
using namespace std;                                                                        //Bad practice, dont do it kids!


/*===================================================================
=====================      SELECTION SORT       =====================
===================================================================*/

/* ********* SELECT THE LOWEST VALUE FOR EACH INDEX *****************
HOW THIS DOES IT:
Ok, so it in escence we find the smallest data, then we put it at the begging,
Next me only have to sort the array starting in the next position, so we do
the same thing another time
*/
template <class T>
vector<T> SelectionSort(vector<T> Data){                                                    //=== SELECTION SORT ========

    for (T SmallestIndex = 0, ActualIndex; SmallestIndex < Data.size(); ++SmallestIndex) {  //Supose the smallest value is the first
        for (ActualIndex = SmallestIndex + 1; ActualIndex < Data.size(); ++ActualIndex) {   //For each value in the array:
            if (Data[SmallestIndex] > Data[ActualIndex]) {                                  //Is there any smallest value?
                T Temporal = Data[SmallestIndex];                                           //The Swap it!
                Data[SmallestIndex] = Data[ActualIndex];                                    //The Swap it!
                Data[ActualIndex] = Temporal;                                               //The Swap it!
            }
        }
    }

    return Data;                                                                            //Return the new data
}


// ==============================================
// ============     MAIN        =================
// ==============================================
int main() {

    // ====== SECTION: ALL THE DATA FOR ALGORITHMS ========  
    vector<int> OriginalData = {1, 4, 2, 5, 3};                                             //This is the Original Data
    for (auto x : OriginalData) cout << "[" << x << "] ";                                   //Show me the Original Data

    //=== SELECTION SORT ========
    vector<int> OrderData = SelectionSort<int> (OriginalData);                              //Selection Sort

    // ====== SECTION: ALL THE DATA FOR ALGORITHMS ========  
    cout << "\n";                                                                           //Some space
    for (auto x : OrderData) cout << "[" << x << "] ";                                      //Show me the Order Data

    return 0;                                                                               //Bye friends
}



