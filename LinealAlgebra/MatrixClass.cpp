/*=============================================================================================================
====================================   GRAPHS REPRESENTATIONS        ==========================================
=============================================================================================================*/
#include <math.h>                                                                       //Include Libraries
#include <iostream>                                                                     //Include Libraries
#include <vector>                                                                       //Include Libraries
#include <set>                                                                          //Include Libraries
#include <map>                                                                          //Include Libraries
#include <list>                                                                         //Include Libraries
using namespace std;                                                                    //Bad practice, dont do

typedef unsigned long long ull;                                                         //Just a long name, sorry
typedef long long lli;                                                                  //Just a long name, sorry






/*===================================================================
================      MATRIX TEMPLATE CLASS       ===================
===================================================================*/

/* ******************* INFORMATION   **********************
        Info:
        -	
        */

template <class T>
class Matrix { 

  private: 
	vector< vector<T> > Info;

  public:
  	ull Rows;
  	ull Columns;


    Matrix(ull Rows, ull Columns) {
    	this.Rows = Rows, this.Columns = Columns;
    	Info.resize(Rows, vector<T>(Columns, 0));
    }

    vector<T>& operator[] (ull Row) {return Info[Row];}
};