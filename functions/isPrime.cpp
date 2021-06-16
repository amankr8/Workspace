#include <bits/stdc++.h>
using namespace std;

// Check if a number is prime or not
bool isPrime(int x) {
    if(x == 1) return 0;
    for(int i=2; i<=sqrt(x); i++) 
        if(x%i == 0)
            return false;
    return true;
}
