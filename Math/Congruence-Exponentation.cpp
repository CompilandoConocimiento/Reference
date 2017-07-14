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
PairOflli DivisionAlgorithm(lli a, lli b) {                                 //FN: Return the only q and r so a=bq+r
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




/*
// *******************  BINARY EXPONENTATION ************************
    Info:
        This function will POW(a,b) but a little bit more fast using
        Exponentation by Squaring 

    Math Observation:
            x (x^2)^((n-1)/2)   if n is odd
    x^n =
            (x^2)^(n/2)         if n is even

    How it does:
        In simple form we have to optimize this code:

            ·········  CODE V1 ·········
            lli BinaryExponentation(lli x, lli n) {
                if (n == 0) return 1;
                if (n == 1) return x;

                if (n%2 == 0) return BinaryExponentation(x*x,  n/2);
                else return (x * BinaryExponentation(x*x, (n-1)/2));
            }


        We dont like recursion, so we will do this:
            
            ········  CODE V2 ·········
            lli BinaryExponentation(lli Base, ull Exponent) {                         
                lli Solution = 1;                

                while (Exponent != 0) {                       
                    if (Exponent % 2 == 1) {                                           
                        Solution = Base * Solution;                                   
                        Exponent = (Exponent - 1 ) / 2;                              
                        Base = Base * Base;  
                    }
                    else {                                           
                        Base = Base * Base;                                  
                        Exponent = Exponent / 2;           
                    }
                }
                return Solution;
            }



        We now look at the last optimizations:

            - Bitwise Operations:
                Remember:
                    -   x << y == x * 2^y
                    -   x >> y == x / 2^y (integer division or floor division)

                    So x >> 1 is x / 2^1 = x/2

            -   (Exponent & 1):
                Check for binary (example:000101101010) if Exponent 
                was odd then their last digit will be 1, so Exponent & 1
                give true only if their last digit was 1.

            - Why "e = (e-1)/2" is equal to "e = e >> 1":
                Remember that if you got to this line e is odd, so their
                last binary digit is 1.

                Remember 1001 >> 1 = 0100 = 100
                So if I remove one we have 1000 >> 1 = 0100 = 100

                So you find that we end at the same number
*/
lli BinaryExponentation(lli Base, ull Exponent) {                           //FN: Modular Exponentation: a^b MOD n
    lli Solution = 1;                                                       //Solution is our aux variable (If exp=0 then s=1)

    while (Exponent != 0) {                                                 //End were exponent is zero

        if (Exponent & 1) {                                                 //If Exponent last digit = 1 therefore is odd:
            Solution = Base * Solution;                                     //s = (x * BinaryExponentation(new base, new exp)
            Base = Base * Base;                                             //new base = b^2 
            Exponent = Exponent >> 1;                                       //new exp = (e-1)/2 with is e = e >> 1 
        } 
        else {                                                              //If Exponent is even:
            Base = Base * Base;                                             //new base = b^2
            Exponent = Exponent >> 1;                                       //new exp = e/2
        }
    }

    return Solution;                                                        //Return solution
}


/*
// *******************  MODULAR EXPONENTATION  *********************
    Info:
        This function will base^exponent MOD n but a little bit more fast using
        Exponentation by Squaring, it is base in the above function.
*/
lli ModularExponentation(lli Base, ull Exponent, ull n) {                   //FN: Modular Exponentation: a^b MOD n
    lli Solution = 1;                                                       //Solution is our aux variable (If exp=0 then s=1)

    while (Exponent != 0) {                                                 //End were exponent is zero
        
        if (Exponent & 1) {                                                 //If Exponent last digit = 1 therefore is odd:
            Solution = (Base * Solution) % n;                               //s = (x * BinaryExponentation(new base, new exp)
            Base = (Base * Base) % n;                                       //new base = b^2 
            Exponent = Exponent >> 1;                                       //new exp = (e-1)/2 with is e = e >> 1 
        } 
        else {                                                              //If Exponent is even:
            Base = (Base * Base) % n ;                                      //new base = b^2
            Exponent = Exponent >> 1;                                       //new exp = e/2
        }
    }

    return Solution;                                                        //Return solution
}







// ######################################################################
// ##################          MAIN         #############################
// ######################################################################
int main(){
    cout << ModularExponentation(17, 341, 5) << "\n";

    return 0;
}



