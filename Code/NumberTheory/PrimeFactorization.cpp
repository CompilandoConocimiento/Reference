/*====================================================================================================
============================                 PRIME FACTORS               =============================
====================================================================================================*/
#include <vector>                                                       //Include Libraries
#include <cmath>                                                        //Include Libraries

using ull = unsigned long long;                                         //Just a so long name, sorry
using namespace std;                                                    //to make the code more pretty

/**
* @return 
    A vector, each element is a pair {p_n, x_n} so you could read the return vector as: 
    n = (p_1^x_1) (p_2^x_2) (p_3^x_3) ...
*/

// ***********     PRIMES FACTORIZATION     *************
std::vector< std::pair<ull, ull> > PrimeFactorization(ull n) {          //Return the prime factorization of n
    std::vector< std::pair<ull, ull> > Factors;                         //This is where we save the factors
    ull exponent;                                                       //This is exponent of a given prime
    
    for (exponent = 0; (n & 1) == 0 ; ++exponent)                       //Is their last digit a '0' in binary?
        n = n >> 1;                                                     //Remove last digit in bin, and save
    if (exponent) Factors.emplace_back(2, exponent);                    //Add the # of times that 2 divides n

    for (ull i = 3; i * i <= n; i += 2) {                               //For each possible divisor
        for (exponent = 0; (n % i) == 0; ++exponent) n /= i;            //Find the times that it divided it!
        if (exponent) Factors.emplace_back(i, exponent);                //If it's not 0, the add to the vector
    }

    if (n > 1) Factors.emplace_back(n, 1);                              //If n were a prime
    return Factors;                                                     //Return the info               
}


// ***********     PRIMES FACTORIZATION     *************
vector< pair<ull, ull> > Factorize(ull n, const vector<ull> &Primes) {  //Return the prime factorization of n
    std::vector< std::pair<ull, ull> > Factors;                         //This is where we save the factors

    for (ull prime : Primes) {                                          //For each prime
        if (prime * prime > n) break;                                   //If is not possible to divide, go!

        ull exponent;                                                   //exponent
        for (exponent = 0; n % prime == 0; ++exponent) n /= prime;      //Find the times that it divided it!
        if (exponent != 0) Factors.emplace_back(prime, exponent);       //Add to the exponent
    }

    if (n > 1) Factors.emplace_back(n, 1);                              //If n were a prime
    return Factors;                                                     //Return the info               
}

// *******   ERATOSTHENES SIEVE / VECTOR OF PRIMES   *******
std::vector<ull> EratosthenesSievePrimes(ull n) {               //Return a vector of only primes
    std::vector<bool> isPrime(n + 1, true);                     //Create the origianl Sieve
    std::vector<ull> Primes(1, 2);                              //2 is a prime, dahhhhh!
    
    isPrime[0] = isPrime[1] = false;                            //Now, 0 & 1(maybe) are not prime

    for (ull i = 4; i <= n; i += 2) isPrime[i] = false;         //Eliminate all the evens numbers

    for (ull i = 3, limit = std::sqrt(n); i <= n; i += 2) {     //Check for every odd number
        if (isPrime[i]) {                                       //If we still believe it's a prime
            Primes.push_back(i);                                //Add it to the vector, it's a prime
            
            if (i <= limit)                                     //It make sense to delete multiples?
                for (ull j = i * i; j <= n; j += 2 * i)         //ForEach multiple we have'nt check
                    isPrime[j] = false;                         //Each multiple is not prime
        }
    }

    return Primes;                                              //Return the vector of only primes
}
