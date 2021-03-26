#include <iostream>
#include <vector>
#include <cmath>

int jumpSearch(std::vector<int> &nums, int x)
{
    int step = std::sqrt(nums.size());
    int low = 0, high = step;
    int idx = -1;

    while (nums[high] < x && high < nums.size())
    {
        high += step;
        low += step;
    }

    for (int i = low; i <= high; i++)
    {
        if (nums[i] == x)
        {
            idx = i;
            break;
        }
    }

    return idx;
}

int main()
{
    std::vector<int> nums = {5, 12, 15, 21, 28, 33, 37, 40, 41, 43, 49, 50, 52, 53, 54, 55};
    //`````````````````````` 0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15
    int n = 55;

    int idx = jumpSearch(nums, n);

    std::cout << idx << std::endl;
    return 0;
}
