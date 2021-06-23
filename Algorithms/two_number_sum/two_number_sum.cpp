//
// Created by edydee on 23/06/21.
//

#include "two_number_sum.h"
#include <unordered_map>

vector<int> two_number_sum::two_number_sum_ind(vector<int> &array, int target) {
    unordered_map<int, int> hash_map;
    for(int i = 0; i < array.size(); i++) {
        int num = array[i];
        int other_half = target - num;
        if(hash_map.find(other_half) != hash_map.end()) {
            return { hash_map[other_half], i };
        }
        hash_map[num] = i;
    }
    return {};
}
