/*=============================================================================================================
====================================   MATH FUNCTION FOR HUMANITY    ==========================================
=============================================================================================================*/
#include <iostream>                                                         //Include Libraries
#include <math.h>                                                           //Include Libraries
#include <vector>                                                           //Include Libraries
using namespace std;                                                        //Bad practice, dont do it kids!


/*===================================================================
=====================      SELECTION SORT       =====================
===================================================================*/
template <class T>
vector<T> BubbleSort(vector<T> Data){                                   //=== BUBBLE SORT ========

    for (int n = Data.size(); n > 0; --n)                               //For each element in array
        for (int i = 0; i < (n - 1); ++i)                               //Optimization
            if (Data[i] > Data[i + 1]) std::swap(Data[i], Data[i + 1]); //If incorrect swap

    return Data;                                                        //Return the new data
}


// ==============================================
// ============     MAIN        =================
// ==============================================
int main() {

    // ====== SECTION: ALL THE DATA FOR ALGORITHMS ========  
    vector<int> OriginalData = {1, 4, 2, 5, 3};                         //This is the Original Data
    for (auto x : OriginalData) cout << "[" << x << "] ";               //Show me the Original Data

    //=== SELECTION SORT ========
    vector<int> OrderData = BubbleSort<int> (OriginalData);             //Selection Sort

    // ====== SECTION: ALL THE DATA FOR ALGORITHMS ========  
    cout << "\n";                                                       //Some space
    for (auto x : OrderData) cout << "[" << x << "] ";                  //Show me the Order Data

    return 0;                                                           //Bye friends
}
