#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    int maxDepth(Node* root) {
        if(root == NULL) return 0;
        
        int max_depth = 0;
        for(int i=0; i<root->children.size(); i++) {
            int depth = maxDepth(root->children[i]);
            max_depth = max(max_depth, depth);
        }
        
        return 1 + max_depth;
    }
};