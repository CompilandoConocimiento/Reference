/*====================================================================================================
============================                 PRIME FACTORS               =============================
====================================================================================================*/
#include <vector>                                                   //Include Libraries
#include <cmath>                                                    //Include Libraries

typedef unsigned long long ull;                                     //Just a so long name, sorry
using namespace std;                                                //to make the code more pretty

/**
* @return 
    A vector, each element is a pair {p_n, x_n} so you could read the return vector as: 
    n = (p_1^x_1) (p_2^x_2) (p_3^x_3) ...
*/

// ***********     PRIMES FACTORIZATION     *************
std::vector< std::pair<ull, ull> > PrimeFactorization(ull n) {      //Return the prime factorization of n
    std::vector< std::pair<ull, ull> > Factors;                     //This is where we save the factors
    ull Exponent;                                                   //This is Exponent of a given prime
    
    for (Exponent = 0; (n & 1) == 0 ; ++Exponent)                   //Is their last digit a '0' in binary?
        n >>= 1;                                                    //Remove last digit in bin, and save
    if (Exponent) Factors.emplace_back(2, Exponent);                //Add the # of times that 2 divides n

    for (ull i = 3; i * i <= n; i += 2) {                           //For each possible divisor
        for (Exponent = 0; (n % i) == 0; ++Exponent) n /= i;        //Find the times that it divided it!
        if (Exponent) Factors.emplace_back(i, Exponent);            //If it's not 0, the add to the vector
    }

    if (n > 1) Factors.emplace_back(n, 1);                          //If n were a prime
    return Factors;                                                 //Return the info               
}


// ***********     PRIMES FACTORIZATION     *************
vector< pair<ull, ull> > Factorize(ull n, vector<ull> Primes) {     //Return the prime factorization of n
    std::vector< std::pair<ull, ull> > Factors;                     //This is where we save the factors

    for (ull prime : Primes) {                                      //For each prime
        if (prime * prime > n) break;                               //If is not possible to divide, go!

        ull Exponent;                                               //Exponent
        for (Exponent = 0; n % prime == 0; ++Exponent) n /= prime;  //Find the times that it divided it!
        if (Exponent != 0) Factors.emplace_back(prime, Exponent);   //Add to the exponent
    }

    if (n > 1) Factors.emplace_back(n, 1);                          //If n were a prime
    return Factors;                                                 //Return the info               
}
