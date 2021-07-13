#include <bits/stdc++.h>
using namespace std;

vector<int> howSum(int targetSum, vector<int> &v, map<int, vector<int>> &m) {
    if(targetSum == 0) return {};
    if(targetSum < 0) return {-1};

    vector<int> min;
    for(int i=0; i<v.size(); i++) {
        int rem = targetSum - v[i];
        vector<int> temp = howSum(rem, v, m);
        if(!temp.empty() && temp[0] == -1) continue; 
        temp.push_back(v[i]);
        if(min.empty() || temp.size() < min.size()) {
            min = temp;
        }
    }

    if(min.empty()) return {-1};
    return min;
}