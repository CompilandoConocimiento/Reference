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




// ******************* LONG DIVISION ALGORITHM ************************
pair<lli, lli> LongDivisionAlgorithm(lli a, lli b, bool ShowIt){            //FN: Return the only q and r 
    lli q, r;                                                               //Variables, remember [0,|b|) in r

    if (b != 0) {                                                           //If we have work to do
        q = a/b;                                                            //Get me the floor of this
        r = a%b;                                                            //Get me the reminder

        if (r < 0){                                                         //If we have a problem
            (q > 0)? q++: q--;                                              //If q>0 add 1, else sub 1
            r = a - (b*q);                                                  //Recalculate reminder
        }
    }
    else {q = 0; r = a;}                                                    //b=0, this is always the result

    if (ShowIt) {                                                           //You want to see it?
        cout << "(a:"<<a<< ") = (b:"<<b<<")";                               //Show it!
        cout << "(q:"<<q<< ") + (r:"<<r<<")\n";                             //Show it!
    }

    return {q,r};                                                           //Return the info
}



// ******************* EUCLIDEAN ALGORITHM ****************************
vector< vector<lli> > EuclideanAlgorithm(lli a, lli b, bool ShowIt){        //FN: Return data for each step
    vector< vector<lli> > Data;                                             //Step by step Data[i]={a,b,q,r}    
    lli r, q;                                                               //The last 2 variables for algorithm 
    bool SpecialCase = false;                                               //This is a special case              
    if (b == 0) SpecialCase = true;                                         //Just activate this flag

    do {                                                                    //Do this at least one time
        auto Step = LongDivisionAlgorithm(a,b, false);                      //Get the long division
        q = Step.first;                                                     //Get values
        r = Step.second;                                                    //Get values

        Data.push_back({a,b,q,r});                                          //Add the result to the data

        a = b;                                                              //The new a is b
        b = r;                                                              //The new b is r
    }
    while (b != 0&& !SpecialCase);                                          //Do it! while we can

    if (ShowIt){                                                            //You want to see it?
        for (auto x : Data) {                                               //For each element in the data
            cout << "(a:"<<x[0] << ") = (b:"<<x[1]<<")";                    //Show it!
            cout << "(q:"<<x[2] << ") + (r:"<<x[3]<<") \n";                 //Show it!
        }
    }

    return Data;                                                            //Return the Data
}




// ******************* GREAT COMMON DIVIDER: EUCLIDEAN EDITION  **********
ull GCD(lli numberA, lli numberB){                                          //FN: Return Great Common Divider of 2 #
    lli reminder;                                                           //Lets create a reminder

    while(numberB != 0){                                                    //Rembember GCD(A,0) = |A|
        reminder = numberA % numberB;                                       //Get me the reminder of the 2 numbers
        numberA = numberB;                                                  //Know A=BQ+R -> GCD(A,B) = GCD(B,R)
        numberB = reminder;                                                 //Let's calculate GCD(B,R)
    }

    return abs(numberA);                                                    //Get me the A when B is 0 GCD(A,0)=|A|
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

    lli CasualNumber;                                                   //Let's create a Casual Number

    // ====== SECTION: LONG DIVISION =============  
    //LongDivisionAlgorithm(-8,0,true);
    
    
    // ====== SECTION: EUCLIDEAN ALGORITHM  ======
    auto Data = EuclideanAlgorithm(2024, 748, true);


    // ====== SECTION: APLICATIONS GCD / LCM  ====
    //cout << "GCD is " << GCD(-5,17) << endl;                            //Show it!
    //cout << "LCD is " << LCM(-5,17) << endl;                            //Show it!


    return 0;
}



