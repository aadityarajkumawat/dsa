#include <iostream>
#include <unordered_map>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

void print_vector(vector<int>& array) {
    cout << "[";
    for (int i = 0; i < array.size(); i++) {
        if (i == array.size() - 1) {
            cout << array[i] << "";
        }
        else {
            cout << array[i] << ", ";
        }
    }

    cout << "]" << endl;
}

// O(n^2) time | O(1) space
vector<int> twoNumberSumV0(vector<int>& array, int targetSum) {
    for (int i = 0; i < array.size(); i++) {
        int first = array[i];

        for (int j = i + 1; j < array.size(); j++) {
            int second = array[j];

            if (first + second == targetSum) {
                return { first, second };
            }
        }
    }

    return {};
}

// O(n) time | O(n) space
vector<int> twoNumberSumV1(vector<int>& array, int targetSum) {
    unordered_map<int, bool> nums = {};

    for (int i = 0; i < array.size(); i++) {
        int potentialMatch = targetSum - array[i];

        unordered_map<int, bool>::iterator ptr = nums.find(potentialMatch);
        if (ptr != nums.end()) {
            return { potentialMatch, array[i] };
        }
        else {
            nums[array[i]] = true;
        }
    }

    return {};
}

// O(nlog(n)) time | O(1) space
vector<int> twoNumberSumV2(vector<int>& array, int targetSum) {
    sort(array.begin(), array.end());

    int left = 0;
    int right = array.size() - 1;

    while (left < right) {
        if (array[left] + array[right] == targetSum) {
            return { array[left], array[right] };
        }
        else if (array[left] + array[right] < targetSum) {
            left += 1;
        }
        else if (array[left] + array[right] > targetSum) {
            right -= 1;
        }
    }

    return {};
}

int main() {
    vector<int> array = { 3, 1, 9, -1, 2, 7, 4 };
    int targetSum = 11;

    vector<int> v0 = twoNumberSumV0(array, targetSum);
    vector<int> v1 = twoNumberSumV1(array, targetSum);
    vector<int> v2 = twoNumberSumV2(array, targetSum);

    print_vector(v0);
    print_vector(v1);
    print_vector(v2);

    return 0;
}
