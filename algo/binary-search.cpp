#include <iostream>
#include <vector>

int binarySearchI(std::vector<int> &nums, int n)
{
    int start = 0, end = nums.size() - 1;
    int idx = -1;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (nums[mid] == n)
        {
            idx = mid;
            break;
        }
        else if (nums[mid] > n)
            end = mid - 1;
        else
            start = mid + 1;
    }

    return idx;
}

int binarySearchR(std::vector<int> &nums, int n, int start, int end)
{
    int idx = -1;

    if (start <= end)
    {
        int mid = (start + end) / 2;

        if (nums[mid] == n)
        {
            idx = mid;
        }
        else if (nums[mid] > n)
            idx = binarySearchR(nums, n, start, mid - 1);
        else
            idx = binarySearchR(nums, n, mid + 1, end);
    }

    return idx;
}

int main()
{
    std::vector<int> nums = {30, 50, 10, 5, 33, 23, 7};
    int n = 23;

    int idx = binarySearchR(nums, n, 0, nums.size() - 1);

    std::cout << idx << std::endl;

    return 0;
}
