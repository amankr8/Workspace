#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &v, int x, int low, int high) {
    if (high >= low) {
        int mid = low + (high - low) / 2;
        if (v[mid] == x) return mid;
        if (v[mid] > x) return binarySearch(v, x, low, mid - 1);
        return binarySearch(v, x, mid + 1, high);
    }
    return -1;
}