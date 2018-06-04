/*================================================================
================  KNAPSACK: STEAL A BANK    ======================
==================================================================

https://www.geeksforgeeks.org/knapsack-problem/                 */

#include <iostream>                                                                         //Include library
#include <vector>                                                                           //Include library
using namespace std;                                                                        //Bad habit

int Knapsack (vector<int>& Values, vector<int>& Costs, int CapacityInCost) {                //Parameters to fn

    int NumberOfItems = Values.size();                                                      //Number of items
    int DataStore[NumberOfItems + 1][CapacityInCost + 1];                                   //DP Table

    for (int item = 0; item <= NumberOfItems; ++item) {                                     //Foreach item number
        for (int actualCost = 0; actualCost <= CapacityInCost; ++actualCost) {              //For each possible cap
            
            int CostOfPreviousItem = Costs[item - 1];                                       //Temporal vars
            int ValueOfPreviousItem = Values[item - 1];                                     //Temporal vars
            int CostUntilPrevItem = DataStore[item - 1][actualCost];                        //Temporal vars

            if (item == 0 or actualCost == 0) {                                             //If at the start
                DataStore[item][actualCost] = 0;                                            //Put zero
            }
            else if (CostOfPreviousItem > actualCost) {                                     //If is better
               DataStore[item][actualCost] = CostUntilPrevItem;                             //take it
            }
            else {                                                                          //If is worst
                int RemoveLastItem = DataStore[item - 1][actualCost - CostOfPreviousItem];  //Remove the last item
                int NewOption = max(CostUntilPrevItem, RemoveLastItem+ValueOfPreviousItem); //Get the better deal
                DataStore[item][actualCost] = NewOption;                                    //New options
            }
        }
    }

    return DataStore[NumberOfItems][CapacityInCost];                                        //Return the result
}


int main() {

    int NumberOfItems, CapacityInCost;
    cin >> CapacityInCost >> NumberOfItems;

    vector<int> Values(NumberOfItems), Costs(NumberOfItems);
    for (int i = 0; i < NumberOfItems; ++i) cin >> Costs[i] >> Values[i];
    
    cout << Knapsack(Values, Costs, CapacityInCost) << "\n";

    return 0;
}