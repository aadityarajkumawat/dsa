#include <iostream>
#include <climits>
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

void print_all_subarrays(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            for (int k = i; k <= j; k++) {
                cout << arr[k] << " ";
            }

            cout << endl;
        }
    }
}

void max_sum_v0(int arr[], int size) {
    int max_sum = INT_MIN;
    int sum = 0;

    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            sum = 0;
            for (int k = i; k <= j; k++) {
                sum += arr[k];
            }

            max_sum = max(max_sum, sum);
        }
    }

    cout << max_sum << endl;
}

void max_sum_v1(int arr[], int size) {
    int max_sum = INT_MIN;
    int sum = 0;

    // use 1 based indexing in this array.
    int cumulative_sum[size + 1];
    cumulative_sum[0] = 0;

    for (int i = 1; i <= size; i++) {
        cumulative_sum[i] = cumulative_sum[i - 1] + arr[i - 1];
    }

    for (int i = 0; i < size; i++) {
        int sum = 0;
        for (int j = 0; j <= i; j++) {
            sum = cumulative_sum[i + 1] - cumulative_sum[j];
            max_sum = max(max_sum, sum);
        }
    }

    cout << max_sum << endl;
}

void max_sum_v2(int arr[], int size) {
    int max_sum = INT_MIN;
    int sum = 0;

    int curr_sum = 0;

    for (int i = 0; i < size; i++) {
        curr_sum += arr[i];

        if (curr_sum < 0) {
            curr_sum = 0;
        }
        max_sum = max(max_sum, curr_sum);
    }

    cout << max_sum << endl;
}

int main() {
    int arr[] = { -1, 4, 7, 2 };
    int size = 4;

    cout << "Sum of all subarrays: " << endl;
    sum_of_all_subarrays(arr, size);

    cout << "All subarrays: " << endl;
    print_all_subarrays(arr, size);

    cout << "Max sum of subarray(v0): " << endl;
    max_sum_v0(arr, size);

    cout << "Max sum of subarray(v1): " << endl;
    max_sum_v1(arr, size);

    cout << "Max sum of subarray(v2): " << endl;
    max_sum_v2(arr, size);

    return 0;
}
