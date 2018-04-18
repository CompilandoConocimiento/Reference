/*================================================================
=======================     FIBONACCI       ======================
================================================================*/
#include <iostream>                                                 //Include Libraries
#include <vector>                                                   //Include Libraries
using namespace std;                                                //Bad practice


template <class T>                                                  //Templates for all
T StupidFibonacci (T n) {                                           //Stupid Fibonacci
    if (n == 0) return 0;                                           //Initial form  
    if (n == 1) return 1;                                           //Initial form  
    else return StupidFibonacci(n - 1) + StupidFibonacci(n - 2);    //Recursive form
}

template <class T>                                                  //Templates for all
T DynamicProgrammingFibonacci (T n) {                               //Cool Fibonacci
    
    T DataStore[n + 1];                                             //Create an array 
    DataStore[0] = 0;                                               //Initial form
    DataStore[1] = 1;                                               //Initial form

    for (T i = 2; i <= n; i++)                                      //For each value to n
        DataStore[i] = DataStore[i - 1] + DataStore[i - 2];         //Create sote value

    return DataStore[n];                                            //return the result
}


int main() {

    cout << StupidFibonacci<int>(40) << "\n";                       //Try StupidFibonacci                      
    cout << DynamicProgrammingFibonacci<int>(40) << "\n";           //Try DP Fibonacci                      

    return 0;
}