/*=============================================================================================================
==============================     BINARY EXPONENTATION (AND MODULAR)        ==================================
=============================================================================================================*/
using namespace std;                                                //Bad practice, dont do it kids!

typedef unsigned long long ull;                                     //Just a so long name, sorry
typedef long long lli;                                              //Just a so long name, sorry

lli BinaryExponentation (lli base, ull exponent) {                  //FN: Modular Exponentation: a^b MOD n
    lli solution = 1;                                               //auxiliar variables for code clarity

    while (exponent > 0) {                                          //End were exponent is zero
        if (exponent & 1) solution = base * solution;               //If exponent last digit = 1 (exp is odd)

        solution = solution * solution;                             //Sol = Sol^2
        exponent = exponent >> 1;                                   //Remove 1 digit from e to read the next one
    }

    return solution;                                                //Return solution
}

lli RecursiveBinaryExponentation (lli x, ull n) {                   //FN: Recursive Binary Exponentation
    if (n == 0) return 1;                                           //Remember base^0 = 1
    if (n == 1) return x;                                           //Remember base^1 = base

    if (n % 2 == 0)                                                 //If the exponent exponent is odd
        return RecursiveBinaryExponentation(x*x,  n / 2);           //Use the definition    
    else                                                            //If the exponent is even
        return (x * RecursiveBinaryExponentation(x*x, (n-1) / 2));  //Use the definition
}


lli ModularExponentation(lli base, ull exponent, ull n) {           //FN: Modular Exponentation: a^b MOD n
    lli solution = 1;                                               //Auxiliar variables for code clarity
    base = base % n;                                                //Start with the correct base

    while (exponent > 0) {                                          //End were exponent is zero
        if (exponent & 1) solution = (base * solution) % n;         //Update solution
        
        solution = (solution * solution) % n;                       //Always update by squaring the aux variable
        exponent = exponent >> 1;                                   //Remove 1 digit from e to read the next one
    }

    return solution;                                                //Return solution
}

