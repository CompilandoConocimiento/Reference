#include <iostream>
#include <vector>

using namespace std;
using lli = long long int;

/**
 * Is just binary search  <3 ...
 * 
 * @param left      The initial index to start searching
 * @param right     The final index to start searching; if -1 we end at Container.size() 
 * @param toFind    The number to find
 * @return          The index of the element; -1 if it was not found
 */

template <typename container, typename item>
lli BinarySearch(const container &Array, item toFind, lli left = 0, lli right = -1) {
    if (right == -1) right = Array.size();
    lli actualPosition;

    while (left <= right) {
        actualPosition = left + (right - left) / 2;
        if (Array[actualPosition] == toFind) return actualPosition;
        
        if (Array[actualPosition] < toFind) left = actualPosition + 1;
        else right = actualPosition - 1;
    }

    return -1;
}
