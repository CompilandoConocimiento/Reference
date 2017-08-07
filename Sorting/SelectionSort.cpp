/*=============================================================================================================
====================================   MATH FUNCTION FOR HUMANITY    ==========================================
=============================================================================================================*/
#include <iostream>                                                                     //Include Libraries
#include <math.h>                                                                       //Include Libraries
#include <vector>                                                                       //Include Libraries
using namespace std;                                                                    //Bad practice, dont do it kids!

typedef unsigned long long ull;                                                         //Just a so long name, sorry
typedef long long lli;                                                                  //Just a so long name, sorry


/*===================================================================
=====================      SELECTION SORT       =====================
===================================================================*/

/* ********* SELECT THE LOWEST VALUE FOR EACH INDEX *****************
HOW THIS DOES IT:
Ok, so it in escence we find the smallest data, then we put it at the begging,
Next me only have to sort the array starting in the next position, so we do the same thing another time
*/
vector<lli> SelectionSort(vector<lli> Data){                                            //=== SELECTION SORT ========
    lli SmallestIndex;                                                                  //This will store the lowest value index
    lli ActualIndex;                                                                    //This will store the actual value
    lli Size = Data.size();                                                             //This is literlly the limit

    for (SmallestIndex = 0; SmallestIndex < Size; ++SmallestIndex){                     //Supose the smallest value is the first
        for (ActualIndex = SmallestIndex + 1; ActualIndex < Size; ++ActualIndex){       //For each value in the array:
            if (Data[SmallestIndex] > Data[ActualIndex]){                               //Is there any smallest value?
                lli Temporal = Data[SmallestIndex];                                     //The Swap it!
                Data[SmallestIndex] = Data[ActualIndex];                                //The Swap it!
                Data[ActualIndex] = Temporal;                                           //The Swap it!
            }
        }
    }

    return Data;                                                                        //Return the new data
}


// ==============================================
// ============     MAIN        =================
// ==============================================
int main(){

    // ====== SECTION: ALL THE DATA FOR ALGORITHMS ========  
    vector<lli> OriginalData = {1,4,2,5,3};                                             //This is the Original Data
    vector<lli> OrderData;                                                              //This is the New and Order Data

    for (auto x : OriginalData) cout << "[" << x << "] ";                               //Show me the Original Data




    //=== SELECTION SORT ========
    OrderData = SelectionSort(OriginalData);
    






    // ====== SECTION: ALL THE DATA FOR ALGORITHMS ========  
    cout << "\n\n\n";                                                                   //Some space
    for (auto x : OrderData) cout << "[" << x << "] ";                                  //Show me the Order Data

    return 0;                                                                           //Bye friends
}



