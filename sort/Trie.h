#pragma once
#include<string>
#include<vector>
using namespace std;

class Trie {
private:
	vector<Trie*> children;
	int pass;
	bool end;

public:
	Trie():pass(0), end(false) {
		children = vector<Trie*>(26);
	}

	void insert(string word) {
		Trie* node = this;
		if (word == "")
			return;
		
		for (int i = 0; i < word.size() - 1; ++i) {
			int index = word[i] - 'a';
			if (node->children[index] == nullptr) {
				Trie* node1 = new Trie();
				node1->pass++;
				node->children[index] = node1;
				node = node1;
			}
			else {
				node = node->children[index];
				node->pass++;
			}
		}
		int index = word[word.size()-1] - 'a';
		if (node->children[index] == nullptr) {
			Trie* node1 = new Trie();
			node1->pass++;
			node1->end = true;
			node->children[index] = node1;
		}
		else {
			node = node->children[index];
			node->pass++;
			node->end = true;
		}
	}

	bool search(string word) {
		if (word == "")
			return true;
		Trie* node = this;
		int i = 0;
		for ( ; i < word.size() - 1; ++i) {
			int index = word[i] - 'a';
			if (node->children[index] == nullptr) {
				return false;
			}
			else {
				node = node->children[index];
			}
		}
		int index = word[i] - 'a';
		if (node->children[index] == nullptr) {
			return false;
		}
		else if (!node->children[index]->end) {
			return false;
		}
		else return true;
	}

	bool startsWith(string prefix) {
		if (prefix == "")
			return true;
		Trie* node = this;
		int i = 0;
		for (; i < prefix.size(); ++i) {
			int index = prefix[i] - 'a';
			if (node->children[index] == nullptr) {
				return false;
			}
			else {
				node = node->children[index];
			}
		}

		return true;
	}
};