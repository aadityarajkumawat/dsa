#include <iostream>
using namespace std;

/**
 * Time Complexity: O(n)
 *
 * ~~~~~~~~~~~~~~~~~~~~~~~ Explanation ~~~~~~~~~~~~~~~~~~~~~~~
 * We keep a variable  curr_sum to keep  track to sum  as  we  keep
 * traversing  the array. Now while  we  simply traverse the  array
 * we keep  incrementing  curr_sum with  elements  of array,  under
 * the  condition  i < n  (to have valid  indices). This   is  just
 * about  incrementing.  We  also  keep a start variable   pointing
 * to index of 0 (initially),  so  when  ever curr_sum  exceeds the
 * actual sum we start subtracting the numbers which are  available
 * at indices of start where start must be strictly less than (i-1)
 * as during the previous iteration the curr_sum was incremented by
 * the value at this index(i - 1),which was obviously i previously,
 * and we don't want to do that as then curr_sum = 0, at the end of
 * that while loop.And finally if curr_sum is equal to sum,we print
 * the indices and break from the loop,in case there is no subarray
 * we print a message mentioning the same.
*/
void subarray_by_sum(int arr[], int size, int sum) {
    int start = 0;
    int curr_sum = arr[0];

    for (int i = 1; i <= size; i++) {
        while (curr_sum > sum && start < i - 1) {
            curr_sum -= arr[start];
            start++;
        }

        if (curr_sum == sum) {
            cout << "start: " << start << endl;
            cout << "end: " << i - 1 << endl;
            break;
        }

        if (i < size) {
            curr_sum += arr[i];
        }
    }

    if (curr_sum != sum) {
        cout << "No subarray found" << endl;
    }
}

int main() {
    int arr[] = { 1, 2, 3, 8 };
    int size = 4;

    subarray_by_sum(arr, size, 5);

    return 0;
}
