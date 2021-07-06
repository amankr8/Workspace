#include <bits/stdc++.h>
using namespace std;

map<pair<int, int>, int> mp;

int gridTraveller(int m, int n) {
    if(mp.count({m, n})) return mp[{m, n}];
    if(mp.count({n, m})) return mp[{n, m}];
    if(m == 1 || n == 1) return 1;
    mp[{m, n}] = gridTraveller(m - 1, n) + gridTraveller(m, n - 1);
    return mp[{m, n}];
}