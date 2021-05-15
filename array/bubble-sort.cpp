#include <iostream>
using namespace std;

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubble_sort(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
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

    bubble_sort(arr, size);

    print_array(arr, size);

    return 0;
}
