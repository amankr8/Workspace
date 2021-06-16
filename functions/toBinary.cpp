#include <bits/stdc++.h>
using namespace std;

// Decimal to Binary conversion
int toBinary(int x) {
    int a = 1, cal = 0;
    while(x > 0) {
        cal = a*(x%2) + cal;
        x /= 2;
        a *= 10;
    }
    return cal;
}
