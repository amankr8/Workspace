#include <bits/stdc++.h>
using namespace std;

// Returns the frequency of a number in an array
int calcFreq(vector<int> arr, int x) {
    int f = 0;
    for(int i=0; i<arr.size(); i++) if(arr[i] == x) f++;
    return f;
}
