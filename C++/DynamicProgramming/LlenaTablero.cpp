/*================================================================
=======================     JUMP            ======================
==================================================================

READ: https://omegaup.com/arena/problem/LLenaTablero#problems   

    !!!!!!!!!!!!!!!!!!!   NOT READY   !!!!!!!!!!!!!

*/

#include <iostream>                                                     //Include Libraries
#include <vector>                                                       //Include Libraries
using namespace std;                                                    //Bad practice

vector< vector<bool> > Data;                                            //Sorry, really, really sorry

int main() {

    int M, N;
    cin >> N >> M;

    for (int i = 0; i < N; ++i) {

        vector<bool> MiniData(M);
        char Temporal;

        for (int j = 0; j < M; ++j) {
            cin >> Temporal;
            MiniData[j] = (Temporal == '.')? true : false;
        }

        Data.push_back(MiniData);
    }

    for (auto x : Data) {
        for (auto point : x) {
            auto NewPoint = point? "." : "#";
            cout << NewPoint << " ";
        }
        cout << "\n";
    }

    return 0;
}