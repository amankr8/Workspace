#include <bits/stdc++.h>
using namespace std;

// Binary to Decimal conversion
int toBinary(int x) {
    int i = 0, dec = 0;
    while(x > 0) {
        dec += (x%10)*pow(2, i);
        x /= 10;
        i++;
    }
    return dec;
}
