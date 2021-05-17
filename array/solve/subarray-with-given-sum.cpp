#include <iostream>
using namespace std;

void subarray_by_sum(int arr[], int size, int sum) {
    int start = 0;
    int curr_sum = arr[0];

    for (int i = 1; i <= size; i++) {
        while (curr_sum > sum && start < i - 1) {
            curr_sum -= arr[start];
            start++;
        }

        if (curr_sum == sum) {
            cout << "start: " << start << endl;
            cout << "end: " << i - 1 << endl;
            break;
        }

        if (i < size) {
            curr_sum += arr[i];
        }
    }

    if (curr_sum != sum) {
        cout << "No subarray found" << endl;
    }
}

int main() {
    int arr[] = { 1, 2, 3, 8 };
    int size = 4;

    subarray_by_sum(arr, size, 5);

    return 0;
}
