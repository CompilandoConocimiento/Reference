#include <iostream>
#include <vector>

using namespace std;

template <class T>  
inline void getNumberFast(T &result) {                   
  T number {};                                                      
  bool sign {};

  char currentDigit {static_cast<char>(getchar_unlocked())};
  
  while(currentDigit < '0' or currentDigit > '9') {
    currentDigit = getchar_unlocked(); 
    if (currentDigit == '-') sign = true;                     
  }

  while ('0' <= currentDigit and currentDigit <= '9') {          
    number = (number << 3) + (number << 1) + (currentDigit - '0');  
    currentDigit = getchar_unlocked();                             
  }

  if (sign) result = -number;
  else result = number;
}

int main() {
  int numberOfElements;
  getNumberFast(numberOfElements);

  cout << numberOfElements << endl;

  std::vector<int> elements {};
  elements.resize(numberOfElements);
  cout << elements.size() << endl;

  for (size_t i {}; i < numberOfElements; ++i) {
    getNumberFast(elements[i]);
    cout << elements[i] << endl;
  }

  cout << elements.size() << endl;

  for (auto x : elements) {
    cout << 2 * x << endl;
  }

  return 0;
}

