#include <iomanip>
#include <iostream>
#include <vector>

enum class direction : int { up = 0, down, left, right };

int main() {
  auto currentDirection = direction::up;
  switch (currentDirection) {
    case direction::up:
      break;
    case direction::down:
      break;
    case direction::left:
      break;
    case direction::right:
      break;
  }
  return 0;
}