#include <bits/stdc++.h>
using namespace std;

map<long long, long long> m;
long long fact(long long n) {
    if(m.count(n)) return m[n];
    if(n < 2) return 1;
    m[n] = n*fact(n-1);
    return m[n];
}

int give(int N, int K, vector<int>& A) {
    vector<int> v(10001, 0);
    long long pairs = 0;
    int l = 0, r = 0;
    while(pairs != K) {
        if(pairs < K) {
            if(r >= A.size()) break;
            int s = v[A[r]];
            v[A[r]]++;
            pairs -= fact(s) / 2;
            pairs += fact(s + 1) / 2;
            r++;
        }
        else {
            if(l >= r) break;
            int s = v[A[l]];
            v[A[l]]--;
            pairs -= fact(s) / 2;
            pairs += fact(s - 1) / 2;
            l++;
        }
    }
    return (r - l);
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];

    cout << give(n, k, v) << endl;
    return 0;
}

/*
5 2
1 2 1 2 1

*/