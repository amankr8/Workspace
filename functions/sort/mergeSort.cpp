#include <bits/stdc++.h>
using namespace std;

// Merges two sorted vectors
void merge(vector<int> &v, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> p(n1);
    vector<int> q(n2);

    for(int i=0; i<n1; i++) p[i] = v[l + i];
    for(int i=0; i<n2; i++) q[i] = v[m + 1 + i];

    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2) {
        if(p[i] <= q[j]) {
            v[k] = p[i];
            i++;
        }
        else {
            v[k] = q[j];
            j++;
        }
        k++;
    }

    while(i < n1) {
        v[k] = p[i];
        i++;
        k++;
    }

    while(j < n2) {
        v[k] = q[j];
        j++;
        k++;
    }
}

// Merge sort function to sort a vector
void mergeSort(vector<int> &v, int l, int r) {
    if(l < r) {
        int m = l + (r - l) / 2;
        mergeSort(v, l, m);
        mergeSort(v, m + 1, r);
        merge(v, l, m, r);
    }
}
