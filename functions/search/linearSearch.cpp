#include <bits/stdc++.h>
using namespace std;

// Linear Search
int linearSearch(vector<int> v, int x) {
    for(int i=0; i<v.size(); i++)
        if(v[i] == x) 
            return i;
    return -1;
}