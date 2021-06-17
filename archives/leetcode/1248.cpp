#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int> &nums, int k) {
        int count = 0;
        unordered_map<int, int> m{{0, 1}};
        int odd = 0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]%2 != 0) odd++;
            if(m.count(odd-k)) count += m[odd-k];
            m.count(odd) ? m[odd]++ : m[odd] = 1;
        }
        return count;
    }
};