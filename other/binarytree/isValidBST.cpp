#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool checkBST(TreeNode* root, int l, int r) {
        if(!root) return true;
        if(root->val <= l || root->val >= r) return false;
        return checkBST(root->left, l, root->val) && checkBST(root->right, root->val, r);
    }
    
    bool isValidBST(TreeNode* root) {
        return checkBST(root, INT_MIN, INT_MAX);
    }
};