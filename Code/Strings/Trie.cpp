#include <array>
#include <string>

template <typename index, size_t alphabetSize = 27>
struct Trie {
  bool isEndOfWord;
  std::array<Trie*, alphabetSize> next;

  Trie() : isEndOfWord {false} { next.fill(nullptr); }

  static auto nextIndex(char character) -> int { return character - 'a'; }

  auto addWord(const std::string& word) -> void {
    auto* node = this;

    for (auto character : word) {
      auto* nextNode = node->next[nextIndex(character)];
      if (not nextNode) nextNode = new Trie;
      node = nextNode;
    }

    node->isEndOfWord = true;
  }

  auto search(const std::string& word) -> bool const {
    auto* node = this;

    for (auto character : word) {
      auto* nextNode = node->next[nextIndex(character)];
      if (not nextNode) return false;
      node = nextNode;
    }

    return node->isEndOfWord;
  }
};

#include <iostream>
auto main() -> int {
  Trie<int, 26> t {};
  auto s1 = std::string {"hola"};
  auto s2 = std::string {"holaq"};
  auto s3 = std::string {"hoaw"};

  t.addWord(s1);
  t.addWord(s2);
  t.addWord(s3);

  std::cout << t.search("sas") << std::endl;
  std::cout << t.search("hola") << std::endl;
  std::cout << t.search("holaq") << std::endl;
}