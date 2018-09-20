/*====================================================================================================
============================                 PRIME FACTORS               =============================
====================================================================================================*/
#include <vector>                               //Include Libraries
#include <cmath>                                //Include Libraries

using namespace std;                            //to make the code more pretty

template <typename T>
bool isPrime(T number) {
    if (number < 2) return false;               //0, 1 are not primes
    if (number == 2) return true;               //You are 2 :o
    if (number % 2 == 0) return false;          //Remove half of integers

    for (T i = 3; i * i <= number; i += 2)      //Foreach odd number until √n
        if (number % i == 0) return false;      //I have found a factor, so no prime
    
    return true;                                //This is prime
}