#include <bits/stdc++.h>
using namespace std;

// DFS (recursive)
bool hasPathRecursive(int nodes, int source, int target, vector<vector<int>>& adj, vector<int>& visited) {
    if(source == target) return true;

    visited[source] = true;
    for(int neighbor : adj[source]) {
        if(!visited[neighbor]) {
            visited[neighbor] = true;
            if(hasPathRecursive(nodes, neighbor, target, adj, visited)) return true;
        }
    }

    return false;
}

// DFS (iterative)
bool hasPathIterative(int nodes, int source, int target, vector<vector<int>>& adj, vector<int>& visited) {
    stack<int> st;
    st.push(source);
    visited[source] = true;
    while(!st.empty()) {
        int curr = st.top();
        st.pop();
        if(curr == target) return true;
        for(int neighbor : adj[curr]) {
            if(!visited[neighbor]) {
                visited[neighbor] = true;
                st.push(neighbor);
            }
        }
    }

    return false;
}

// BFS
bool hasPath(int nodes, int source, int target, vector<vector<int>>& adj, vector<int>& visited) {
    queue<int> q;
    q.push(source);
    visited[source] = true;
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        if(curr == target) return true;
        for(int neighbor : adj[curr]) {
            if(visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    while(m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int source, target;
    cin >> source >> target;
    vector<int> visited(n, false), reset(n, false);
    cout << hasPathIterative(n, source, target, adj, visited) << endl;
    visited = reset;
    cout << hasPathRecursive(n, source, target, adj, visited) << endl;
    visited = reset;
    cout << hasPath(n, source, target, adj, visited) << endl;

    return 0;
}