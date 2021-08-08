#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    unordered_map<Node*, Node*> m;
    
    // BFS
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        
        Node* copy = new Node(node->val, {});
        m[node] = copy;
        
        queue<Node*> q;
        q.push(node);
        
        while(!q.empty()) {
            Node* curr = q.front();
            
            for(auto it : curr->neighbors) {
                if(!m.count(it)) {
                    m[it] = new Node(it->val, {});
                    q.push(it);
                }
                
                m[curr]->neighbors.push_back(m[it]);
            }
            
            q.pop();
        }
        
        return copy;
    }

    // DFS
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        
        if(!m.count(node)) {
            m[node] = new Node(node->val, {});
            
            for(auto it : node->neighbors) {
                m[node]->neighbors.push_back(cloneGraph(it));
            }
        }
        
        return m[node];
    }
};