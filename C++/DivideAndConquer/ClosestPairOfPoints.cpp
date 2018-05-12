/*================================================================
==============     CLOSEST PAIR OF POINTS    =====================
================================================================*/
#include <cstdlib>                                                          //Include Libraries
#include <cmath>                                                            //Include Libraries
#include <algorithm>
#include <limits>

using namespace std;                                                        //Bad practice


/*========================================
==========       POINT STRUCT    =========
========================================*/
struct Point {                                                              //A real struct
    double x, y;                                                            //Get the data
};

/*========================================
==========  HELPER FUNCTIONS     =========
========================================*/
inline double Distance(Point &P1, Point &P2) {                              //Distance
    return (P1.x - P2.x) * (P1.x - P2.x) + (P1.y - P2.y)*(P1.y - P2.y);     //Calculus
}
 
double BruteForce(Point Points[], size_t Size) {                            //Brute Force
    
    double MinimunDistance = numeric_limits<double>::max();                 //Get a cool max
    
    for (auto i = 0; i < Size; ++i) {                                       //Foreach point
        for (auto j = i + 1; j < Size; ++j) {                               //Foreach point
            double CurrentDistance = Distance(Points[i], Points[j]);        //Get the distance
            if (CurrentDistance < MinimunDistance)                          //If better
                MinimunDistance = CurrentDistance;                          //Add it!
        }
    }

    return MinimunDistance;                                                 //Now return
}


/*========================================
==========   REAL FUNCTIONS      =========
========================================*/
double StripClosest(Point Strip[], size_t Size, double d) {
    double MinimunDistance = d;                                             //Start the Distance

    std::sort(Strip, Strip + Size,                                          //First Sort the
        [](const Point& P1, const Point& P2) {                              //point about the
            return P1.y < P2.y;                                             //x - axis
        }
    );

    for (int i = 0; i < Size; ++i) {                                        //For each point
        for (int j = i + 1; j < Size; ++j) {                                //For each point

            if ((Strip[j].y - Strip[i].y) >= MinimunDistance) break;        //If not good, bye

            double CurrentDistance = Distance(Strip[i], Strip[j]);          //Get the distance
            if (CurrentDistance < MinimunDistance)                          //If better
                MinimunDistance = CurrentDistance;                          //Add it!
        }
    }
 
    return MinimunDistance;
}

double ClosestsPoints(Point Points[], size_t NumberOfPoints) {              //Recursice function
        
    if (NumberOfPoints < 80) return BruteForce(Points, NumberOfPoints);    //Simple case

    size_t Middle = NumberOfPoints / 2;                                     //Find the middle place
 
    double MinDistanceSide = min(                                           //Smallest distance
        ClosestsPoints(Points, Middle),                                     //Left size
        ClosestsPoints(Points + Middle, NumberOfPoints - Middle)            //Right size
    );                                                  

    Point Strip[NumberOfPoints];                                            //Line at middle point
    int SizeOfStrip = 0;                                                    //The Real Size

    for (int i = 0; i < NumberOfPoints; i++) {                              //For each point
        if (abs(Points[i].x - Points[Middle].x) < MinDistanceSide)          //Are in the radius
            Strip[SizeOfStrip++] = Points[i];                               //Add it!
    }

    return min(                                                             //Return the minimum
        MinDistanceSide,                                                    //Of the sides
        StripClosest(Strip, SizeOfStrip, MinDistanceSide)                   //And the distance
    );
}
 


double ClosestPairOfPoints(Point Points[], int NumberOfPoints) {             //Init Funcion

    std::sort(Points, Points + NumberOfPoints,                              //First Sort the
        [](const Point& P1, const Point& P2) {                              //point about the
            return P1.x < P2.x;                                             //x - axis
        }
    );

    return ClosestsPoints(Points, NumberOfPoints);                          //Recursice Function
}
 


/*======================================================
================        MAIN          ==================
======================================================*/
int main() {                                                                //General Main

    int NumberOfPoints; scanf("%d", &NumberOfPoints);
    Point Points[NumberOfPoints];                                           //Now reserve space

    for (int i = 0; i < NumberOfPoints; ++i) {                              //Now get the data
        scanf("%lf %lf", &Points[i].x, &Points[i].y);
    }
    
    printf("%.3lf\n", sqrt(ClosestPairOfPoints(Points, NumberOfPoints)) );

    return 0;
}



