#include <iostream>
#include <vector>
using namespace std;

struct point {
                                int x, y;

                                // Ok print do not change anything
                                auto print() const {                   
                                    cout << x << ", " << y << endl;
                                }

                                // Illegal: print change something, so no const
                                auto print2() const { 
                                    x = 20;                  
                                    cout << x << ", " << y << endl;
                                }
                            };

int main() {
    
                            const point p1 {1, 2}, p2 {2, 3};
                            const point* p3 {&p1};
                            
                            p3 = &p2;                   // Ok
                            p3.x = 30;                  //Illegal: p3 cannot change
    return 0;
}

