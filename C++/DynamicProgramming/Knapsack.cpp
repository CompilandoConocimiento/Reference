/*================================================================
================  KNAPSACK: STEAL A BANK    ======================
==================================================================

https://www.geeksforgeeks.org/knapsack-problem/                 */

#include <iostream>                                                     
#include <vector>                                                       
using namespace std;                                                    

int Knapsack(const vector<int>& Values, const vector<int>& Costs, int CapacityInCost) { 
    
    int NumberOfItems = Values.size();
    int DataStore[NumberOfItems + 1][CapacityInCost + 1];

    for (int item = 0; item <= NumberOfItems; ++item) {
        
        for (int actualCost = 0; actualCost <= CapacityInCost; ++actualCost) {
            
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

    return DataStore[NumberOfItems][CapacityInCost];
}


int main() {

    int NumberOfItems, CapacityInCost;
    cin >> NumberOfItems >> CapacityInCost;

    vector<int> Values(NumberOfItems), Costs(NumberOfItems);

    for (int i = 0, temporal; i < NumberOfItems; ++i) {
        cin >> temporal;
        Values[i] = temporal;
    }

    for (int i = 0, temporal; i < NumberOfItems; ++i) {
        cin >> temporal;
        Costs[i] = temporal;
    }

    cout << Knapsack(Values, Costs, CapacityInCost) << "\n";

    return 0;
}