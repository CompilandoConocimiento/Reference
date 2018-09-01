#include <iostream>
#include <vector>

using namespace std;
using lli = long long int;

/**
 * @param left      The initial index to start searching
 * @param right     The final index to start searching; if -1 we end at Container.size() 
 * @param toFind    The number to find
 * @return          The index of the element; -1 if it was not found
 */

template <typename domain>
domain ContinuousTernarySearch(
    const function<domain(domain)> &f, uint iterations, domain left, domain right) { 
    domain leftThird, rightThird;

    while (iterations--) {
        leftThird = left + (right - left) / 3;
        rightThird = right - (right - left) / 3;

        if ( f(leftThird) < f(rightThird) ) left = leftThird;
        else right = rightThird;
    }

    return (left + right) / 2;
}
