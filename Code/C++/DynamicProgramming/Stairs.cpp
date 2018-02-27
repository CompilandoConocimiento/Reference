/*================================================================
=======================     JUMP            ======================
==================================================================

READ: https://omegaup.com/arena/problem/Escalera#problems

*/
#include <iostream>                                                     //Include Libraries
#include <vector>                                                       //Include Libraries
using namespace std;                                                    //Bad practice

long long int NumberOfStairs, MaxJumpSize;                              //Sorry, really, really sorry

template <class T>                                                      //Templates for all
T StupidJumps (T ActualStair, vector<T> &Table) {                       //======== STUPID SOLUTION =========
    
    if (ActualStair > NumberOfStairs)  return 0;                        //If we are over 
    if (ActualStair == NumberOfStairs) return 1;                        //If we are at the limit

    int Count = 0;                                                      //Start at zero
    for (int NewJump = 1; NewJump <= MaxJumpSize; ++NewJump) {          //Add each possible jump
        Count += Jumps(ActualStair + NewJump);                          //Add it!
    }

    return Count;                                                       //Return it!
}

template <class T>                                                      //Templates for all
T Jumps (T ActualStair, vector<T> &Table) {                             //======== ITERATIVE SOLUTION ======
    
    if (ActualStair > NumberOfStairs)  return 0;                        //If we are over 
    if (ActualStair == NumberOfStairs) return 1;                        //If we are at the limit

    if (Table[ActualStair] != -1) return Table[ActualStair];            //If we have already solve it!

    Table[ActualStair] = 0;                                             //Supose zero
    for (T NewJump = 1; NewJump <= MaxJumpSize; ++NewJump) {            //For each possible jump
        Table[ActualStair] += Jumps(ActualStair + NewJump, Table);      //Add it to the result
    }

    return Table[ActualStair];                                          //This is the result
}


int main() {                                                            // ======== MAIN ==============

    cin >> NumberOfStairs >> MaxJumpSize;                               //Read data
    vector<long long int> Table(NumberOfStairs + 1, -1);                //Create DP table

    cout << Jumps<long long int>(0, Table) << "\n";                     //Call the Function

    return 0;
}