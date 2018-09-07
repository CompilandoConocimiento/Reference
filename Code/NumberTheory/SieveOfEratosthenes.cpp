/*====================================================================================================
============================            SIEVE OF ERATOSTHENES            =============================
====================================================================================================*/
#include <vector>                                               //Include Libraries
#include <cmath>                                                //Include Libraries

// *******   ERATOSTHENES SIEVE / IS PRIME IN O(1)   *******
template<typename T>
std::vector<bool> EratosthenesSieveIsPrime(T n) {               //To check if i is prime: Vector[i]
    std::vector<bool> isPrime(n + 1, true);                     //Ok, first, allocate space 
    isPrime[0] = isPrime[1] = false;                            //Now, 0 & 1(maybe) are not prime

    for (T i = 4; i <= n; i += 2) isPrime[i] = false;           //Eliminate all the evens numbers

    T limit = std::sqrt(n) + 1;                                 //Delete multiple until
    for (T i = 3; i <= limit; i += 2)                           //For every odd number < √n  
        if (isPrime[i])                                         //If we found a prime :0
            for (T j = i * i; j <= n; j += 2 * i)               //ForEach multiple we have'nt check
                isPrime[j] = false;                             //Each multiple is not prime

    return isPrime;                                             //Return the complete sieve
}

// *******   ERATOSTHENES SIEVE / VECTOR OF PRIMES   *******
template<typename T>
std::vector<T> EratosthenesSievePrimes(T n) {                   //Return a vector of only primes
    std::vector<bool> isPrime(n + 1, true);                     //Create the origianl Sieve
    std::vector<T> Primes(1, 2);                                //2 is a prime, dahhhhh!

    T limit = std::sqrt(n) + 1;                                 //Delete multiple until
    for (T i = 3; i <= n; i += 2) {                             //For every odd number < √n
        if (isPrime[i]) {                                       //If we still believe it's a prime
            Primes.push_back(i);                                //Add it to the vector, it's a prime
            
            if (i <= limit)                                     //It make sense to delete multiples?
                for (T j = i * i; j <= n; j += 2 * i)           //ForEach multiple we have'nt check
                    isPrime[j] = false;                         //Each multiple is not prime
        }
    }

    return Primes;                                              //Return the vector of only primes
}
