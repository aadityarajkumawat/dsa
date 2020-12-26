/**
* Practice Everyday
*/
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;


int main() {
  vector<int> nums = { 2, 4, 7, 9, 11 };
  vector<int>::iterator ptr;
  /**
   * <vector>.begin -> gives a iterator pointing to first element of vector
   * <vector>.end -> return a iterator pointing to element one past the last(0);
  */
  for (ptr = nums.begin(); ptr < nums.end(); ptr++) {
    cout << (*ptr) << " ";
  }
  cout << endl;

  /**
   * <vector>.advance -> move iterator by n-positions
  */
  vector<int>::iterator qtr;
  qtr = nums.begin();
  // Now to move qtr by 2 positions
  advance(qtr, 2);

  cout << *(qtr) << endl;

  // iterator to nth position from begining and end
  // next() and prev()
  qtr = nums.begin();
  vector<int>::iterator second_from_begin = next(qtr, 2);
  qtr = nums.end();
  vector<int>::iterator third_from_end = prev(qtr, 3);

  cout << *(second_from_begin) << " " << *(third_from_end) << endl;

  return 0;
}
