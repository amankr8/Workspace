#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

void handle_io() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main() {
    handle_io();

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

// int main() {
//     handle_io();

//     int n, m;
//     cin >> n >> m;

//     map<int, set<pair<int, int>>> adj;
//     for(int i=0; i<n; i++) {
//         int u, v, w;
//         cin >> u >> v >> w;
//         adj[u].insert({v, w});
//         adj[v].insert({u, w});
//     }

//     int source;
//     cin >> source;

//     vector<int> dist(n+1, INT_MAX);
//     dist[source] = 0;

//     set<pair<int, int>> mh;
//     mh.insert({0, source});
//     while(!mh.empty()) {
//         int node = mh.begin()->second;
//         int weight = mh.begin()->first;
//         mh.erase({node, weight});

//         for(pair<int, int> p : adj[node]) {
//             if(weight + p.second < dist[p.first]) {
//                 dist[p.first] = weight + p.second;
//                 mh.insert({dist[p.first], p.first});
//             }
//         }
//     }

//     for(int i=1; i<dist.size(); i++) cout << dist[i] << " ";
//     cout << endl;

//     return 0;
// }