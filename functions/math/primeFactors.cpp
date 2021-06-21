#include <bits/stdc++.h>
using namespace std;

// Returns the prime factors of a number
vector<int> primeFactors(int n) {
    vector<int> pf;
    for(int i=2; i<=sqrt(n); i++) {
        while(n % i == 0) {
            pf.push_back(i);
            n /= i;
        }
    }
    if(n > 1) pf.push_back(n);
    return pf;
}
