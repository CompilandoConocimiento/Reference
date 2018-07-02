/*================================================================
=====        LONGEST INCREASING SUBSEQUENCE          =============
================================================================*/
#include <iostream>                                                 //Include Libraries
#include <vector>                                                   //Include Libraries
#include <algorithm>                                                //Include Libraries
using namespace std;                                                //Bad practice

/*========================================
==========      DP LIS          ==========
========================================*/
int DynamicProgrammingLIS(vector<int> &Data) {                      //DP Solution
    vector<int> DPArray(Data.size(), 1);                            //Create a temporal array
 
    for (int i = 1; i < Data.size(); i++)                           //Foreach element in data
        for (int j = 0; j < i; j++)                                 //Check all element before
            if (Data[i] > Data[j] and DPArray[i] < DPArray[j] + 1)  //If is smaller
                DPArray[i] = DPArray[j] + 1;                        //Add one to the count
 
    return *max_element(DPArray.begin(), DPArray.end());            //Return the max element
}


int main() {                                                        //Call main

    int n; cin >> n;                                                //Get n numbers
    vector<int> Data(n);                                            //Get the a [1, ..., n]
    for (int i = 0; i < n; ++i) cin >> Data[i];                     //Get the data

    cout << DynamicProgrammingLIS(Data) << "\n";                    //Call the vector data
    return 0;                                                       //Go out!
}