/*=============================================================================================================
==============================     NUMBER THEORY FUNCTION FOR HUMANITY       ==================================
=============================================================================================================*/
using namespace std;                                                        //Bad practice, dont do it kids!

typedef unsigned long long ull;                                             //Just a so long name, sorry
typedef long long lli;                                                      //Just a so long name, sorry

lli BinaryExponentation (lli base, ull exponent) {                          //FN: Modular Exponentation: a^b MOD n
    lli solution = 1, auxiliar = base;                                      //auxiliar variables for code clarity

    while (exponent != 0) {                                                 //End were exponent is zero
        if (exponent & 1) solution = auxiliar * solution;                   //If exponent last digit = 1 (exp is odd)

        auxiliar = auxiliar * auxiliar;                                     //Always update by squaring the aux variable
        exponent = exponent >> 1;                                           //Remove 1 digit from e to read the next one
    }

    return solution;                                                        //Return solution
}

lli RecursiveBinaryExp  (lli base, ull exponent) {                          //FN: Recursive Binary Exponentation
    if (exponent == 0) return 1;                                            //Remember base^0 = 1
    if (exponent == 1) return base;                                         //Remember base^1 = base

    if (exponent % 2 == 0)                                                  //If the exponent exponent is odd
        return RecursiveBinaryExp(base*base,  exponent / 2);                //Use the definition    
    else                                                                    //If the exponent is even
        return (base * RecursiveBinaryExp(base * base, (exponent-1) / 2));  //Use the definition
}


lli ModularExponentation(lli base, ull exponent, ull n) {                   //FN: Modular Exponentation: a^b MOD n
    lli solution = 1, auxiliar = base;                                      //auxiliar variables for code clarity

    while (exponent != 0) {                                                 //End were exponent is zero

        if (exponent & 1) solution = (auxiliar * solution) % n;             //Update solution
        
        auxiliar = (auxiliar * auxiliar) % n;                               //Always update by squaring the aux variable
        exponent = exponent >> 1;                                           //Remove 1 digit from e to read the next one

    }

    return solution;                                                        //Return solution
}

