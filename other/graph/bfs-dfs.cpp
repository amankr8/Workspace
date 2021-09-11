#include <bits/stdc++.h>
using namespace std;

void print_dfs(int root, vector<bool> visited, vector<vector<int>>& adj) {
    stack<int> st;
    st.push(root);
    visited[root] = true;
    while(!st.empty()) {
        int curr = st.top();
        st.pop();
        cout << (char)(curr + 'a') << " ";
        for(int neighbor : adj[curr]) {
            if(visited[neighbor]) continue;
            visited[neighbor] = true;
            st.push(neighbor);
        }
    }
    cout << endl;
}

void print_bfs(int root, vector<bool> visited, vector<vector<int>>& adj) {
    queue<int> q;
    q.push(root);
    visited[root] = true;
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        cout << (char)(curr + 'a') << " ";
        for(int neighbor : adj[curr]) {
            if(visited[neighbor]) continue;
            visited[neighbor] = true;
            q.push(neighbor);
        }
    }
    cout << endl;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<bool> visited(n, false);
    vector<vector<int>> adj(n);
    while(m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    print_dfs(0, visited, adj);
    print_bfs(0, visited, adj);
}