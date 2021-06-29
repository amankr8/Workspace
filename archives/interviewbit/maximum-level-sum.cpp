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
    int Solution::solve(TreeNode* A) {
        if(!A) return 0;
        int max = A->val;
        queue<TreeNode*> q;
        q.push(A);
        while(!q.empty()) {
            int currsize = q.size();
            int sum = 0;
            for(int i=0; i<currsize; i++) {
                TreeNode* curr = q.front(); 
                sum += curr->val;
                if(curr->left != NULL) q.push(curr->left);
                if(curr->right != NULL) q.push(curr->right); 
                q.pop();
            }
            if(sum > max) max = sum;
        }
        return max;
    }
};


