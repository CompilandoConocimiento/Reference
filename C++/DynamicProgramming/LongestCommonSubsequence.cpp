/*================================================================
=====        LONGEST INCREASING SUBSEQUENCE          =============
================================================================*/
#include <iostream>                                                 //Include Libraries
#include <string>                                                   //Include Libraries
#include <vector>                                                   //Include Libraries
using namespace std;                                                //Bad practice


/*========================================
==========      DP LIS          =========
========================================*/
int DynamicProgrammingLIS (string &A, string &B) {                  //Cool LIS
    int Table [A.size() + 1][B.size() + 1];                         //Table

    for (int i = 0; i <= A.size(); ++i) {                           //For each char
        for (int j = 0; j <= B.size(); ++j) {                       //For each char
            if (i == 0 or j == 0) Table[i][j] = 0;                  //Start
            else if (A[i - 1] == B[j - 1])                          //If equals, add it
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
int StupidLIS (string &A, string &B, int i, int j) {                //Not Cool LIS
    if (i == 0 or j == 0) return 0;                                 //If at start
    if (A[i] == B[j]) return 1 + StupidLIS(A, B, i-1, j-1);         //If equals
    return max(StupidLIS(A, B, i-1, j), StupidLIS(A, B, i, j-1));   //Return maximum
}

int main() {
    string A, B; cin >> A >> B;                                     //Read data
    cout << DynamicProgrammingLIS(A, B) << "\n";                    //Try DP LSI 

    return 0;
}