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
    int index;
    
    int search(int start, int end, int x, vector<int>& v) {
        for(int i=start; i<=end; i++)
            if(v[i] == x)
                return i;
        return -1;
    }
    
    TreeNode* helper(int start, int end, vector<int>& preorder, vector<int>& inorder) {
        if(start > end) return NULL;
        
        int curr = preorder[index++];
        TreeNode* node = new TreeNode(curr);
        
        int pos = search(start, end, curr, inorder); 
        node->left = helper(start, pos - 1, preorder, inorder);
        node->right = helper(pos + 1, end, preorder, inorder);
        
        return node;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        index = 0;
        return helper(0, inorder.size() - 1, preorder, inorder);
    }
};