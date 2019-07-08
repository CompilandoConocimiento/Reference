#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
  auto someMap = map<int, string> {
      {15, "fifteen"},
      {0, "null"},
      {8, "eight"},
  };

  for (const auto& p : someMap) cout << p.first << '\n';

  return 0;
}
