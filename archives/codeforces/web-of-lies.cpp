#include <bits/stdc++.h>
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

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<int> adj(n+1, 0);

    while(m--) {
        int u, v;
        cin >> u >> v;
        adj[min(u,v)]++;
    }

    int ans = 0;
    for(int i=1; i<=n; i++) {
        if(adj[i] == 0) ans++;
    }

    int q;
    cin >> q;

    while(q--) {
        int query, u, v;
        cin >> query;

        switch(query) {
            case 1:
                cin >> u >> v;
                if(adj[min(u, v)] == 0) ans--;
                adj[min(u, v)]++;
                break;
            case 2:
                cin >> u >> v;
                if(adj[min(u, v)] > 0) adj[min(u, v)]--;
                if(adj[min(u, v)] == 0) ans++;
                break;
            case 3:
                cout << ans << endl;
                break;
            default:
                cout << "invalid" << endl;
        }
    }
}

int main() {
    handle_io();
    solve();
    return 0;
}