#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct TrieNode {
    bool isEndOfWord = false;
    unordered_map<char, TrieNode*> next;

	void addWord(const string& word) {
		TrieNode* node = this;

		for (auto character : word) {
			if (!node->next[character]) 
				node->next[character] = new TrieNode;
			
			node = node->next[character];
		}

		node->isEndOfWord = true;
	}

	bool search(const string& word) {
		TrieNode* node = this;
		
		for (size_t i = 0; i < word.size(); i++) {
			if (node->next[word[i]] == nullptr) return false;
			node = node->next[word[i]];
		}
		return node != nullptr and node->isEndOfWord;
	}
};