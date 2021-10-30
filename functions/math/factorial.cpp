#include <bits/stdc++.h>
using namespace std;

// Recursive function to return the factorial of a number
int factorial(int n) {
    return (n == 1) ? 1 : n * factorial(n - 1);
}

int mod = pow(10, 9) + 7;
map<int, int> m;
int fact(int n) {
    if(m.count(n)) return m[n];
    if(n < 2) return 1;
    m[n] = n * fact(n - 1);
    return m[n];
}