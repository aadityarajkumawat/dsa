//
// Created by edydee on 23/06/21.
//

#include "ValidateSequenceProblem.h"

bool ValidateSequenceProblem::validateSum(vector<int> &array, vector<int> &sequence) {
    int arrIdx = 0;
    int seqIdx = 0;
    while(arrIdx < array.size() && seqIdx < sequence.size()) {
        if(sequence[seqIdx] == array[arrIdx]) {
            seqIdx++;
        }
        arrIdx++;
    }
    return seqIdx == sequence.size();
}
