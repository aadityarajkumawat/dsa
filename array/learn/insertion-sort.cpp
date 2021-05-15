#include <iostream>
using namespace std;

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertion_sort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int curr = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > curr) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = curr;
    }
}

int main() {
    cout << "Enter size of array: " << endl;
    int size;
    cin >> size;

    int arr[size];
    cout << "Enter elements of array: " << endl;
    for (int i = 0;i < size;i++) {
        cin >> arr[i];
    }

    cout << "O/P" << endl;

    print_array(arr, size);
    insertion_sort(arr, size);
    print_array(arr, size);

    return 0;
}
