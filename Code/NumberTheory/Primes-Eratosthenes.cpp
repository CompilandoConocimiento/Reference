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



/* ******************* PRIME FACTORIZATION OF N    **********************
    Info:
        This function will return a n pair so:
        -   The first of the pair is p_i where p_i is prime
        -   The seconf of the pair is p_i exponent
        
        So n = p_1^x_1 p_2^x_2 p_3^x_3 ...

    How it does:

        -   First it transform n into binary and check the number of 0's
            that are at end of n and eliminate from the number
            Remember that n = 2^(#of 0's at end)...
            Example (10100 -> 101)

        -   After that n must be odd
        
        -   Just use a kind of sieve to find how many time does it divided
            and i

*/

vector<PairOflli> PrimeFactorization(lli Number) {                          //FN: Return the prime factorization of n
    vector<PairOflli> Factors;                                              //This is where the info goes
    lli Exponent = 0;                                                       //This is Exponent of a given prime
    
    for (; (Number & 1) == 0 ; ++Exponent)                                  //Is their last digit a '0' in binary?
        Number >>= 1;                                                       //Remove last digit in bin an keep count

    if (Exponent) Factors.emplace_back(2, Exponent);                        //Add the # of times that 2 divides n

    for (lli i = 3; i*i <= Number; i += 2) {                                //For each possible divisor
        for (Exponent = 0; (Number % i) == 0; ++Exponent) Number /= i;      //Find the times that it divided it!
        if (Exponent) Factors.emplace_back(i, Exponent);                    //If it's not 0, the add to the vector
    }

    if (Number > 1) Factors.emplace_back(Number, 1);                        //If n were a prime
    return Factors;                                                         //Return the info               
}

vector<PairOflli> PrimeFactorization(lli Number, vector<ull> &Primes) {     //FN: Return the prime factorization of n
    vector<PairOflli> Factors;                                              //This is where the info goes

    for (lli Exponent = 0, i = 0; Number != 1; ++i, Exponent = 0){          //For each possible Prime
        for (; !(Number % Primes[i]); ++Exponent) Number /= Primes[i];      //Find the times that it divided it!
        if (Exponent) Factors.emplace_back(Primes[i], Exponent);            //If it's not 0, the add to the vector  
    }

    return Factors;                                                         //Return the info               
}











// ######################################################################
// ##################          MAIN         #############################
// ######################################################################
int main(){

    /* ====== SECTION: PRIME FACTORIZATION ================= 
    cout << "n = " << RandomNumber << "\n = ";                          //Show the Prime factorization          
    for (auto Factor : PrimeFactorization(RandomNumber, VectorPrimes))  //For each factor
        cout << Factor.first << "^" << Factor.second << " * ";          //Show it!
    cout << "\n";                                                       //And then go
    */

    return 0;
}



