/*=============================================================================================================
==============================     NUMBER THEORY FUNCTION FOR HUMANITY       ==================================
=============================================================================================================*/

#include <math.h>                                                           //Include Libraries
#include <stdlib.h>                                                         //Include Libraries
#include <iostream>                                                         //Include Libraries
#include <vector>                                                           //Include Libraries
using namespace std;                                                        //Bad practice, dont do it kids!

typedef unsigned long long ull;                                             //Just a so long name, sorry
typedef long long lli;                                                      //Just a so long name, sorry



// ********* ERATOSTHENES SIEVE / GET PRIMES USING BOOLS *************
vector<bool> EratosthenesSieveBoolVector(ull Size){                         //FN: To check if i is prime use Vector[i]
    vector<bool> BoolPrimes(Size+1, true);                                  //Ok, first, resize so I can access it

    BoolPrimes[0] = false;                                                  //Now, 0 is not prime :o
    BoolPrimes[1] = false;                                                  //Now, 1 (maybe) is not prime :o

    for (int i = 4; i <= Size; i+= 2) BoolPrimes[i] = false;                //Eliminate all the pairs

    for (int i = 3; i*i <= Size; i+= 2) {                                   //Check for every # < √i (Math things) 
        if (BoolPrimes[i])                                                  //If we still believe it's a prime
            for (ull j = i*i; j <= Size; j+= 2*i)                           //Remove all his multiples-Special limit
                BoolPrimes[j] = false;                                      //For each multiple just remove it
    }

    return BoolPrimes;                                                      //Return the info to know witch number is prime
}

// ********* GET PRIMES / PRIMES UNTIL AN N FACTOR ******************
vector<ull> PrimeVectorUsingSieve(const vector<bool> &BoolPrimes){          //FN: Return a vector with all primes of the Sieve
    vector<ull> VectorOfPrimes;                                             //This is were we will have all the Primes

    for (ull i = 0, Size = BoolPrimes.size(); i <= Size; ++i)               //For each element of the Bool vector
        if (BoolPrimes[i]) VectorOfPrimes.push_back(i);                     //If it´s prime then add it to the Vector

    return VectorOfPrimes;                                                  //Return the complete vector with all the info
}






// ==============================================
// ============     MAIN        =================
// ==============================================
int main(){
    ull Size = 10000000;                                                //Just the max n

    // ====== SECTION: ERATOSTHENES SIEVE =================                                                 
    vector<bool> BoolPrimes = EratosthenesSieveBoolVector(Size);        //T or F: check if i is prime using Vector[i]
    vector<ull> VectorPrimes = PrimeVectorUsingSieve(BoolPrimes);       //Now create a vector with all primes until Size

    for (auto PrimeNumber : VectorPrimes) cout << PrimeNumber << "\n";  //Show it!

    return 0;
}



