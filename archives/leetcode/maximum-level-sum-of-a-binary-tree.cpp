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
    int maxLevelSum(TreeNode* root) {
        if(root == NULL) return 0;
        
        int maxLevelSum = INT_MIN;
        
        queue<TreeNode*> q;
        q.push(root);
        
        int maxLevel = 0, level = 0;
        while(!q.empty()) {
            level++;
            int loop = q.size();
            
            int levelSum = 0;
            for(int i=0; i<loop; i++) {
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left != NULL) q.push(temp->left);
                if(temp->right != NULL) q.push(temp->right); 
                levelSum += temp->val;
            }
            
            if(levelSum > maxLevelSum) {
                maxLevelSum = levelSum;
                maxLevel = level;
            }
        }
        
        return maxLevel;
    }
};