#include <bits/stdc++.h>
using namespace std;

// Decimal to Binary conversion
int toBinary(int x) {
    int a = 1, bin = 0;
    while(x > 0) {
        bin += (x % 2) * a;
        x /= 2;
        a *= 10;
    }
    return bin;
}
