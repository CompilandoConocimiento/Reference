#include <string>
#include <unordered_map>
using namespace std;

struct Trie {
  bool isEndOfWord = false;
  std::unordered_map<char, Trie*> next;

  auto addWord(const std::string& word) -> void {
    auto* node = this;

    for (auto character : word) {
      auto& nextNode = node->next[character];
      if (!nextNode) nextNode = new Trie;
      node = nextNode;
    }

    node->isEndOfWord = true;
  }

  auto search(const std::string& word) -> bool {
    auto* node = this;

    for (auto character : word) {
      const auto nextNode = node->next[character];
      if (!nextNode) return false;
      node = nextNode;
    }

    return node->isEndOfWord;
  }
};
