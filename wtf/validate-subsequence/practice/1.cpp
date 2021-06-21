#include <iostream>
#include <vector>
using namespace std;

bool validate_sum(vector<int>& arr, vector<int>& sequence) {
    int sub_idx = 0;
    bool is_valid = true;
    for (int i = 0; i < arr.size();i++) {
        if (sub_idx == sequence.size()) {
            is_valid = false;
            return is_valid;
        }
        if (arr[i] == sequence[sub_idx]) {
            sub_idx++;
        }
    }
    return is_valid;
}

int main() {
    vector<int> arr = { 4, 7, 0, -1, 8, 2, 5 };
    vector<int> sequence = { 7, 99, 2 };
    bool is_valid = validate_sum(arr, sequence);
    cout << is_valid << endl;
    return 0;
}
