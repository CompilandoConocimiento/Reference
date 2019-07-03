#include <iostream>
#include <vector>

template <typename number = int>
struct topBottomFrogAndStairs {
  const number maxJump;
  const number targetStair;
  const number placeHolder;
  std::vector<number> numWaysSince;

  topBottomFrogAndStairs(number maxJump, number targetStair = 100,
                         number placeHolder = -1)
      : targetStair {targetStair},
        placeHolder {placeHolder},
        maxJump {maxJump},
        numWaysSince(targetStair + 1, placeHolder) {}

  auto howManyWaysSince(number stair) -> number {
    if (stair == targetStair) return 1;
    if (stair > targetStair) return 0;
    if (numWaysSince[stair] != placeHolder) return numWaysSince[stair];

    auto possibleWays = number {};
    for (auto jump = number {1}; jump <= maxJump; ++jump)
      possibleWays += howManyWaysSince(stair + jump);

    numWaysSince[stair] = possibleWays;
    return possibleWays;
  }
};

template <typename number = int>
struct bottomUpFrogAndStairs {
  const number maxJump;
  const number targetStair;
  const number placeHolder;
  std::vector<number> numWaysSince;

  bottomUpFrogAndStairs(number maxJump, number targetStair = 100,
                        number placeHolder = -1)
      : targetStair {targetStair},
        placeHolder {placeHolder},
        maxJump {maxJump},
        numWaysSince(targetStair + 1, placeHolder) {}

  auto howManyWaysSince(number currentStair) -> number {
    numWaysSince[targetStair] = 1;

    for (auto stair {targetStair}; stair >= 0; --stair) {
      for (auto jump = number {1}; jump <= maxJump; ++jump) {
        if (stair + jump <= targetStair) {
          numWaysSince[stair] += numWaysSince[stair + jump];
        }
      }
    }

    return numWaysSince[currentStair];
  }
};

auto main() -> int {
  using namespace std;
  using number = long long;

  number maxJump {3}, targetStair {4};
  cin >> targetStair >> maxJump;

  auto f = bottomUpFrogAndStairs<number> {maxJump, targetStair, 0};
  cout << f.howManyWaysSince(0) << endl;
  return 0;
}