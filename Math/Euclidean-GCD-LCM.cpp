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
typedef pair<lli,lli> PairOflli;                                            //Just a so long name, sorry
typedef vector< vector<lli> > MatrixOflli;                                  //Just a so long name, sorry





/*=================================================================
=============   JUST TO LEARN AND SEE STEP BY STEP   ==============
=================================================================*/
// ******************* LONG DIVISION ALGORITHM ************************
PairOflli DivisionAlgorithm(lli a, lli b, bool ShowIt){                     //FN: Return the only q and r 
    lli q, r;                                                               //Variables, remember [0,|b|) in r

    if (b != 0) {                                                           //If we have work to do
        q = a/b;                                                            //Get me the floor of this
        r = a%b;                                                            //Get me the reminder

        if (r < 0){                                                         //If we have a problem
            (q >= 0)? q++: q--;                                             //If q>0 add 1, else sub 1
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
MatrixOflli EuclideanAlgorithm(lli a, lli b, bool ShowIt){                  //FN: Return data for each step
    MatrixOflli Data;                                                       //Step by step Data[i]={a,b,q,r}    
    lli RealA = a, RealB = b, r, q;                                         //The last 2 variables for algorithm 
    bool SpecialCase = false;                                               //This is a special case              
    if (b == 0) SpecialCase = true;                                         //Just activate this flag

    do {                                                                    //Do this at least one time
        auto Step = DivisionAlgorithm(a, b, false);                         //Get the long division
        q = Step.first;                                                     //Get values
        r = Step.second;                                                    //Get values

        Data.push_back({a,b,q,r});                                          //Add the result to the data
        if (SpecialCase) break;                                             //Break if we are over

        a = b;                                                              //The new a is b
        b = r;                                                              //The new b is r
    }
    while (b != 0);                                                         //Do it! while we can

    if (ShowIt) {                                                           //You want to see it?
        cout << "=== Process: ===\n";                                       //Title
        for (auto x : Data) {                                               //For each element in the data
            cout << "(a:"<< x[0] << ") = (b:" << x[1] << ")";               //Show it!
            cout << "(q:"<< x[2] << ") + (r:" << x[3] << ")\n";             //Show it!
        }
        cout << "\nSo GCD("<<RealA<<", "<<RealB<< ") = "<<abs(a)<<"\n";     //You maybe want to know this
    }

    return Data;                                                            //Return the Data
}



// *******************EXTENDED EUCLIDEAN ALGORITHM ********************
MatrixOflli ExtendedEuclideanAlgorithm(lli a,lli b,bool ShowIt){            //FN: Return data for each step
    vector< vector<lli> > Data;                                             //Step by step Data[i]={a,b,q,r,x,y}    
    lli r, q, Temporal;                                                     //Variables for algorithm 
    lli RealA = a, RealB = b, LastM = 1, LastN = 0, m = 0, n = 1;           //Variables for Bezut Identity
    
    bool SpecialCase = false;                                               //This is a special case              
    if (b == 0) SpecialCase = true;                                         //Just activate this flag

    do {                                                                    //Do this at least one time
        auto Step = DivisionAlgorithm(a, b, false);                         //Get the long division
        q = Step.first;                                                     //Get values
        r = Step.second;                                                    //Get values

        if (SpecialCase) {Data.push_back({a, b, q, r, 1, 0}); break;}       //If b=0, original info is all we need

        Temporal = m;                                                       //Lets save m
        m = LastM - m*q;                                                    //Lets create the new m as lastm-lastm*q
        LastM = Temporal;                                                   //Now you are the last m 

        Temporal = n;                                                       //Lets save n
        n = LastN - n*q;                                                    //Lets create the new n as lastn-lastn*q
        LastN = Temporal;                                                   //Now you are the last n 
 
        Data.push_back({a, b, q, r, m, n});                                 //Add the result to the data
        a = b;                                                              //The new a is b
        b = r;                                                              //The new b is r
    }
    while (b != 0);                                                         //Do it! while we can

    if (ShowIt) {                                                           //Nou want to see it?

        cout << "=== Process for GCD: ===\n";                               //The title
        for (auto x : Data) {                                               //For each element in the data
            cout << "(a:"<<x[0]<< ") = (b:"<<x[1]<<")";                     //Show it!
            cout << "(q:"<<x[2]<< ") + (r:"<<x[3]<<") \n";                  //Show it!
        }

        cout << "\n\n=== Process for Bezut Coeficients: ===\n";             //The title for the Bezut Process
        cout << "(a':"<<RealA<< ") = " << "(a':"<<RealA<< ")(m:1) + ";      //The original lineal combination of a
        cout << "(b':"<<RealB<< ")(n:0)\n";                                 //The original lineal combination of a

        cout << "(b':"<<RealB<< ") = " << "(a':"<<RealA<< ")(m:0) + ";      //The original lineal combination of b
        cout << "(b':"<<RealB<< ")(n:1)\n\n";                               //The original lineal combination of b

        for (auto x : Data) {                                               //For each element in the data
            cout << "(r:"<<x[3]<<") = " << "(a:"<<x[0]<<") - ";             //Show it (r) = (a) - (b)(q)
            cout << "(b:"<<x[1]<<")" << "(1:"<<x[2]<<")  =  ";              //Show it (r) = (a) - (b)(q)

            cout << "(a':"<<RealA<<")(m:"<<x[4]<<") + ";                    //Show it!
            cout << "(b':"<<RealB<<")(n:"<<x[5]<<") \n";                    //Show it!
        } 

        cout << "\nSo GCD("<<RealA<<", "<<RealB<< ") = "<<abs(a)<<"\n";     //You maybe want to know this
        
        cout << "So BezutNumbers("<< RealA <<", "<< RealB << ") = ";        //You maybe want to know this
        cout << "("<< LastM <<", "<< LastN <<")\n";                         //You maybe want to know this
        
        cout << "So Bezut Indentity: (GCD:"<< abs(a) << ") = ";             //You maybe want to know this
        cout << "(a':" << RealA << ")(m:" << LastM << ") +";                //You maybe want to know this
        cout << "(b':" << RealB << ")(n:" << LastN << ") \n";               //You maybe want to know this
    }

    return Data;                                                            //Return the Data
}




/*=================================================================
========  BEST OPTIMIZATIONS OF THIS FOR REAL LIFE      ===========
=================================================================*/

// ******************* LONG DIVISION ALGORITHM ************************
PairOflli DivisionAlgorithm(lli a, lli b){                                  //FN: Return the only q and r 
    lli q, r;                                                               //Variables, remember [0,|b|) in r

    if (b != 0) {                                                           //If we have work to do
        q = a/b;                                                            //Get me the floor of this
        r = a%b;                                                            //Get me the reminder

        if (r < 0){                                                         //If we have a problem
            (q >= 0)? q++: q--;                                             //If q>0 add 1, else sub 1
            r = a - (b*q);                                                  //Recalculate reminder
        }
    }
    else {q = 0; r = a;}                                                    //b=0, this is always the result
    return {q,r};                                                           //Return the info
}



// ******************* GREAT COMMON DIVIDER: EUCLIDEAN EDITION  **********
ull GCD(lli a, lli b){                                                      //FN: Return GreatCommonDivider of 2 #
    lli reminder;                                                           //Lets create a reminder

    while(b != 0){                                                          //Rembember GCD(A,0) = |A|
        reminder = a % b;                                                   //Get me the reminder of the 2 numbers
        a = b;                                                              //Know A=BQ+R -> GCD(A,B) = GCD(B,R)
        b = reminder;                                                       //Let's calculate GCD(B,R)
    }

    return abs(a);                                                          //Get me the A when B is 0 GCD(A,0)=|A|
}



// ******************* LEAST COMMON MULTIPLE *****************************
ull LCM(lli a, lli b){                                                      //FN: Return the LCM of 2 numbers 
    return (abs(a*b)) / GCD(a, b);                                          //THEOREM: LCM(a, b) = |ab| / GCD(a,b)
}



/* ******************* BEZUT COEFFICIENTS AND GCD  **********************
    Info:
        This function will return a pair so:
        -   The first of the pair is m
        -   The seconf of the pair is n
        
        So GCD(a,b) = am + bn
        Tips:
        -   If you need GCD(a,b) and the Bezut Coeficients just
            ejecute this function and then find the GCD as:
            GCD(a,b) = am + bn

        -   If you need LCM(a,b) and the Bezut Coeficients just
            ejecute this function and then find the LCM as:
            LCM(a, b) = |ab| / am + bn
*/
PairOflli BezutCoefficients(lli a, lli b){                                  //FN: Return GreatCommonDivider of 2 #
    lli Temporal, q, r, m = 0, n = 1, LastM = 1, LastN = 0;                 //The variables

    while(b != 0){                                                          //Rembember GCD(A,0) = |A|
        auto Step = DivisionAlgorithm(a, b);                                //Get the long division
        q = Step.first;                                                     //Get values
        r = Step.second;                                                    //Get values
        
        a = b;                                                              //Know A=BQ+R -> GCD(A,B) = GCD(B,R)
        b = r;                                                              //Let's calculate GCD(B,R)

        Temporal = m;                                                       //Lets save m
        m = LastM - m*q;                                                    //Lets create the new m as lastm-lastm*q
        LastM = Temporal;                                                   //Now you are the last m 

        Temporal = n;                                                       //Lets save n
        n = LastN - n*q;                                                    //Lets create the new n as lastn-lastn*q
        LastN = Temporal;                                                   //Now you are the last n 
    }

    return {LastM, LastN};                                                  //Get me the last 2 variables
}



















// ######################################################################
// ##################          MAIN         #############################
// ######################################################################
int main(){

    // ====== SECTION: LONG DIVISION =============  
    //DivisionAlgorithm(-1,-3,true);
    cout << -5%7;
    
    // ====== SECTION: EUCLIDEAN ALGORITHM  ======
    //EuclideanAlgorithm(141, 96, true);                                  //Remember GCD is Data[Size-1][3] or is obvious 
    //ExtendedEuclideanAlgorithm(2024, 748, true);                        //GCD=Data[S-1][3], m=Data[S-1][4] N=Data[S-1][5]

    //auto Data = BezutCoefficients(141, 96);                             //Get you the pair of m and n 
    //cout << "m = "<<Data.first<< " n = "<<Data.second<< "\n";           //Show it

    // ====== SECTION: APLICATIONS GCD / LCM  ====
    //cout << "GCD is " << GCD(5,) << endl;                               //Show it!
    //cout << "LCM is " << LCM(-12,30) << endl;                           //Show it!


    return 0;
}



