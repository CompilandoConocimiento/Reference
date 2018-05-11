/*================================================================
==========         LARGEST SUM CONTIGOUS SUBARRAY      ===========
================================================================*/
#include <iostream>                                                     //Include Libraries
#include <vector>                                                       //Include Libraries
using namespace std;                                                    //Bad practice


/*========================================
==========   MAX SUBARRAY SUM    =========
========================================*/
template <class T>                                                      //Templates for all
long long int MaxSubArraySum(vector<T> &Data) {                         //Function
   
   T MaximumContiguosSum = Data[0];                                     //Local vars
   T CurrentMaxSum = Data[0];                                           //Local vars

   for (int i = 1; i < Data.size(); ++i) {                              //For each element FROM 1
        if (Data[i] > CurrentMaxSum + Data[i])                          //What is better
            CurrentMaxSum = Data[i];                                    //just take current
        else CurrentMaxSum += Data[i];                                  //or add it to subarray

        if (CurrentMaxSum > MaximumContiguosSum)                        //If we fin new maximum
            MaximumContiguosSum = CurrentMaxSum;                        //Add it!
    }

    return MaximumContiguosSum;                                         //Return it!
}

