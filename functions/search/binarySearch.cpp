#include <bits/stdc++.h>
using namespace std;

// Iterative Binary Search
int binarySearch(vector<int> &v, int x, int low, int high) {
    while (high >= low) {
        int mid = (low + high) / 2;
        if (v[mid] == x) 
            return mid;
        if (v[mid] < x) 
            low = mid + 1;
        if (v[mid] > x) 
            high = mid - 1;
    }
    return -1;
}

// Recursive Binary Search
int binarySearch(vector<int> &v, int x, int low, int high) {
    if (high >= low) {
        int mid = (low + high) / 2;
        if (v[mid] == x) 
            return mid;
        if (v[mid] > x) 
            return binarySearch(v, x, low, mid - 1);
        if (v[mid] < x)
            return binarySearch(v, x, mid + 1, high);
    }
    return -1;
}
