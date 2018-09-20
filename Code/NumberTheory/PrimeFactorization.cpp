/*====================================================================================================
============================                 PRIME FACTORS               =============================
====================================================================================================*/
#include <vector>                                                   //Include Libraries
#include <cmath>                                                    //Include Libraries

using namespace std;                                                //to make the code more pretty

/**
* @return 
    A vector, each element is a pair {p_n, x_n} so you 
    could read the return vector as: 
    
    n = (p_1^x_1) (p_2^x_2) (p_3^x_3) ...
*/

// ***********     PRIMES FACTORIZATION     *************
template<typename T>
std::vector< std::pair<T, T> > PrimeFactorization(T n) {            //Return the prime factorization of n
    std::vector< std::pair<T, T> > Factors;                         //This is where we save the factors
    T exponent;                                                     //This is exponent of a given prime
    
    for (exponent = 0; (n & 1) == 0 ; ++exponent)                   //Is last digit a '0' in binary?
        n = n >> 1;                                                 //Remove last digit in bin, and save
    if (exponent) Factors.emplace_back(2, exponent);                //Add the # of times that 2 divides n

    for (T i = 3; i * i <= n; i += 2) {                             //For each possible divisor
        for (exponent = 0; (n % i) == 0; ++exponent) n /= i;        //Find the times that it divided it!
        if (exponent) Factors.emplace_back(i, exponent);            //Not 0?, the add to the vector
    }
    
    if (n > 1) Factors.emplace_back(n, 1);                          //If n were a prime
    
    return Factors;                                                 //Return the info               
}


// ***********     PRIMES FACTORIZATION     *************
template<typename T>
vector< pair<T, T> > Factorize(T n, const vector<T> &Primes) {      //Get the prime factors with primes
    std::vector< std::pair<T, T> > Factors;                         //This is where we save the factors

    size_t limit = std::sqrt(n);                                    //Add a limit to factors
    for (size_t i = 0; i < limit; i++) {                            //Until that limit
        T prime = Primes[i], exponent;                              //exponent
        for (exponent = 0; n % prime == 0; ++exponent) n /= prime;  //Find the times that it divided it!
        if (exponent != 0) Factors.emplace_back(prime, exponent);   //Add to the exponent
    }

    if (n > 1) Factors.emplace_back(n, 1);                          //If n were a prime
    
    return Factors;                                                 //Return the info               
}

// ***********     GER SMALLEST PRIME FACTOR     *************
template <typename T>
T getSmallestPrimeFactor(T number) {                                //Get the smallest prime factor
    if (number == 1) return 1;                                      //Stupid
    if (number % 2 == 0) return 2;                                  //Stupid
    
    T limit = sqrt(number) + 1;                                     //Get the correct limit
    for (T i = 3; i < limit; i += 2)                                //Foreach odd number until √n
        if (number % i == 0) return i;                              //If divisible, this is the first
    
    return number;                                                  //number is prime - . -
}