#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool checkSubarraySum(vector<int> &nums, int k) {
            int sum = 0;
            unordered_map<int, int> m{{0, -1}};
            for(int i=0; i<nums.size(); i++) {
                sum += nums[i];
                if(k) sum %= k;
                if(m.count(sum)) {
                    if((i - m[sum]) > 1) return true;
                } else m[sum] = i;
            }
            return false;
        }
};