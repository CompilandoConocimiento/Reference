#include <iostream>
#include <vector>
#include <cmath>
using namespace std; 

template<typename T>
T countDivisors(T n) { 
    T exponent, count = 1; 
    
    for (exponent = 0; (n & 1) == 0; ++exponent)  
        n = n >> 1;     
    if (exponent) count *= (exponent + 1);

    for (T i = 3; i * i <= n; i += 2) {     
        for (exponent = 0; (n % i) == 0; ++exponent) n /= i;  
        if (exponent) count *= (exponent + 1);
    }
    
    if (n > 1) count *= (1 + 1);

    return count;
}

template<typename T>
vector<T>  getDivisors(T n) { 
    vector<T> divisors, bigDivisors;

    for (T i = 1; i * i <= n; i++) { 
        if (n % i == 0) { 
            if (n / i != i) {
                divisors.push_back(i); 
                bigDivisors.push_back(n / i);
            }
            else divisors.push_back(i); 
        } 
    } 

    divisors.insert(end(divisors), rbegin(bigDivisors), rend(bigDivisors));
    return divisors;
}

