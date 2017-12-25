/*=============================================================================================================
====================================   GRAPHS REPRESENTATIONS        ==========================================
=============================================================================================================*/
#include <iostream>                                                                     //Include Libraries
#include <vector>                                                                       //Include Libraries
#include <set>                                                                          //Include Libraries
#include <map>                                                                          //Include Libraries
#include <list>                                                                         //Include Libraries

typedef unsigned long long ull;                                                         //Just a long name, sorry
typedef long long lli;                                                                  //Just a long name, sorry

using namespace std;                                                                    //Bad practice, dont do


/*===================================================================
================      MATRIX TEMPLATE CLASS       ===================
===================================================================*/

template <class T>
class Matrix { 

    private: 
        ull Rows;
        ull Columns;

        vector< vector<T> > Info;

    Matrix(ull Rows, ull Columns) {
        this.Rows = Rows, this.Columns = Columns;
        Info.resize(Rows, vector<T>(Columns, 0));
    }

    vector<T>& operator[] (ull Row) {return Info[Row];}
};