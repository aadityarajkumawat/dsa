#include <iostream>
using namespace std;

// O(n) time | O(1) space
bool validateSubsequenceV0(int array[], int arraySize, int sequence[], int seqSize) {
    int arrIdx = 0;
    int seqIdx = 0;

    while (arrIdx < arraySize && seqIdx < seqSize) {
        if (array[arrIdx] == sequence[seqIdx]) {
            seqIdx += 1;
        }

        arrIdx += 1;
    }

    return seqIdx == seqSize;
}

// O(n) time | O(1) space
bool validateSubsequenceV1(int array[], int arraySize, int sequence[], int seqSize) {
    int seqIdx = 0;

    for (int i = 0; i < arraySize; i++) {
        if (seqIdx == seqSize) break;

        if (array[i] == sequence[seqIdx]) {
            seqIdx += 1;
        }
    }

    return seqIdx == seqSize;
}

int main() {
    int array[] = { 4, 2, -1, 8, 0, 5, 9, 7 };
    int sequence[] = { 2, -1, 0, 9 };

    bool isValid0 = validateSubsequenceV0(array, 8, sequence, 4);
    bool isValid1 = validateSubsequenceV1(array, 8, sequence, 4);

    if (isValid0) {
        cout << "Valid" << endl;
    }
    else {
        cout << "Invalid" << endl;
    }
    if (isValid1) {
        cout << "Valid" << endl;
    }
    else {
        cout << "Invalid" << endl;
    }

    return 0;
}
