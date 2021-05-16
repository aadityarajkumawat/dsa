#include <iostream>
using namespace std;

/**
 * Subarray: Continous part of an array
 * eg: [5, 7, 2, 9, 3, 0];
 * subarray: [7, 2, 9]
 * number of subarrays: nC2 + n = n(n + 1)/2
*/

void sum_of_all_subarrays(int arr[], int size) {
    int curr = 0;
    for (int i = 0; i < size; i++) {
        curr = 0;
        for (int j = i; j < size; j++) {
            curr += arr[j];
            cout << curr << " ";
        }
    }

    cout << endl;
}

int main() {
    int arr[] = { 1, 2, 0, 7, 2 };
    int size = 5;

    sum_of_all_subarrays(arr, size);

    return 0;
}
