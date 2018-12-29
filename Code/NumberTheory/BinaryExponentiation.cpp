/*=============================================================================================================
==============================     BINARY EXPONENTIATION (AND MODULAR)       ==================================
=============================================================================================================*/
#include <iostream>

using namespace std;                                                //Bad practice, dont do it kids!
using ull = unsigned long long;                                     //Just a so long name, sorry
using lli = long long;                                              //Just a so long name, sorry

lli BinaryExponentation (lli base, ull exponent) {                  //FN: Modular Exponentiation: a^b MOD n
    lli solution = 1;                                               //auxiliar variables for code clarity

    while (exponent > 0) {                                          //End were exponent is zero
        if (exponent & 1) solution = base * solution;               //If exponent last digit = 1 (exp is odd)

        base = base * base;                                         //Sol = Sol^2
        exponent = exponent >> 1;                                   //Remove 1 digit from e to read the next one
    }

    return solution;                                                //Return solution
}

lli RecursiveBinaryExponentation (lli x, ull n) {                   //FN: Recursive Binary Exponentiation
    if (n == 0) return 1;                                           //Remember base^0 = 1
    if (n == 1) return x;                                           //Remember base^1 = base

    if (n % 2 == 0)                                                 //If the exponent exponent is odd
        return RecursiveBinaryExponentation(x*x,  n / 2);           //Use the definition    
    else                                                            //If the exponent is even
        return (x * RecursiveBinaryExponentation(x*x, (n-1) / 2));  //Use the definition
}


lli ModularBinaryExponentation(lli base, ull exponent, ull n) {     //FN: Modular Exponentiation: a^b MOD n
    lli solution = 1;                                               //Auxiliar variables for code clarity
    base = base % n;                                                //Start with the correct base

    while (exponent > 0) {                                          //End were exponent is zero
        if (exponent & 1) solution = (base * solution) % n;         //Update solution
        
        base = (base * base) % n;                                   //Always update by squaring the aux variable
        exponent = exponent >> 1;                                   //Remove 1 digit from e to read the next one
    }

    return solution;                                                //Return solution
}
