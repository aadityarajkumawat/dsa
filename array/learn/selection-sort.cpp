#include <iostream>
using namespace std;

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void selection_sort(int arr[], int size) {
    int currIdx = 0;
    for (int i = 0; i < size - 1; i++) {
        currIdx = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[currIdx]) {
                currIdx = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[currIdx];
        arr[currIdx] = temp;
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

    selection_sort(arr, size);

    print_array(arr, size);

    return 0;
}
