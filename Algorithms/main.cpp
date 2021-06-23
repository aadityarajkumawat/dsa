#include <iostream>
#include "./validate-sequence/ValidateSequenceProblem.h"

using namespace std;

int main() {
    ValidateSequenceProblem* k = new ValidateSequenceProblem();

    vector<int> array = { 4, 6, 2, 7, 1, 0, -1, 3, 5 };
    vector<int> sequence = { 6, 1, 99, 5 };

    bool is_valid = k->validateSum(array, sequence);

    if(is_valid) {
        cout << "Sequence is valid!" << endl;
    }
    else {
        cout << "Sequence is not valid!" << endl;
    }
    return 0;
}
