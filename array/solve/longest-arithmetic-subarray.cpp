#include <iostream>
using namespace std;

void get_length_of_longest_arithmetic_subarray(int arr[], int size) {
    int pd = arr[1] - arr[0];
    int curr = 1;  // current length for current pd
    int ans = 0; // max of ans and curr, to get max length

    for (int i = 1; i < size; i++) {
        if (pd == arr[i] - arr[i - 1]) {
            curr += 1;
        }
        else {
            curr = 2;
            pd = arr[i] - arr[i - 1];
        }

        ans = max(ans, curr);
    }

    cout << ans << endl;
}

int main() {
    int arr[] = { 10, 7, 4, 6, 8, 10, 11 };
    int size = 7;

    get_length_of_longest_arithmetic_subarray(arr, size);

    return 0;
}
