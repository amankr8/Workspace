#include <bits/stdc++.h>
using namespace std;

// Returns factors of a number
vector<int> factors(int n) {
    vector<int> factors;
    factors.push_back(1);
    if(n == 1) return factors;
    for(int i=2; i<=sqrt(n); i++) {
        if(n%i == 0) {
            factors.push_back(i);
            if(i != sqrt(n)) factors.push_back(n/i);
        }
    }
    factors.push_back(n);
    sort(factors.begin(), factors.end());
    return factors;
}
  