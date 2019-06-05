#include <iostream>
#include <vector>

using namespace std;

int main() {
  int number { 0b00000110 };
  int number1 = number >> 1; // 0b00001100
  int number2 = number >> 3; // 0b00110000
  if (number1 == 0b00000011) cout << "Aaa" << endl;
  if (number2 == 0b00000000) cout << "Aaa2" << endl;

  return 0;
}
