#include <bits/stdc++.h>
using namespace std;

// Returns the prime factors of input
vector<int> primeFactors(int n) {
    vector<int> pf;
    for(int d=2; d<=sqrt(n); d++) {
        while(n % d == 0) {
            pf.push_back(d);
            n /= d;
        }
    }
    if(n > 1) pf.push_back(n);
    return pf;
}
