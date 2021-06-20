#include <bits/stdc++.h>
using namespace std;

// Calculates the rotation count of a sorted array
int findRotationCount(const vector<int> &v) {
    int low = 0, high = v.size() - 1;
    while (low <= high) {
        if(v[low] <= v[high])
            return low;
        int mid = low + (high - low) / 2;
        int next = (mid + 1) % v.size();
        int prev = (mid + v.size() - 1) % v.size();
        if(v[mid] <= v[next] && v[mid] <= v[prev])
            return mid;
        else if(v[mid] <= v[high])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1; // invalid case
}