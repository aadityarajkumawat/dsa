#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

void swap(int first, int sec, vector<int> *vec) {
    int temp = (*vec)[first];
    (*vec)[first] = (*vec)[sec];
    (*vec)[sec] = temp;
}

// O(1) space | O(n^2) time
void insertionSort(vector<int> *vec) {
    for (int i = 1; i < (*vec).size(); i++) {
        int j = i;
        while (j > 0 && (*vec)[j] < (*vec)[j - 1]) {
            swap(j, j - 1, vec);
            j--;
        }
    }
}

int main() {
    vector<int> arr = {5, 8, 2, 9, 5, 6, 3};

    cout << "input array: ";
    printVector(arr);
    insertionSort(&arr);
    cout << "sorted array: ";
    printVector(arr);

    return 0;
}
