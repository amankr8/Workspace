#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
	struct TrieNode *child[26];
	bool isWord;
};

struct TrieNode *getNode(void) {
	struct TrieNode *node = new TrieNode;
	node->isWord = false;

	for(int i = 0; i < 26; i++) {
		node->child[i] = NULL;
    }

	return node;
}

void insert(struct TrieNode *root, string key) {
	struct TrieNode *it = root;

	for(int i=0; i<key.size(); i++) {
		int index = key[i] - 'a';
		if (it->child[index] == NULL) {
			it->child[index] = getNode();
        }
		it = it->child[index];
	}

	it->isWord = true;
}

bool search(struct TrieNode *root, string key) {
	struct TrieNode *it = root;

	for(int i=0; i<key.size(); i++) {
		int index = key[i] - 'a';
		if (it->child[index] == NULL)
			return false;
		it = it->child[index];
	}

	return (it->isWord);
}

int main() {
	
	return 0;
}
