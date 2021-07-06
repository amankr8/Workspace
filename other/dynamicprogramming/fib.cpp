#include <bits/stdc++.h>
using namespace std;

map<int, int> m;

int fib(int n) {
    if(m.count(n)) return m[n];
    if(n == 1) return 0;
    if(n == 2) return 1;
    m[n] = fib(n-2) + fib(n-1);
    return m[n];
}