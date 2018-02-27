/*================================================================
=======================     FIBONACCI       ======================
==================================================================
READ: 10020 - Minimal coverage
*/

#include <iostream>                                                 //Libraries
#include <vector>                                                   //Libraries
#include <utility>                                                  //Libraries

using namespace std;                                                //Bad practice

typedef vector< pair<int, int> > VectorPair;                        //Sorry, just a long name

/*
    =============================================================
    ============   FUNCTION: MINIMAL COVERAGE    ================
    =============================================================

    Args:
        Data: The [a, b] segments
        EndPlace: End of the Segment [0, EndPlace]
    Returns:
        VectorPair: The segments if last is {-1, -1} no solution
*/
VectorPair MinimalCoverage(VectorPair& Data, int EndPlace) {        //The solution function
    VectorPair Result;                                              //The Result vector

    pair<int, int> BestCase = {-1, -1};                             //Best segment up to date
    int WhereIAm = 0;                                               //Where I am da!!

    while (WhereIAm < EndPlace) {
        for (auto& segment : Data) {                                //For each segment [a, b]
            if (segment.first <= WhereIAm)                          //If  a <= WhereIAm < b
                if (WhereIAm < segment.second)                      //If  a <= WhereIAm < b
                    if (segment.second > BestCase.second)           //If is better
                        BestCase = segment;                         //Change it
        }

        if (BestCase.second == -1 or BestCase.second == WhereIAm) { //If no other option
            if (WhereIAm < EndPlace) Result.push_back({-1, -1});    //Add -1, -1 if not end
            break;                                                  //Break it
        } 

        WhereIAm = BestCase.second;                                 //New point
        Result.push_back(BestCase);                                 //Add it         
    }

    if (Result.back() == make_pair(-1, -1)) Result.clear();         //If it was not possible

    return Result;                                                  //Go!
}



int main() {
    int NumberOfTestCases;
    cin >> NumberOfTestCases;

    vector<VectorPair> Data;
    for (int i = 0, a, b; i < NumberOfTestCases; ++i) {
        
        VectorPair MiniData;

        int EndPlace;
        cin >> EndPlace;

        while (true) {
            cin >> a >> b;
            if (a == 0 and b == 0) break;
            MiniData.push_back({a, b});
        }

        Data.push_back(MinimalCoverage(MiniData, EndPlace));
    }

    for (int i = 0; i < Data.size(); ++i) {

        auto& Result = Data[i];
        
        if (Result.size() == 0) {
            cout << "0\n\n";
            continue;
        }

        cout << Result.size() << "\n";

        for (auto segment : Result) {
            cout << segment.first << " " << segment.second << "\n";
        }

        if (i < (Data.size() - 1)) cout << "\n";
    }

    return 0;
}