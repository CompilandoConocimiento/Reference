
#include <string>

template <typename number, number base = 29, number mod = 10000000009, char minCoefficient = 'a' - 1>
struct myHash {
  static inline auto encode(std::string& word) -> number {
    auto currentExp = number {1};
    auto result = number {};

    for (auto letter : word) {
      result += ((letter - minCoefficient) * currentExp) % mod;
      currentExp = (currentExp * base) % mod;  // need to move this
    }

    return result;
  }

  static inline auto getCoefficient(char letter, number currentCoefficient) -> number {
    return ((letter - minCoefficient) * currentCoefficient) % mod;
  }

  static inline auto getNextBase(number currentBase = 1) -> number {
    return (currentBase * base) % mod;
  }
};