#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int> &nums, int k) {
        int count = 0;
        for(int i=0; i<nums.size(); i++) {
            int odd = 0;
            for(int j=i; j<nums.size(); j++) {
                if(nums[j]%2 == 1) odd++;
                if(odd == k) count++;
            }
        }
        return count;
    }
};