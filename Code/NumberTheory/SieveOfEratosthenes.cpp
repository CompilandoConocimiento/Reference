#include <vector> 

// *******   ERATOSTHENES SIEVE / IS PRIME IN O(1)   *******
template<typename T>
auto getIsPrime(T maxValue) -> std::vector<bool> {       
    std::vector<bool> isPrime (maxValue + 1, true);         
    isPrime[0] = isPrime[1] = false; 

    for (T i {4}; i <= maxValue; i += 2) isPrime[i] = false;

    for (T i {3}; i * i <= maxValue; i += 2) {
        if (not isPrime[i]) continue;    

        T multiple {i * i}, step {2 * i};
        while (multiple <= maxValue) {
            isPrime[multiple] = false; 
            multiple += step;
        }
    }

    return isPrime;                                
}

// *******   ERATOSTHENES SIEVE / VECTOR OF PRIMES   *******
template<typename T>
auto getPrimes(T maxValue) -> std::vector<T> {          
    std::vector<bool> isPrime (maxValue + 1, true);                     
    std::vector<T> primes {2};                                  

    // Just to do it if you need the bools too.                       
    // isPrime[0] = isPrime[1] = false;                          
    // for (T i = 4; i <= n; i += 2) isPrime[i] = false;         

    for (T i {3}; i <= maxValue; i += 2) {   
        if (not isPrime[i]) continue;    
        primes.push_back(i);     

        T multiple {i * i}, step {2 * i};
        while (multiple <= maxValue) {
            isPrime[multiple] = false; 
            multiple += step;
        }    
    }

    return primes;               
}
