#include <bits/stdc++.h>
using namespace std;

// Returns the first or last occurrence of an element in an array
int occur(const vector<int> &v, int x, bool first) {
    int result = -1;
    int low = 0, high = v.size() - 1;
    while (high >= low) {
        int mid = low + (high - low) / 2;
        if (v[mid] == x) {
            result = mid;
            if(first) high = mid - 1;
            else low = mid + 1;
        }
        else if (v[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return result;
}

// Counts the number of occurrences of an element in an array
int countOccur(const vector<int> &v, int x) {
    int firstOccur = occur(v, x, true);
    int lastOccur = occur(v, x, false);
    return (lastOccur - firstOccur) + 1;
}