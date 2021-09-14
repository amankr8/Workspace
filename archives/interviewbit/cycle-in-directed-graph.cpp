#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isCycle(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& recVisited) {
        visited[node] = recVisited[node] = true;

        for(int neighbor : adj[node]) {
            if(visited[neighbor]) {
                if(recVisited[neighbor]) return true;
                continue;
            }
            if(isCycle(neighbor, adj, visited, recVisited)) return true;
        }
        recVisited[node] = false;
        return false;
    }

    int Solution::solve(int A, vector<vector<int>> &B) {
        vector<vector<int>> adj(A + 1);
        for(int i=0; i<B.size(); i++) {
            adj[B[i][0]].push_back(B[i][1]);
        }
        
        vector<bool> visited(A + 1, false);
        vector<bool> recVisited(A + 1, false);
        for(int i=1; i<=A; i++) {
            if(visited[i]) continue;
            if(isCycle(i, adj, visited, recVisited)) return true;
        }
        return false;
    }
};
