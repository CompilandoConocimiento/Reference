#include <map>
#include <string>
using namespace std;

int main() {
  map<int, string> someMap {
      {0, "null"},
      {8, "eight"},
      {15, "fifteen"},
  };

  auto element = someMap.find(9);

  if (element != end(someMap) and (*element).second == "nine") {

  }
  return 0;
}