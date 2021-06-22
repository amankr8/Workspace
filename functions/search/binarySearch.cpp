#include <bits/stdc++.h>
using namespace std;

// Iterative Binary Search
int binarySearch(vector<int> &v, int x) {
    int low = 0, high = v.size() - 1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(v[mid] == x) {
            return mid;
        }
        else if(x > v[mid]) {
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
    if (low <= high) {
        int mid = low + (high - low) / 2;
        if(v[mid] == x) {
            return mid;
        }
        else if(x > v[mid]) {
            return binarySearch(v, x, low, mid - 1);
        }
        else {
            return binarySearch(v, x, mid + 1, high);
        }
    }
    return -1;
}

// Binary Search in circularly sorted array (no repeated elements)
int cBinarySearch(vector<int> &v, int x) {
    int low = 0, high = v.size() - 1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(v[mid] == x)
            return mid;
        else if(v[mid] <= v[high]) {
            if(x > v[mid] && x <= v[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
        else if(v[low] <= v[mid]) {
            if(x >= v[low] && x <= v[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
    }
    return -1;
}