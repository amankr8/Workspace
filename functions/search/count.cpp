#include <bits/stdc++.h>
using namespace std;

// Returns the first or last occurrence of an element in an array
int binarySearch(const vector<int> &v, int x, bool first) {
    int result = -1;
    int low = 0, high = v.size() - 1;
    while (high >= low) {
        int mid = low + (high - low) / 2;
        if (v[mid] == x) {
            result = mid;
            if(first) high = mid - 1;
            else low = mid + 1;
        }
        else if (v[mid] < x) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return result;
}

// Counts frequency of an element in an array
int count(const vector<int> &v, int x) {
    int first = binarySearch(v, x, 1);
    if(first == -1) return 0;
    else {
        int last = binarySearch(v, x, 0);
        return (last - first) + 1;
    }
}
