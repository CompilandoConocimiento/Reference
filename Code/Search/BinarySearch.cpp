#include <iostream>
#include <vector>

using namespace std;
using lli = long long int;
using uint = unsigned int;

/**
 * Give it a container of items that is sorted and an item to find
 * and this will return you the index of such item in O(log_2(n))
 * 
 * @param left      The initial index to start searching
 * @param right     The final index to start searching; if -1 we end at Container.size() 
 * @param toFind    The number to find
 * @return          The index of the element; -1 if it was not found
 */

template <typename container, typename item>
ssize_t DiscreteBinarySearch(const container &Data, item toFind, size_t left, size_t right) {

    lli actualPosition;

    while (left <= right) {
        actualPosition = left + (right - left) / 2;
        if (Data[actualPosition] == toFind) return actualPosition;
        
        if (Data[actualPosition] < toFind) left = actualPosition + 1;
        else right = actualPosition - 1;
    }

    return -1;
}

/**
 * Give it a function f: Domain -> Domain that is monotonus, and give me an 'a'
 * and this will return you the 'x' such f(x) = a
 * 
 * @param left      The initial index to start searching
 * @param right     The final index to start searching; if -1 we end at Container.size() 
 * @param toFind    The number to find
 * @return          The index of the element; -1 if it was not found
 */

template <typename domain>
domain ContinuousBinarySearch(
   const function<domain(domain)> &f, uint iterations, domain left, domain right, domain toFind) { 
    
    domain middle;

    while (iterations--) {
        middle = left + (right - left) / 2;

        if (f(middle) < toFind) left = middle;
        else right = middle;
    }

    return (left + right) / 2;
}
