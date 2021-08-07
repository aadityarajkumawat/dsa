#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// O(n^2) time | O(1) space
vector<int> twoNumberSum1(vector<int>* nums, int* target) {
    vector<int> twoNums;
    for (int i = 0; i < nums->size() - 1; ++i) {
        int curr = (*nums)[i];
        for (int j = i + 1; j < nums->size(); ++j) {
            int otherHalf = (*nums)[j];
            if (curr == (*target) - otherHalf) {
                twoNums.insert(twoNums.begin(), { curr, otherHalf });
                return twoNums;
            }
        }
    }
    return {};
}

vector<int> twoNumberSum2(vector<int>* nums, int* target) {
    vector<int> twoNums;
    unordered_map<int, bool> hashMap;
    for (int i = 0; i < nums->size(); ++i) {
        int curr = (*nums)[i];
        int otherHalf = (*target) - curr;
        unordered_map<int, bool>::iterator it = hashMap.find(otherHalf);
        if (it != hashMap.end()) {
            twoNums.insert(twoNums.begin(), { curr, otherHalf });
            return twoNums;
        }
        hashMap.insert({ curr, true });
    }
    return {};
}

int main() {
    vector<int> nums = { 4, 8, -2, 0, 3, 2, 5 };
    int target = 7;

    vector<int> twoNums = twoNumberSum2(&nums, &target);
    vector<int>::iterator it;
    for (it = twoNums.begin(); it != twoNums.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}
