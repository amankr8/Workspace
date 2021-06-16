#include <bits/stdc++.h>
using namespace std;

// Input a vector< vector<long long> >
vector< vector<int> > getVV32() {
    int n, m;
    cin >> n >> m;
    vector< vector<int> > vv(n, vector<int> (m));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> vv[i][j];
    return vv;
}
