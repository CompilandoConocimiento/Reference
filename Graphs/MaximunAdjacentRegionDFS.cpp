/*=============================================================================================================
==========================        DFS: DEEP FIRST SEARCH   APPLICATION         ================================
=============================================================================================================*/

#include <math.h>                                                               //Include Libraries
#include <iostream>                                                             //Include Libraries
#include <vector>                                                               //Include Libraries
#include <set>                                                                  //Include Libraries
#include <map>                                                                  //Include Libraries
#include <list>                                                                 //Include Libraries
using namespace std;                                                            //Bad practice, dont do it kids!

typedef unsigned long long ull;                                                 //Just a so long name, sorry
typedef long long lli;                                                          //Just a so long name, sorry
typedef vector< pair<int, int> > VectorOfPair;
typedef vector< vector<bool> > MatrixOfBool;                                	//Just a so long name, sorry
typedef MatrixOfBool MB;                                						//Just a so long name, sorry



/*===============================================================================
======================              MAXIMUN REGION            ===================
===============================================================================*/


/* ******************* MAP DFS: MAXIMUN REGION   ********************* */
void MapDFS
	(MB& Map, MB& Visited, lli Row, lli Column, ull& Count, VectorOfPair& Moves) {	//FN: Find all adjacent to you
	ull Rows = Map.size(), Columns = Map[0].size();									//Lets get the dimensions to work

	if (Row >= Rows || Row < 0 || Column >= Columns || Column < 0) return;			//We are outside the dimensions
	if (Visited[Row][Column] == true) return;										//If we have been here
	if (Map[Row][Column] == 0) return;												//If there is nothing here

	Visited[Row][Column] = true;													//Now we have visited
	++Count;																		//Lets count this point too

	for (auto& Move : Moves)														//For each pair of PossibleMoves
		MapDFS(Map, Visited, Row + Move.first, Column + Move.second, Count, Moves); //Call to all possible moves
}



/* ******************* GET MAXIMUN REGION   ********************** */
ull GetMaximunConexRegion(MatrixOfBool& Map, VectorOfPair Moves) {					//FN: Get the max adjacent region

	ull Rows = Map.size(), Columns = Map[0].size();									//Get me size dimensions
	MatrixOfBool Visited(Rows, vector<bool>(Columns,0));							//Create the Visited Matrix

	ull SizeMaxRegion = 0;															//Suppose the worst case scenario

    for (lli i = 0; i < Rows; ++i)													//Classical for loops
        for (lli j = 0; j < Columns; ++j)											//Classical for loops
            if (Map[i][j] && Visited[i][j] == false)	{  							//If there is something to search
            	ull MaybeNewMax = 0;												//Get me this region size
                MapDFS(Map, Visited, i, j, MaybeNewMax, Moves);    					//Visit all cells in this island
                if (MaybeNewMax > SizeMaxRegion) SizeMaxRegion = MaybeNewMax;		//If we have found new biggest
            }
 
    return SizeMaxRegion;															//Return this data


}

// ######################################################################
// ##################          MAIN         #############################
// ######################################################################
int main() {


	// ==== VECTOR OF MOVES ==========
	vector< pair<int, int> > ValidMovements;										//Valid Moves: 100% True & Proof

	ValidMovements.push_back({0,1});												//Move Right  	->
	ValidMovements.push_back({-1,0});												//Move Down 	^
	ValidMovements.push_back({1,0});												//Move Up       v
	ValidMovements.push_back({0,-1});												//Move Left 	<-

	ValidMovements.push_back({1,1});												//Move 270 +45 Degrees
	ValidMovements.push_back({1,-1});												//Move 180 +45 Degrees
	ValidMovements.push_back({-1,1});												//Move 0   +45 Degrees
	ValidMovements.push_back({-1,-1});												//Move 90  +45 Degrees


	// ==== GET AND SHOW INPUT ==========
	ull Row, Column;																//Create variables
	cin >> Row >> Column;															//Get them

	vector< vector<bool> > Map;														//Create the Map

	for (ull i = 0; i < Row; i++) {													//For each Row
		vector<bool> AuxVector(Column);												//Create an Aux Vector
		for (ull j = 0, Temporal; j < Column; j++)									//For each Column
			cin >> Temporal, AuxVector[j] = Temporal;								//Get it!
		Map.push_back(AuxVector);													//Add the Row to the Matrix
	}

	for (auto RowInfo : Map) {														//For each Row
		for (auto Element: RowInfo) cout << Element << " "; cout << endl;			//Show the Row
	}

	// ==== GET MAXIMUN REGION ==========
	auto i = GetMaximunConexRegion(Map, ValidMovements);							//Get the info
	cout << "\n\nThe Maximun Region is of " << i << " elements"<< endl;				//Show the info

	return 0;																		//Bye main :D
}
