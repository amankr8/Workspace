#include <bits/stdc++.h>
using namespace std;

bool canSum(int targetSum, vector<int> &v, map<int, bool> &m) {
    if(m.count(targetSum)) return m[targetSum];
    if(targetSum == 0) return true;
    if(targetSum < 0) return false;
    for(int i=0; i<v.size(); i++) {
        int rem = targetSum - v[i];
        if(canSum(rem, v, m)) {
            m[targetSum] = true;
            return true;
        }
    }
    m[targetSum] = false;
    return false;
}