#include <bits/stdc++.h>
using namespace std;

// BFS
class Solution {
public:
    int calcHeight(int root, vector<vector<int>>& adj) {
        int height = -1;
        vector<int> parent(adj.size(), -1);
        
        queue<int> q;
        q.push(root);
        while(!q.empty()) {
            height++;
            int loop = q.size();
            while(loop--) {
                int head = q.front();
                q.pop();
                for(int i=0; i<adj[head].size(); i++) {
                    if(adj[head][i] == parent[head]) continue;
                    parent[adj[head][i]] = head;
                    q.push(adj[head][i]);
                }
            }
        }
        
        return height;
    }
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(int i=0; i<edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        map<int, int> ht;
        int minh = INT_MAX;
        for(int i=0; i<n; i++) {
            ht[i] = calcHeight(i, adj);
            if(ht[i] < minh) minh = ht[i];
        }
        
        vector<int> ans;
        for(auto it : ht) {
            if(it.second == minh) ans.push_back(it.first);
        }
        
        return ans;
    }
};

// DFS
class Solution {
public:
    int calcHeight(int parent, int root, vector<vector<int>>& adj) {
        if(adj[root].size() == 1 && adj[root][0] == parent) return 0;
        
        int curr_max = 0;
        for(int i=0; i<adj[root].size(); i++) {
            if(adj[root][i] == parent) continue;
            curr_max = max(curr_max, 1 + calcHeight(root, adj[root][i], adj));
        }
        
        return curr_max;
    }
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(int i=0; i<edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        int minh = INT_MAX;
        map<int, int> ht;
        for(int i=0; i<n; i++) {
            ht[i] = calcHeight(-1, i, adj);
            if(ht[i] < minh) minh = ht[i];
        }
         
        vector<int> ans;
        for(auto it : ht) {
            if(it.second == minh) ans.push_back(it.first);
        }
        
        return ans;
    }
};