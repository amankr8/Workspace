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

map<pair<int, int>, int> myMap; 
int knapSack(int totalCost, vector<vector<int>>& combined, int n, int o1, int o2) {
    if(n == 0 || totalCost == 0) return 0;

    if(myMap.count({totalCost, n})) return myMap[{totalCost, n}];

    int cost = combined[n-1][1];
    if(n == o1 || n == o2 || cost > totalCost) {
        myMap[{totalCost, n}] = knapSack(totalCost, combined, n - 1, o1, o2);
        return myMap[{totalCost, n}];
    }

    int rating = combined[n-1][0];
    myMap[{totalCost, n}] = max(rating + knapSack(totalCost - cost, combined, n - 1, o1, o2), knapSack(totalCost, combined, n - 1, o1, o2));
    return myMap[{totalCost, n}];
}

void solve() {
    int totalCost;
    cin >> totalCost;
    int m, x;
    cin >> m >> x;
    vector<vector<int>> horr(m, vector<int>(x));
    for(int i=0; i<m; i++) {
        for(int j=0; j<x; j++) {
            cin >> horr[i][j];
        }
    }
    int n, y;
    cin >> n >> y;
    vector<vector<int>> scif(n, vector<int>(y));
    for(int i=0; i<n; i++) {
        for(int j=0; j<y; j++) {
            cin >> scif[i][j];
        }
    }

    vector<vector<int>> comb(m + n, vector<int>(2));
    for(int i=0; i<m+n; i++) {
        for(int j=0; j<2; j++) {
            if(i < m) comb[i][j] = horr[i][j];
            else comb[i][j] = scif[i-m][j];
        }
    }

    int maxRating = -1;
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            map<pair<int, int>, int> myMap;
            int o1 = i + 1;
            int o2 = m + j + 1;
            int newTotal = totalCost - horr[i][1] - scif[j][1];
            if(newTotal < 0) continue;

            int currRating = horr[i][0] + scif[j][0] + knapSack(newTotal, comb, m + n, o1, o2);
            
            maxRating = max(maxRating, currRating);
        }
    }

    cout << maxRating << endl;
}

int main() {
    handle_io();
    solve();
    return 0;
}