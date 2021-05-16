#include <iostream>
using namespace std;

/**
 * Brute force
 * Time Complexity: O(n^2)
*/
void print_number_of_record_breaking_days_v0(int arr[], int size) {
    int number_of_record_breaking_days = 0;
    bool first = true;
    bool second = true;

    for (int i = 0; i < size; i++) {
        first = true;
        second = true;

        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[i]) {
                first = false;
                break;
            }
        }

        if (i != size - 1 && arr[i + 1] > arr[i]) {
            second = false;
        }

        if (first && second) {
            number_of_record_breaking_days++;
        }
    }

    cout << "Number of record breaking days: " << number_of_record_breaking_days << endl;
}

/**
 * Optimized version
 * Time Complexity: O(n)
 * To optimize, we optimize the way the
 * first condition is being checked
*/
void print_number_of_record_breaking_days_v1(int arr[], int size) {
    int number_of_record_breaking_days = 0;
    int mx = -1;

    bool first = true;
    bool second = true;

    for (int i = 0; i < size; i++) {
        first = true;
        second = true;

        mx = max(mx, arr[i]);

        if (arr[i] < mx) {
            first = false;
        }

        if (i != size - 1 && arr[i + 1] > arr[i]) {
            second = false;
        }

        if (first && second) {
            number_of_record_breaking_days++;
        }
    }

    cout << "Number of record breaking days: " << number_of_record_breaking_days << endl;
}

int main() {
    int arr[] = { 1, 2, 0, 7, 2, 0, 2, 2 };
    int size = 8;

    print_number_of_record_breaking_days_v1(arr, size);

    return 0;
}
