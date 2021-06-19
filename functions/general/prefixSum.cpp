#include <bits/stdc++.h>
using namespace std;

// Returns an array of prefix sum of array v;
vector<int> prefixSum(const vector<int> &v) {
    vector<int> pfx(v.size());
    pfx[0] = v[0];
    for(int i=1; i<pfx.size(); i++) pfx[i] = pfx[i-1] + v[i];
    return pfx;
}
