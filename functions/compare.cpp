#include <bits/stdc++.h>
using namespace std;

// Comparator to sort by second of pair
bool compare(pair<int, int> &a, pair<int, int> &b) {
    return (a.second < b.second);
}
