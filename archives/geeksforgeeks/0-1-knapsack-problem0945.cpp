#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    map<pair<int, int>, int> m;
    int knapSack(int W, int wt[], int val[], int n) {
       if(n == 0 || W == 0) return 0;
       if(m.count({W, n})) return m[{W, n}];
       if(wt[n - 1] > W) {
           m[{W, n}] = knapSack(W, wt, val, n - 1);
           return m[{W, n}];
       }
       m[{W, n}] = max(val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1), knapSack(W, wt, val, n - 1));
       return m[{W, n}];
    }
};