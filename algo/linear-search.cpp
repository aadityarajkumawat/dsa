#include <iostream>
#include <vector>

bool plainLinearSearch(std::vector<int> &nums, int n)
{
	int foundIndex = -1;
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] == n)
			foundIndex = i;
	}

	return foundIndex != -1;
}

bool improvedLinearSearch(std::vector<int> &nums, int n)
{
	int left = 0, right = nums.size() - 1;
	int pos = -1;

	while (left <= right)
	{
		if (nums[left] == n)
		{
			pos = left;
			break;
		}

		if (nums[right] == n)
		{
			pos = right;
			break;
		}

		left++;
		right--;
	}

	return pos != -1;
}

int main()
{
	std::vector<int> nums = {30, 50, 10, 5, 33, 23, 7};
	int n = 23;

	// bool nIsThere = plainLinearSearch(nums, n);
	bool nIsThere = improvedLinearSearch(nums, n);

	if (nIsThere)
	{
		std::cout << "cool" << std::endl;
	}

	return 0;
}
