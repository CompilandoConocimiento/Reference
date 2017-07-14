/*=============================================================================================================
==============================     NUMBER THEORY FUNCTION FOR HUMANITY       ==================================
=============================================================================================================*/

#include <math.h>                                                           //Include Libraries
#include <stdlib.h>                                                         //Include Libraries
#include <iostream>                                                         //Include Libraries
#include <vector>                                                           //Include Libraries
using namespace std;                                                        //Bad practice, dont do it kids!

typedef unsigned long long ull;                                             //Just a so long name, sorry
typedef long long lli;                                                      //Just a so long name, sorry
typedef pair<lli,lli> PairOflli;                                            //Just a so long name, sorry
typedef vector< vector<lli> > MatrixOflli;                                  //Just a so long name, sorry





/*=================================================================
=============   JUST TO LEARN AND SEE STEP BY STEP   ==============
=================================================================*/



/*=================================================================
========  BEST OPTIMIZATIONS OF THIS FOR REAL LIFE      ===========
=================================================================*/

// ******************* LONG DIVISION ALGORITHM ************************
PairOflli DivisionAlgorithm(lli a, lli b){                                  //FN: Return the only q and r so a=bq+r
    lli q, r;                                                               //Variables, remember [0,|b|) in r

    if (b != 0) {                                                           //If we have work to do
        q = a/b;                                                            //Get me the floor of this
        r = a%b;                                                            //Get me the reminder

        if (r < 0){                                                         //If we have a problem
            (q >= 0)? q++: q--;                                             //If q>0 add 1, else sub 1
            r = a - (b*q);                                                  //Recalculate reminder
        }
    }
    else {q = 0; r = a;}                                                    //b=0, this is always the result
    return {q,r};                                                           //Return the info
}


// *******************  BINARY EXPONENTATION ************************
lli BinaryExponentation(lli Base, lli Exponentation){                       //FN: Just like POW but using Binary Exponentation
    lli Solution = 1;                                                       //Maybe e=0, so b^0=1

    while (Exponentation != 0) {                                            //If b^0 then s = 1
        if (Exponentation % 2 == 1) {                                       //If e odd then s = b(b^2)^{(e-1)/2} = b(new b)^new e
            Solution = Base * Solution;                                     //If e=1 then we need this
            Exponentation = (Exponentation - 1 ) / 2;                       //new e = (e-1)/2
            Base = Base * Base;                                             //new b = b^2
        }
        else {                                                              //Id e even then s = (b^2)^(n/2) = new base^new e
            Base = Base * Base;                                             //new b = b^2
            Exponentation = Exponentation / 2;                              //new e = e/2
        }
    }

    return Solution;                                                        //Go you are the answer
}






















// ######################################################################
// ##################          MAIN         #############################
// ######################################################################
int main(){

    cout << BinaryExponentation(3,7) << "\n";
    


    return 0;
}



