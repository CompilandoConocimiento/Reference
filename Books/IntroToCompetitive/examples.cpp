#include <iostream>
#include <vector>
using namespace std;

int main() {
    const int a {10};
    auto& b {a};
    auto&& b =  10;
    
    return 0;
}

