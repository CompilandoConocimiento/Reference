/*====================================================================================================
============================            SIEVE OF ERATOSTHENES            =============================
====================================================================================================*/
#include <vector>                                               //Include Libraries
#include <cmath>                                                //Include Libraries

typedef unsigned long long ull;                                 //Just a so long name, sorry
typedef long long int lli;                                      //Just a so long name, sorry


// *******   ERATOSTHENES SIEVE / IS PRIME IN O(1)   *******
std::vector<bool> EratosthenesSieveIsPrime(ull n) {             //To check if i is prime: Vector[i]
    std::vector<bool> isPrime(n + 1, true);                     //Ok, first, allocate space
    isPrime[0] = isPrime[1] = false;                            //Now, 0 & 1(maybe) is not prime

    for (ull i = 4; i <= n; i += 2) isPrime[i] = false;         //Eliminate all the evens

    for (ull i = 3, limit = std::sqrt(n); i <= limit; i += 2)   //Check for every # < √i (Math) 
        if (isPrime[i])                                         //If we still believe it's a prime
            for (ull j = i * i; j <= n; j += 2 * i)             //Remove all his multiples- limit
                isPrime[j] = false;                             //For each multiple just remove it

    return isPrime;                                             //Return the info to know if n is prime
}

// *******   ERATOSTHENES SIEVE / VECTOR OF PRIMES   *******
std::vector<ull> EratosthenesSievePrimes(ull n) {               //Vector of primes
    std::vector<bool> isPrime(n + 1, true);                     //Ok, first, allocate space
    std::vector<ull> Primes(1, 2);                              //2 is a prime, dahhhhh!
    
    isPrime[0] = isPrime[1] = false;                            //Now, 0 & 1(maybe) is not prime

    for (ull i = 4; i <= n; i += 2) isPrime[i] = false;         //Eliminate all the evens

    for (ull i = 3, limit = std::sqrt(n); i <= n; i += 2) {     //Check for every # < √i (Math) 
        if (isPrime[i]) {                                       //If we still believe it's a prime
            Primes.push_back(i);                                //Add it!
            
            if (i <= limit)                                     //It make sense to delete multiples?
                for (ull j = i * i; j <= n; j += 2 * i)         //Remove all his multiples- limit
                    isPrime[j] = false;                         //For each multiple just remove it
        }
    }

    return Primes;                                              //Return the info to know if n is prime
}
