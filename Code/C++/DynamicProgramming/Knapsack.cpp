/*================================================================
================  KNAPSACK: STEAL A BANK    ======================
==================================================================

I would explain the problem, but come on is on Google
*/

#include <iostream>                                                     
#include <vector>                                                       
#include <cmath>                                                        
using namespace std;                                                    


int Knapsack(vector<int> Values, vector<int> Costs, int AvailableCost) { 
    
    int NumberOfItems = Values.size();
    int DataStore[NumberOfItems + 1][AvailableCost + 1];

    for (int item = 0; item <= NumberOfItems; ++item) {
        
        for (int actualCost = 0; actualCost <= AvailableCost; ++actualCost) {
            
            int CostOfPreviousItem = Costs[item - 1];
            int ValueOfPreviousItem = Values[item - 1];
            int CostUntilPreviousItem = DataStore[item - 1][actualCost];

            if (item == 0 or actualCost == 0) {
                DataStore[item][actualCost] = 0;
                continue;
            }
            else if (CostOfPreviousItem > actualCost) {
               DataStore[item][actualCost] = CostUntilPreviousItem;
               continue;
            }
            else {
                int RemoveLastItem = DataStore[item - 1][actualCost - CostOfPreviousItem];
                int NewOption = max(CostUntilPreviousItem, RemoveLastItem + ValueOfPreviousItem);
                DataStore[item][actualCost] = NewOption;
            }
        }
    }

    return DataStore[NumberOfItems][AvailableCost];
}






int main() {

    int NumberOfItems, AvailableCost;
    cin >> NumberOfItems >> AvailableCost;

    vector<int> Values(NumberOfItems), Costs(NumberOfItems);

    for (int i = 0, temporal; i < NumberOfItems; ++i) {
        cin >> temporal;
        Values[i] = temporal;
    }

    for (int i = 0, temporal; i < NumberOfItems; ++i) {
        cin >> temporal;
        Costs[i] = temporal;
    }

    cout << Knapsack(Values, Costs, AvailableCost) << "\n";

    return 0;
}