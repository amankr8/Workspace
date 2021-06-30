#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
        vector<int> v;
        deque<pair<int, int>> d = {{INT_MIN, -1}};
        for(int i=0; i<A.size(); i++) {
            while(!d.empty() && A[i] > d.back().first && (i - d.back().second) < B) {
                d.pop_back();
            }
            d.push_back({A[i], i});
            if(d.front().second < (i - B + 1)) d.pop_front();
            if((i + 1) >= B) {
                v.push_back(d.front().first);
            }
        }
        return v;
    }
};


