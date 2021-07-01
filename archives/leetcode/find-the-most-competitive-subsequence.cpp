#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        deque<int> dq;
        for(int i=0; i<nums.size(); i++) {
            while(!dq.empty() && (nums.size()-i) > (k-dq.size()) && dq.back() > nums[i]) {
                dq.pop_back();
            }
            if(dq.size() < k) dq.push_back(nums[i]);
        }
        vector<int> v;
        while(!dq.empty()) {
            v.push_back(dq.front());
            dq.pop_front();
        }
        return v;
    }
};