#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isCycle(int parent, int node, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[node] = true;
        for(int neighbor : adj[node]) {
            if(neighbor == parent) continue;
            if(visited[neighbor]) return true;
            if(isCycle(node, neighbor, adj, visited)) return true;
        }
        return false;
    }

    int Solution::solve(int A, vector<vector<int>> &B) {
        vector<vector<int>> adj(A + 1);
        for(int i=0; i<B.size(); i++) {
            adj[B[i][0]].push_back(B[i][1]);
            adj[B[i][1]].push_back(B[i][0]);
        }

        vector<bool> visited(A + 1, false);
        for(int i=1; i<=A; i++) {
            if(visited[i]) continue;
            if(isCycle(-1, i, adj, visited)) return true;
        }
        return false;
    }
};
