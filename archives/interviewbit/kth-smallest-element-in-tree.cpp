#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void helper(TreeNode* node, int& k, int& kth) {
        if(!node) return;
        helper(node->left, k, kth);
        k--;
        if(k == 0) {
            kth = node->val;
            return;
        }
        helper(node->right, k, kth);
    } 

    int Solution::kthsmallest(TreeNode* A, int B) {
        int kth;
        helper(A, B, kth);
        return kth;
    }
};