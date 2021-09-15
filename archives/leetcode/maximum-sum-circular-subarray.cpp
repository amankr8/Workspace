#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int best_max_sum = INT_MIN, max_sum = 0, best_min_sum = INT_MAX, min_sum = 0, total = 0;
        for(int i=0; i<nums.size(); i++) {
            total += nums[i];
            
            min_sum += nums[i];
            min_sum = min(min_sum, nums[i]);
            best_min_sum = min(best_min_sum, min_sum);
            
            max_sum += nums[i];
            best_max_sum = max(best_max_sum, max_sum);
            max_sum = max(max_sum, 0);
        }
        if(best_max_sum < 0) return best_max_sum;
        return max(best_max_sum, total - best_min_sum);
    }
};