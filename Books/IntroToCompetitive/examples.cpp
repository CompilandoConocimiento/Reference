#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
int totalFruit(vector<int>& tree) {
  vector<pair<int, int>> trees2 {};
  
  int prev, current;
  for (int i {1}; i < tree.size(); ++i) {
    prev = tree[i - 1];
    current = tree[i];
    
    if (prev < current) 
      trees2.push_back({prev, current});
    else 
      trees2.push_back({current, prev});
  }
  
  int max {1}, maxLocal {1};
  if (trees2.size() == 0) return 1;

  auto start = trees2[0];
  prev = start.first, current = start.second;
  for (auto& step : trees2) {
    if ((prev == step.first and current == step.second) or 
    (step.first and step.second and (step.first == prev or step.first == current) )) { 
      ++maxLocal;
      if (maxLocal > max) max = maxLocal;
    }
    else {
      maxLocal = 2;
      prev = step.first, current = step.second;
    }
  }
  
  return max;
}

int main() {
    vector<int> emails {0,1,2,2};

    cout << totalFruit(emails) << endl;
}

