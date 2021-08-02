#include <iostream>
#include <vector>
using namespace std;

// O(n) time | O(1) space
bool is_sub_sequence(vector<int>* arr, vector<int>* sub_seq) {
    int sub_seq_idx = 0;
    bool is_sub_seq = false;
    for (int i = 0; i < arr->size(); i++) {
        if ((*arr)[i] == (*sub_seq)[sub_seq_idx]) {
            sub_seq_idx++;
        }
    }
    is_sub_seq = sub_seq->size() == sub_seq_idx;
    return is_sub_seq;
}

int main() {
    vector<int> arr = { 3, 4, 5, 7, 3, 0, 11 };
    vector<int> sub_seq = { 3, 7, -1 };
    bool is_sub_seq = is_sub_sequence(&arr, &sub_seq);
    if (is_sub_seq) {
        cout << "Subsequence" << endl;
    }
    else {
        cout << "Not a subsequence" << endl;
    }
    return 0;
}
