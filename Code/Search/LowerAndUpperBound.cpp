#include <iostream>
#include <vector>
ussing namespace std;

/**
 * @param Data      The container to iterate
 * @param target    The item to search
 * @return          The index of the element; Data.size() if not found
 */
template <typename T>
ssize_t lowerBound(std::vector<T>& Data, T target) {
    ssize_t middle, start = 0, end = Data.size();
    
    while (start < end) {
        middle = start  + (end - start) / 2;
        
        if (target > Data[middle]) start = middle + 1;
        else end = middle;
    }

    return start;
}

/**
 * @param Data      The container to iterate
 * @param target    The item to search
 * @return          The index of the element; Data.size() if not found
 */
template <typename T>
ssize_t upperBound(std::vector<T>& Data, T target) {
    ssize_t middle, start = 0, end = Data.size();
    
    while (start < end) {
        middle = start  + (end - start) / 2;
        
        if (target < Data[middle]) end = middle;
        else start = middle + 1;
    }

    return start;
}
