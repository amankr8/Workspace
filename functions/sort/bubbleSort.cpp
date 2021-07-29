#include <bits/stdc++.h>
using namespace std;

// Bubble sort function to sort a vector
void bubbleSort(vector<int>& v) {
    for(int i=1; i<v.size(); i++) {
        for(int j=0; j<v.size()-i; j++) {
            if(v[j] > v[j+1]) {
                swap(v[j], v[j+1]);
            }
        }
    }
}