#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

void fill(Node* root, vector<int>& post) {
    if(!root) return;
    fill(root->left, post);
    fill(root->right, post);
    post.push_back(root->data);
}

vector<int> preorder(Node* root) {
    vector<int> post;
    fill(root, post);
    return post;
}