#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct Trie {
    bool isEndOfWord = false;
    unordered_map<char, Trie*> next;

	void addWord(string word) {
		Trie* node = this;

		for (auto character : word) {
			if (!node->next[character]) 
				node->next[character] = new Trie;
			
			node = node->next[character];
		}

		node->isEndOfWord = true;
	}

	bool search(string word) {
		Trie* node = this;
		
		for (size_t i = 0; i < word.size(); i++) {
			if (node->next[word[i]] == nullptr) return false;
			node = node->next[word[i]];
		}
		return node != nullptr and node->isEndOfWord;
	}
};