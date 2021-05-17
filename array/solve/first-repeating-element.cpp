#include "bits/stdc++.h"
using namespace std;

void print_index(int arr[], int size) {
    int N = 1e6 + 2;
    int idx[N];
    int min_idx = INT_MAX;

    for (int i = 0;i < N;i++) {
        idx[i] = -1;
    }

    for (int i = 0;i < size;i++) {
        if (idx[arr[i]] != -1) {
            min_idx = min(min_idx, idx[arr[i]]);
        }
        else {
            idx[arr[i]] = i;
        }
    }

    if (min_idx == INT_MAX) {
        cout << "-1" << endl;
        return;
    }

    cout << min_idx + 1 << endl;
}

int main() {
    int arr[] = { 1, 5, 3, 7, 8, 3, 5, 6 };
    //          { -1, 0, -1, 2, -1, 1, -1, 3, 4, -1, -1, -1, -1, -1, -1, -1, -1 }
    int size = 8;

    print_index(arr, size);

    return 0;
}
