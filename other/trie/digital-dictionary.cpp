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

        for(auto ch : word) {
            if(!it->next[ch - 'a']) {
                it->next[ch - 'a'] = new TrieNode();
            }
            it = it->next[ch - 'a'];
        }

        it->isWord = true;
    }

    bool search(string word) {
        TrieNode* it = root;

        for(auto ch : word) {
            if(!it->next[ch - 'a']) {
                return false;
            }
            it = it->next[ch - 'a'];
        }

        return it->isWord;
    }

    void remove(string word) {
        TrieNode* it = root;

        for(auto ch : word) {
            if(!it->next[ch - 'a']) {
                return;
            }
            it = it->next[ch - 'a'];
        }

        it->isWord = false;
    }

    void printall(TrieNode* node, string word) {
        if(node->isWord) {
            cout << word << endl;
        }

        for(int i=0; i<26; i++) {
            char ch = (char)('a' + i);
            if(node->next[i] != NULL) {
                printall(node->next[i], word + ch);
            }
        }
    }

    void print_prefix(string word) {
        TrieNode* it = root;

        for(auto ch : word) {
            if(!it->next[ch - 'a']) {
                cout << "No suggestions" << endl;
                return;
            }
            it = it->next[ch - 'a'];
        }

        printall(it, word);
    }
};

int main() {
    Trie t;

    int n;
    cin >> n;
    while(n--) {
        string s;
        cin >> s;
        t.insert(s);
    }

    int query;
    cin >> query;
    while(query--) {
        string s;
        cin >> s;
        t.print_prefix(s);
    }
}