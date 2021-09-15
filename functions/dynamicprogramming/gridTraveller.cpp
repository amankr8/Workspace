#include <bits/stdc++.h>
using namespace std;

int gridTraveller(int m, int n, map<pair<int, int>, int> &mp) {
    if(mp.count({m, n})) return mp[{m, n}];
    if(mp.count({n, m})) return mp[{n, m}];
    if(m == 1 || n == 1) return 1;
    mp[{m, n}] = gridTraveller(m - 1, n, mp) + gridTraveller(m, n - 1, mp);
    return mp[{m, n}];
}