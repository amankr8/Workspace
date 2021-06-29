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
    void checkSum(TreeNode* node, int B, int sum, vector<int> &v, vector<vector<int>> &vv) {
        if(!node) {
            v.push_back(-1);
            return;
        }
        v.push_back(node->val);
        sum += node->val;
        if(node->left == NULL && node->right == NULL) {
            if(sum == B) vv.push_back(v);
            return;
        }
        checkSum(node->left, B, sum, v, vv);
        v.pop_back();
        checkSum(node->right, B, sum, v, vv);
        v.pop_back();
    }

    vector<vector<int>> Solution::pathSum(TreeNode* A, int B) {
        vector<vector<int>> vv;
        vector<int> v;
        checkSum(A, B, 0, v, vv);
        return vv;
    }
};


