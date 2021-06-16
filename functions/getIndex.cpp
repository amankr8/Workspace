#include <bits/stdc++.h>
using namespace std;

// Returns the index of a vector element
int getIndex(vector<int> v, int x) {
    auto it = find(v.begin(), v.end(), x);
    if (it != v.end()) return (it - v.begin());
    return -1;
}
