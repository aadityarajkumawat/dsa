#include <iostream>
#include <vector>

void swap(int &a, int &b)
{
  int temp = a;
  a = b;
  b = temp;
}

void insertionSort(std::vector<int> &nums)
{

  for (int i = 0; i < nums.size() - 1; i++)
  {
      int minInUnSortedPart = i;
      for(int j = i + 1;j < nums.size();j++)
      {
	if(nums[j] < nums[minInUnSortedPart]) {
	    minInUnSortedPart = j;
	}	  
      }
      swap(nums[i], nums[minInUnSortedPart]);
  }
}

int main()
{
  std::vector<int> nums = {64, 25, 12, 22, 11};

  insertionSort(nums);

  for(int i = 0;i < nums.size();i++) {
      std::cout << nums[i] << " ";
  }
  std::cout << std::endl;
  return 0;
}

