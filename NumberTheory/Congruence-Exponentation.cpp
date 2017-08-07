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
    return {q, r};                                                          //Return the info
}




/*
// *******************  BINARY EXPONENTATION ************************
    INFO:
        This function will POW(a,b) but a little bit more fast using
        Exponentation by Squaring 

        Math Observation:
                x (x^2)^((n-1)/2)   if n is odd
        x^n =
                (x^2)^(n/2)         if n is even

        HISTORY - ALTERNATIVE CODES:

            VERSION ALTERNATIVE:
                Using the Method 1 from my book in Number Theory

                ·······  CODE V1·········
                lli BinaryExponentation(lli Base, ull Exponent) {       //FN: Binary Exponentation
                    lli Solution = 1;                                   //Solution is aux variable (If exp=0 then s=1)

                    for (; Exponent != 0; Exponent = Exponent >> 1) {   //Cool way of: For each bit in Exponent                   
                        if (Exponent & 1)                               //If last digit = 1
                            Solution = (Solution * Solution) * Base;    //Then new solution = solution^2 * base
                        else Solution = Solution * Solution;            //If last digit = 0 then new sol = sol^2
                    }

                    return Solution;                                    //Return solution
                }


            VERSION 2:
                WE HAVE TO OPTIMIZE THIS:
                    This is an obvious code if you look from the identities

                ·········  CODE V2 ·········
                lli BinaryExponentation(lli x, lli n) {
                    if (n == 0) return 1;
                    if (n == 1) return x;

                    if (n%2 == 0) return BinaryExponentation(x*x,  n/2);
                    else return (x * BinaryExponentation(x*x, (n-1)/2));
                }


                ·········  CODE V3: ITERATIVE ·········
                This code uses a "new" algorithm, with is based from my book
                Number Theory, this algorithm is deduced from the Above code
                by creating equivalents instruccions to the machine but a new layer
                that make it more easy to understand.


                HOW WE TRANSFORM THAT:
                    -   Bitwise Operations:
                        Remember:
                            -   x << y == x * 2^y
                            -   x >> y == x / 2^y (integer division or floor division)


                    -   TRANSFORM THE  "E = (E-1)/2" AND "E = E/2" USING THE BINARY NOTATION:
                            Why "e = (e-1)/2" is equal to "e = e >> 1" and "e = e/2" is also "e = e >> 1":

                            Remember "E >> 1" delete the least significant bit, so is the same of "E / 2"

                            But why it works when we need to do "(E-1)/2":
                                Remember that if  e is odd their last binary digit is 1. 
                                
                                Remember 1001 >> 1 = 0100 = 100 (Add a 0 at the start and remove last digit)
                                So if I remove one, we have 1000 >> 1 = 0100 = 100

                                So you find that we end at the same number it doesnt matter if is odd or even
                                this will always give you the correct answer

                    -   TRANSFORM THE ODD / EVEN TEST BY CHECKING EACH DIGIT, IS THE SAME:
                        (Exponent & 1):
                            Check for binary (example:000101101010) if Exponent 
                            was odd then their last digit will be 1, so Exponent & 1
                            give true only if their last digit was 1.


                    -   ADD AN AUX VARIABLE TO DELETE RECURSION  
        

        HOW IT WORK:
            Thanks to the math identity we create an algoritm that always works:

            ALGORITM: This deduced from the V1:
                Start solution to 0
                Start auxiliar to base
                For each bit in exponent (Starting at the least important one):
                    If is 1:
                        Update solution = auxiliar * solution
                        Update auxiliar = auxiliar^2
                    If is 0:
                        Update auxiliar = auxiliar^2
*/
lli BinaryExponentation(lli Base, ull Exponent) {                           //FN: Modular Exponentation: a^b MOD n
    lli Solution = 1, Auxiliar = Base;                                      //Auxiliar variables for code clarity                

    while (Exponent != 0) {                                                 //End were exponent is zero

        if (Exponent & 1) {                                                 //If Exponent last digit = 1 (Exp is odd):
            Solution = Auxiliar * Solution;                                 //Update Solution
            Auxiliar = Auxiliar * Auxiliar;                                 //Always update by squaring the aux variable
            Exponent = Exponent >> 1;                                       //Remove 1 digit from e to read the next one
        } 
        else {                                                              //If Exponent is even:
            Auxiliar = Auxiliar * Auxiliar;                                 //Always update by squaring the aux variable
            Exponent = Exponent >> 1;                                       //Remove 1 digit from e to read the next one
        }
    }

    return Solution;                                                        //Return solution
}


/*
// *******************  MODULAR EXPONENTATION  *********************
    INFO:
        This function will base^exponent MOD n but a little bit more
        fast using exponentation by Squaring, it is base in the above
        function.

        
        ALTERNATIVE CODE:
            This also works and rely on my own algorithm from my book
            in number theory, but, it's not so fast (5% more time)

            ·······  CODE V1·········
            lli ModularExponentation(lli Base, ull Exponent, ull n) {       //FN: Modular Exponentation: a^b MOD n
                ull K = 1, R = DivisionAlgorithm(Base, (lli) n).second;     //Get k, a constant and the first step

                while (BinaryExponentation(R, K) % n != 1) K++;             //Find the special k

                lli OtherR = DivisionAlgorithm(Exponent, K).second;         //Get the other r

                return (BinaryExponentation(r, r2) % n);                    //Answer is r^new r (mod n)
            }

*/
lli ModularExponentation(lli Base, ull Exponent, ull n) {                   //FN: Modular Exponentation: a^b MOD n
    lli Solution = 1, Auxiliar = Base;                                      //Auxiliar variables for code clarity                

    while (Exponent != 0) {                                                 //End were exponent is zero

        if (Exponent & 1) {                                                 //If Exponent last digit = 1 (Exp is odd):
            Solution = (Auxiliar * Solution) % n;                           //Update Solution
            Auxiliar = (Auxiliar * Auxiliar) % n;                           //Always update by squaring the aux variable
            Exponent = Exponent >> 1;                                       //Remove 1 digit from e to read the next one
        } 
        else {                                                              //If Exponent is even:
            Auxiliar = (Auxiliar * Auxiliar) % n;                           //Always update by squaring the aux variable
            Exponent = Exponent >> 1;                                       //Remove 1 digit from e to read the next one
        }
    }

    return Solution;                                                        //Return solution
}




// ######################################################################
// ##################          MAIN         #############################
// ######################################################################
int main(){

    /* ====== SECTION: BINARY EXPONENTATION  =================                                                 
        cout << BinaryExponentation(17, 34) << "\n";
    */

    /* ====== SECTION: MODULAR EXPONENTATION  ============  
        cout << ModularExponentation(17, 34, 5) << "\n";     
    */ 
        
    


    return 0;
}



