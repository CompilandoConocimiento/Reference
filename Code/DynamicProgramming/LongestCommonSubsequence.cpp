/*================================================================
=========        LONGEST COMMON SUBSEQUENCE          =============
================================================================*/
#include <string>                                                   //Include Libraries
#include <algorithm>                                                //Include Libraries
using namespace std;                                                //Bad practice

// ***********     DYNAMIC LCS    *************
int DynamicProgrammingLCS (string &A, string &B) {                  //Cool LIS
    int Table [A.size() + 1][B.size() + 1];                         //Table

    for (int i = 0; i <= A.size(); ++i) {                           //Foreach word in A
        for (int j = 0; j <= B.size(); ++j) {                       //Foreach word in B
            if (i == 0 or j == 0) Table[i][j] = 0;                  //If no word check, put 0
            else if (A[i - 1] == B[j - 1])                          //If equals then
                Table[i][j] = 1 + Table[i-1][j-1];                  //Then check th previous
            else                                                    //if not equals
                Table[i][j] = max(Table[i-1][j], Table[i][j-1]);    //Move the max of the 2
        }
    }

    return Table[A.size()][B.size()];                               //Return the bigger
}
