#include <bits/stdc++.h>
using namespace std;

int fib(int n, map<int, int> &m) {
    if(m.count(n)) return m[n];
    if(n == 1) return 0;
    if(n == 2) return 1;
    m[n] = fib(n-2, m) + fib(n-1, m);
    return m[n];
}