#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

class Solution {
public:
    void visitDFS(int source, vector<vector<int>>& isConnected, unordered_set<int>& visited) {
        visited.insert(source);
        for(int i=0; i<isConnected[source].size(); i++) {
            if(isConnected[source][i] && !visited.count(i)) {
                visitDFS(i, isConnected, visited);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_set<int> visited;
        int count = 0;
        for(int i=0; i<isConnected.size(); i++) {
            if(!visited.count(i)) {
                count++;
                visitDFS(i, isConnected, visited);
            }
        }
        return count;
    }
};