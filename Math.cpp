/*=============================================================================================================
====================================   MATH FUNCTION FOR HUMANITY    ==========================================
=============================================================================================================*/

#include <iostream>                                                         //Include Libraries
#include <math.h>                                                           //Include Libraries
#include <vector>                                                           //Include Libraries
using namespace std;                                                        //Bad practice, dont do it kids!

typedef unsigned long long ull;                                             //Just a so long name, sorry
typedef long long lli;                                                      //Just a so long name, sorry




/*===================================================================
=====================   FUNCTION WITH PRIMES   ======================
===================================================================*/

// ********* ERATOSTHENES SIEVE / GET PRIMES *****************************
void SieveEratosthenesBool(vector<bool> &BooleanPrimes, ull Size){          //FN: To check if i is prime: Vector[i]

    BooleanPrimes.resize(Size+1, true);                                     //Ok, first, resize so I can access it

    BooleanPrimes[0] = false;                                               //Now, 0 is not prime :o
    BooleanPrimes[1] = false;                                               //Now, 1 (maybe) is not prime :o

    for(int i = 4; i <= Size; i+=2) BooleanPrimes[i] = false;               //Eliminate all the pairs

    for(int i = 3; i*i <= Size; i+=2) {                                     //Check for every # < √i (Math things) 
        if (BooleanPrimes[i])                                               //If we still believe it's a prime
            for(ull j = i*i; j <= Size; j+= 2*i)                            //Remove all his multiples-Special limit
                BooleanPrimes[j] = false;                                   //For each multiple just remove it
    }
}

// ********* GET PRIMES / PRIMES UNTIL AN N FACTOR ***********************
void getPrimes(vector<ull> &Primes, vector<bool> &BooleanPrimes){           //FN: Return a vector give primes
    ull Size = BooleanPrimes.size();                                        //This is the size of the max prime

    for (ull i = 0; i <= Size; ++i)                                         //For each element of the Bool vector
        if (BooleanPrimes[i])                                               //If it´s prime then:
            Primes.push_back(i);                                            //Add it to the Vector
}


/*===================================================================
=============   CLASSIC ALGORITHMS AND EUCLIDES  ====================
===================================================================*/

// ******************* GREAT COMMON DIVIDER ******************************
ull GCD(ull numberA, ull numberB){                                          //FN: Return the GCD of 2 numbers
    ull reminder;                                                           //Lets create a reminder
    while(numberB != 0){                                                    //Rembember GCD(A,0) = A
        reminder = numberA % numberB;                                       //Get me the reminder of the 2 numbers
        numberA = numberB;                                                  //Know (A=BQ+R) :. GCD(A,B) = GCD(B,R)
        numberB = reminder;                                                 //Let's calculate GCD(B,R)
    }
    return numberA;                                                         //Get me the A when B is 0 GCD(A,0)=A
}

// ******************* LEAST COMMON MULTIPLE *****************************
ull LCM(lli numberA, lli numberB){                                          //FN: Return the LCM of 2 numbers     
    if (numberA > 0) numberA *= -1;                                         //Just ignore the negatives
    if (numberB > 0) numberB *= -1;                                         //Just ignore the negatives
    return (numberB * numberA) / GCD(numberA, numberB);                     //THEOREM: LCM(a, b) = (a x b) / GCD(a,b)
}


// ==============================================
// ============     MAIN        =================
// ==============================================
int main(){

    ull Size = 10000000;

    /*
    // ====== SECTION: ERATOSTHENES SIEVE =======
    vector<bool> BooleanPrimes;                                             //Get a vector this lets you if Primes
    vector<ull> Primes;                                                     //This will store all Primes as a Vector
                                                    
    SieveEratosthenesBool(BooleanPrimes, Size);                             //The hardcore Function
    getPrimes(Primes, BooleanPrimes);                                       //Now create a vector

    for (auto x : Primes) cout << x << ", ";                                //Show it!
    */



    /*
    // ====== SECTION: EUCLID AND CLASSICS =======
    lli CasualNumber;                                                       //Let's create a Casual Number

    CasualNumber = GCD(8,-10);                                              //Now check the GCD of 2 negatives : Problems
    cout << CasualNumber << endl;                                           //Show it!

    CasualNumber = LCM(8,-10);                                              //Now check the GCD of 2 negatives : Problems
    cout << CasualNumber << endl;                                           //Show it!

    */



    return 0;
}



