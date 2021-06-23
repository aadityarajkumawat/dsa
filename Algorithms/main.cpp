#include <iostream>
#include "two_number_sum/two_number_sum.h"

using namespace std;

int main() {
    two_number_sum* sol = new two_number_sum();
    vector<int> array = { 3, 5, 2, 8, 2, 0, 1 };
    int target = 10;
    vector<int> ans = sol->two_number_sum_ind(array, target);
    vector<int>::iterator it;
    for(it = ans.begin(); it < ans.end(); it++) {
        cout << *it << endl;
    }
    return 0;
}
