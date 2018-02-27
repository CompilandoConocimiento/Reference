#include <iostream>                                                     //Include Libraries
#include <vector>                                                       //Include Libraries
#include <math.h>                                                       //Include Libraries
using namespace std;                                                    //Bad practice



auto CheckHamming(vector<bool> Data, bool Show = true) {                //=== FUNCTION TO CHECK HAMMING ===

    int NumPairBits = ceil(log2((double)Data.size()));                  //Get the Number of Bits pairs

    int ErrorIndex = 0;                                                 //Suppose an error in ...

    for (int PairBit = 1, SumOfBit; PairBit <= NumPairBits; ++PairBit) {//For each bit bit

        int Count = 0;                                                  //Suppose the count is zero

        if (Show) cout << "Pair Bit is " << PairBit << " \t";           //Show the pair bit

        for (int index = 1; index <= Data.size(); ++index)              //Now find the count
            if ((index >> (PairBit - 1)) & 1)                           //If the pair bit is on 
                Count += Data[index - 1];                               //Add it the value of data

        if (Show) cout << "Count : " << Count;                          //Show the count
        if (Show) cout << ((Count % 2)? " Error: Inpair" : "") << "\n"; //Show the add bit

        if (Count % 2)                                                  //If the count is not pair
            ErrorIndex += (1 << (PairBit - 1));                         //Add to count 2^PairBit
    
    }

    if (ErrorIndex != 0) {                                              //If we have an error
        auto ErrorBit = Data[ErrorIndex - 1];                           //Get the error

        if (Show) cout << "Error: Bit #" << ErrorIndex;                 //Show the error
        if (Show) cout << " should be " << !ErrorBit << "\n";           //Show the error

        Data[ErrorIndex - 1] = !ErrorBit;                               //Reverse it!
    }
    
    return Data;                                                        //Return the new data

}

int main() {

    vector<bool> OriginalData = {
        0, 1, 1, 1,
        1, 0, 0, 1,
        0, 0, 0, 0,
        0, 0, 1, 0,
        1, 1, 1, 0,
        0, 0, 0, 0,
        1, 1, 1, 1,
        0, 1, 0, 1,
        1, 0, 0, 0,
        1, 1, 0, 1};


    auto NewData = CheckHamming(OriginalData);

    for (auto x : OriginalData) cout << x << " ";
    cout << "\n";

    for (auto x : NewData) cout << x << " ";
    cout << "\n";


    return 0;
}