#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    TrieNode* next[26];
    bool isWord;

    TrieNode() {
        for(int i=0; i<26; i++) {
            next[i] = NULL;
        }
        isWord = false;
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* it = root;

        for(char ch : word) {
            if(!it->next[ch - 'a']) {
                it->next[ch - 'a'] = new TrieNode();
            }
            it = it->next[ch - 'a'];
        }

        it->isWord = true;
    }

    bool search(string word) {
        TrieNode* it = root;

        for(char ch : word) {
            if(!it->next[ch - 'a']) {
                return false;
            }
            it = it->next[ch - 'a'];
        }

        return it->isWord;
    }
};