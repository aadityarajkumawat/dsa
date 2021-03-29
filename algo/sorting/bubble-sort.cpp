#include <iostream>
#include <vector>

void bubbleSort(std::vector<int> &nums) {
    int n = nums.size();
    bool swapped = false;

    for(int j = 0;j < n - 1;j++) {
	swapped = false;
	for(int i = 0;i < n - j - 1;i++) {
	    if(nums[i] > nums[i + 1]) {
		int temp = nums[i];
		nums[i] = nums[i + 1];
		nums[i + 1] = temp;

		swapped = true;
	    }
	}

	if(swapped == false) {
	    break;
	}
    }
}

int main()
{
    std::vector<int> nums = {5, 1, 4, 2, 8};
    bubbleSort(nums);
    for(int i = 0;i < nums.size();i++) {
	std::cout << nums[i] << std::endl;
    }
    return 0;
}

