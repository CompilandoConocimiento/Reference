/*================================================================
=====        LONGEST INCREASING SUBSEQUENCE          =============
================================================================*/
#include <iostream>                                                 //Include Libraries
#include <string>                                                   //Include Libraries
#include <string.h>                                                 //Include Libraries
using namespace std;                                                //Bad practice


typedef unsigned long long int ull;                                 //Mini name

/*========================================
==========      DP LIS          =========
========================================*/
ull DynamicProgrammingLIS (string &A, string &B) {                  //Cool LIS

    ull Table [A.size() + 1][B.size() + 1];                         //Table
    memset(Table, 0, A.size() + B.size() + 2);                      //Start at 0

    for (int i = 1; i < A.size() + 1; ++i) {                        //For each char
        for (int j = 1; j < B.size() + 1; ++j) {                    //For each char
            if (A[i] == B[j])                                       //If equals, add it
                Table[i][j] = 1 + Table[i-1][j-1];                  //Move the 2 pointers
            else                                                    //if not equals
                Table[i][j] = max(Table[i-1][j], Table[i][j-1]);    //Move the max of the 2
        }
    }

    return Table[A.size()][B.size()];                               //Return the bigger
}


/*========================================
==========      BAD LIS          =========
========================================*/
ull StupidLIS (string &A, string &B, ull i, ull j) {                //Not Cool LIS
    if (i == 0 or j == 0) return 0;                                 //If at start
    if (A[i] == B[j]) return 1 + StupidLIS(A, B, i-1, j-1);         //If equals
    return max(StupidLIS(A, B, i-1, j), StupidLIS(A, B, i, j-1));   //Return maximum
}

int main() {

    string A, B; cin >> A >> B;                                     //Read data
    cout << DynamicProgrammingLIS(A, B) << "\n";                    //Try DP LSI 

    return 0;
}