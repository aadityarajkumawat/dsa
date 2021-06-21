#include <iostream>
#include <iterator>
#include <vector>
#include <unordered_map>
using namespace std;

bool key_in_map(unordered_map<int, int>& hash_map, int key) {
    return hash_map.find(key) != hash_map.end();
}

vector<int> two_number_sum(vector<int>& nums, int target) {
    unordered_map<int, int> hash_map;
    vector<int>::iterator it;
    for (int i = 0; i < nums.size(); i++) {
        int num = nums[i];
        int other_half = target - num;
        if (key_in_map(hash_map, other_half)) {
            return { hash_map[other_half], i };
        }
        hash_map[num] = i;
    }
    return {};
}

int main() {
    vector<int> nums = { 7, 2, 6, 1, 0 };
    int target = 8;
    vector<int> ans = two_number_sum(nums, target);
    vector<int>::iterator it;
    for (it = ans.begin(); it < ans.end(); it++) {
        cout << *it << endl;
    }
    return 0;
}
