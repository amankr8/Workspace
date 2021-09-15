#include <bits/stdc++.h>
using namespace std;

vector<int> djikstra(int vertices, int source, vector<vector<pair<int,int>>>& adj) {
    vector<int> dist(vertices + 1, INT_MAX);
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

    dist.erase(dist.begin());
    return dist;
}

/*
4 4 
1 2 24
1 4 20
3 1 3
4 3 12
1

*/