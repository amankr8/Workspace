#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
        vector<int> v;
        deque<pair<int, int>> d = {{INT_MIN, -1}};
        for(int i=0; i<A.size(); i++) {
            while(!d.empty() && A[i] > d.back().first && (i - d.back().second) < B) d.pop_back();
            d.push_back({A[i], i});
            while(d.front().second < (i - B + 1)) d.pop_front();
            if(i >= B - 1) v.push_back(d.front().first);
        }
        return v;
    }

    vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
        vector<int> v;
        priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
        for(int i=0; i<A.size(); i++) {
            pq.push({A[i], i});
            while(pq.top().second < (i - B + 1)) pq.pop();
            if(i >= B - 1) v.push_back(pq.top().first);
        }
        return v;
    }
};


