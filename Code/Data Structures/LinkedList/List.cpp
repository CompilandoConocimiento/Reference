#include <iostream>
#include <list>
#include <stack>

using namespace std;

template <typename T>
struct node {
    T value;
    node* next;

    node (T _value = T{}, node* _next = nullptr) : 
    value{_value}, next{_next}  { }
};

template <typename T>
struct LinkedList {

};

int main () {

    node<int> n {0}; 
    cout << n.value << endl;

    return 0;
}