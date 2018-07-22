/*====================================================================================================
=====================             FACTORIZATION OF A FACTORIAL           =============================
====================================================================================================*/
#include <vector>                                                   //Include library

typedef unsigned long long ull;                                     //Just a so long name, sorry
typedef std::pair<ull, ull> pairOfUll;                              //Just a so long name, sorry
using namespace std;                                                //Just for names

ull NumberOfTimesPDivideN(ull n, ull prime) {                       //Rememember prime should be prime
    ull exponent = 0, divisor = prime;                              //Add exponent var and new name 

    while (divisor <= n) {                                          //Find the highest power (exponent) ..
        exponent += (n / divisor);                                  //of prime that divide n using the ..
        divisor *= prime;                                           //Legendre formula
    }

    return exponent;                                                //Return the highest power
}

vector<pairOfUll> FactorizeAFactorial(ull n, vector<ull> Primes) {      //Factorize n!
    std::vector< std::pair<ull, ull> > Factors;                         //This is where we save factors

    for (ull prime : Primes) {                                          //For each prime in the Sieve
        if (prime > n) break;                                           //If we came to the need, go!
        Factors.emplace_back(prime, NumberOfTimesPDivideN(n, prime));   //Now add to the vector
    }

    return Factors;                                                     //Return the factors
}