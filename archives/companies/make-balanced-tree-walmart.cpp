#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};

TreeNode* buildTree(int p, int i, vector<int>& parent) {
    if(i >= parent.size() || parent[i] != p) return NULL;

    TreeNode* node = new TreeNode(i);
    node->left = buildTree(i, i+1, parent);
    node->right = buildTree(i, i+2, parent);
    return node;
}

int minNodes;

int calcHeight(TreeNode* root) {
    if(!root) return 0;
    return 1 + max(calcHeight(root->left), calcHeight(root->right));
}

void calcMin(TreeNode *node) {
    if(!node) return;
    
    int leftHt = calcHeight(node->left);
    int rightHt = calcHeight(node->right);
    
    int diff = abs(leftHt - rightHt);
    if(diff > 1) minNodes += (diff - 1);

    calcMin(node->left);
    calcMin(node->right);
}

int solve(int N, vector<int>& parent) {
    TreeNode* root = buildTree(-1, 0, parent);

    minNodes = 0;
    calcMin(root);
    return minNodes;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    cout << solve(n, v) << endl;
    return 0;
}

/*
5
-1
0
1
2
2

Tree representation:

    0
     \
      1
       \
        2
       / \
      3   4

*/