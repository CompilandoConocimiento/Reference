#include <algorithm>
#include <string>
#include <vector>
using namespace std;
#include <iostream>

template <typename number = int, typename index = int>
struct topBottomLCS {
  const std::string A;
  const std::string B;
  const number placeHolder;
  std::vector<std::vector<number>> memorized;

  topBottomLCS(std::string A, std::string B, number placeHolder = -1)
      : A {A},
        B {B},
        placeHolder {placeHolder},
        memorized(A.size() + 1,
                  std::vector<number>(B.size() + 1, placeHolder)) {}

  auto LCSSince(index i, index j) -> number {
    if (i >= A.size() or j >= B.size()) return 0;
    if (memorized[i][j] != placeHolder) return memorized[i][j];

    if (A[i] == B[j]) return memorized[i][j] = LCSSince(i + 1, j + 1) + 1;
    return memorized[i][j] = std::max(LCSSince(i + 1, j), LCSSince(i, j + 1));
  }
};

template <typename number = int, typename index = int>
struct bottomUpLCS {
  const std::string A;
  const std::string B;
  const number placeHolder;
  std::vector<std::vector<number>> LCSUntil;

  bottomUpLCS(std::string A, std::string B, number placeHolder = -1)
      : A {A},
        B {B},
        placeHolder {placeHolder},
        LCSUntil(A.size() + 1, std::vector<number>(B.size() + 1)) {}

  auto getLCSUntil(index sizeA, index sizeB) -> number {
    for (index endStringA {}; endStringA <= sizeA; ++endStringA) {
      for (index endStringB {}; endStringB <= sizeB; ++endStringB) {
        if (endStringA == 0 or endStringB == 0)
          LCSUntil[endStringA][endStringB] = 0;
        else if (A[endStringA - 1] == B[endStringB - 1])
          LCSUntil[endStringA][endStringB] =
              1 + LCSUntil[endStringA - 1][endStringB - 1];
        else
          LCSUntil[endStringA][endStringB] =
              max(LCSUntil[endStringA - 1][endStringB],
                  LCSUntil[endStringA][endStringB - 1]);
      }
    }

    return LCSUntil[sizeA][sizeB];
  }
};

auto main() -> int {
  using namespace std;

  string A, B;
  cin >> A >> B;

  auto LCS = bottomUpLCS<int> {A, B, 0};
  cout << LCS.getLCSUntil(A.size(), B.size()) << endl;
  return 0;
}