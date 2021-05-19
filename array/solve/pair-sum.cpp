#include <iostream>
using namespace std;

bool pair_sum_v0(int arr[], int size, int k) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] + arr[j] == k) {
                cout << i << " " << j << endl;
                return true;
            }
        }
    }

    return false;
}

bool pair_sum_v1(int arr[], int size, int k) {
    int start = 0;
    int end = size - 1;

    while (start < end) {
        if (arr[start] + arr[end] > k) {
            end--;
        }
        else if (arr[start] + arr[end] < k) {
            start++;
        }
        else {
            cout << start << " " << end << endl;
            return true;
        }
    }

    return false;
}

int main() {
    int arr[] = { 2, 4, 7, 11, 14, 16, 20, 21 };
    int size = 8;
    int k = 31;

    bool is_found = pair_sum_v1(arr, size, k);

    if (is_found) {
        cout << "Found" << endl;
    }
    else {
        cout << "Not Found" << endl;
    }

    return 0;
}
