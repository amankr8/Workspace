#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

class Solution{
    public:
    int calcHeight(Node* root) {
        if(!root) return 0;
        return 1 + max(calcHeight(root->left), calcHeight(root->right));
    }
    
    bool isBalanced(Node *root) {
        if(!root) return true;
        
        int leftHt = calcHeight(root->left);
        int rightHt = calcHeight(root->right);
        
        bool currNodeIsBalanced = abs(leftHt - rightHt) <= 1;
        bool leftNodeIsBalanced = isBalanced(root->left);
        bool rightNodeIsBalanced = isBalanced(root->right);
        
        if(currNodeIsBalanced && leftNodeIsBalanced && rightNodeIsBalanced) {
            return true;
        }
        return false;
    }
};