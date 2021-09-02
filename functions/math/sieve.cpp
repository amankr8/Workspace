#include <bits/stdc++.h>
using namespace std;

// Returns prime numbers upto a number N
vector<int> sieve(int N) {
    vector<int> v(N+1, 1), p;
    if(N < 2) return p;

    v[0] = v[1] = 0;
    p.push_back(2);
    for(int i=3; i<=N; i+=2) {
        if(v[i]) {
            p.push_back(i);
            for(int j=i*i; j<=N; j+=i)
                v[j] = 0;
        }
    }
    return p;
}
