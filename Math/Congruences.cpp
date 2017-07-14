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



/*=================================================================
========  BEST OPTIMIZATIONS OF THIS FOR REAL LIFE      ===========
=================================================================*/





/*=================================================================
========          APLICATIONS OF CONGRUENCE             ===========
=================================================================*/
lli FindReminderOfAToBDividedByN(lli a, lli b, ull n, bool ShowIt){
    auto Initial = DivisionAlgorithm(a,n);
    lli k = 1, q = Initial.first, r = Initial.second;

    if (ShowIt) cout << "\n" << a << " ≡ " << r << "  mod " << n << "\n";

    while ((pow(r,k)) % n == 1) k++;

    if (ShowIt) 
        cout << a << "^" << k << " ≡ 1" << "  mod " << n << "\n";  
    


    return ( pow(r,k) % n );
}



















// ######################################################################
// ##################          MAIN         #############################
// ######################################################################
int main(){

    FindReminderOfAToBDividedByN(17, 341, 5, true);
    


    return 0;
}



