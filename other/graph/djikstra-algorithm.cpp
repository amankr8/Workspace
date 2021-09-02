#include <bits/stdc++.h>
using namespace std;

// Djikstra's Algorithm 
// ~ shortest path from single source
// ~ works only for positive weighted edges

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n+1);
    for(int i=0; i<n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int source;
    cin >> source;

    vector<int> dist(n+1, INT_MAX);
    dist[source] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});
    while(!pq.empty()) {
        int vertex = pq.top().second;
        int weight = pq.top().first;
        pq.pop();

        for(pair<int, int> p : adj[vertex]) {
            if(weight + p.second < dist[p.first]) {
                dist[p.first] = weight + p.second;
                pq.push({dist[p.first], p.first});
            }
        }
    }

    for(int i=1; i<dist.size(); i++) cout << dist[i] << " ";
    cout << endl;

    return 0;
}

/*
4 4 
1 2 24
1 4 20
3 1 3
4 3 12
1

*/