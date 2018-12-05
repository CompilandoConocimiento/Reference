#include <iostream>
#include <vector>
#include <cmath>
using namespace std; 

template<typename T>
T countDivisors(T number) { 
    T exponent, count {1}; 
    
    for (exponent = 0; (number & 1) == 0; ++exponent)  
        number = number >> 1;     
    if (exponent) count *= (exponent + 1);

    for (T i = 3; i * i <= number; i += 2) {     
        for (exponent = 0; (number % i) == 0; ++exponent) number /= i;  
        if (exponent) count *= (exponent + 1);
    }
    
    if (number > 1) count *= (1 + 1);

    return count;
}

template<typename T>
vector<T>  getDivisors(T number) { 
    vector<T> divisors, otherDivisors;

    for (T i = 1; i * i <= number; i++) { 
        if (number % i == 0) { 
            if (number / i != i) {
                divisors.push_back(i); 
                otherDivisors.push_back(number / i);
            }
            else divisors.push_back(i); 
        } 
    } 

    divisors.insert(end(divisors), rbegin(otherDivisors), rend(otherDivisors));
    return divisors;
}

