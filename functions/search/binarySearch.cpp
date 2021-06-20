#include <bits/stdc++.h>
using namespace std;

// Iterative Binary Search
int binarySearch(vector<int> &v, int x) {
    int low = 0, high = v.size() - 1;
    while (high >= low) {
        int mid = low + (high - low) / 2;
        if (v[mid] == x) {
            return mid;
        }
        else if (v[mid] < x) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1;
}

// Recursive Binary Search
int binarySearch(vector<int> &v, int x, int low, int high) {
    if (high >= low) {
        int mid = low + (high - low) / 2;
        if (v[mid] == x) {
            return mid;
        }
        else if (v[mid] > x) {
            return binarySearch(v, x, low, mid - 1);
        }
        else {
            return binarySearch(v, x, mid + 1, high);
        }
    }
    return -1;
}
