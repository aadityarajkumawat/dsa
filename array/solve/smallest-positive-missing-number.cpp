#include <iostream>
using namespace std;

void print_positive_smallest_missing_number(int arr[], int size) {
    int N = 1e2 + 2;
    bool check[N];
    int idx = -1;

    for (int i = 0; i < N; i++) {
        check[i] = false;
    }

    for (int i = 0; i < size; i++) {
        if (arr[i] >= 0) {
            check[arr[i]] = true;
        }
    }

    for (int i = 0; i < size; i++) {
        if (check[i] == false) {
            idx = i;
            break;
        }
    }

    cout << idx << endl;
}

int main() {
    int arr[] = { 0, -9, 1, 3, -4, 5 };
    int size = 6;

    print_positive_smallest_missing_number(arr, size);

    return 0;
}
