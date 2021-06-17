#include <bits/stdc++.h>
using namespace std;

// Returns an array of prefix sum of array v;
vector<int> prefixSum(const vector<int> &v) {
    vector<int> pfx(v.size()+1);
    pfx[0] = 0;
    for(int i=1; i<pfx.size(); i++) pfx[i] = pfx[i-1] + v[i-1];
    return pfx;
}
