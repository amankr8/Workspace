#include <bits/stdc++.h>
using namespace std;

bool howSum(int targetSum, vector<int> &v, map<int, vector<int>> &m) {
    if(m.count(targetSum)) {
        if(!m[targetSum].empty()) return true;
        return false;
    }

    if(targetSum == 0) return true;
    if(targetSum < 0) return false;

    for(int i=0; i<v.size(); i++) {
        int rem = targetSum - v[i];
        if(howSum(rem, v, m)) {
            m[targetSum] = m[rem];
            m[targetSum].push_back(v[i]);
            return true;
        }
    }

    m[targetSum] = {};
    return false;
}