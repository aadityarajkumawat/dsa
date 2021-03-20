#include <iostream>
#include <vector>
#include <cmath>

int jumpSearch(std::vector<int> &nums, int x, int n)
{
    int step = std::sqrt(n);
    int prev = 0;

    while (nums[std::min(step, n) - 1] < x)
    {
        prev = step;
        step += std::sqrt(n);
        if (prev >= n)
            return -1;
    }

    while (nums[prev] < x)
    {
        prev++;
        if (prev == std::min(step, n))
            return -1;
    }

    if (nums[prev] == x)
        return prev;

    return -1;
}

int main()
{
    std::vector<int> nums = {30, 50, 10, 5, 33, 23, 7};
    int n = 23;
    return 0;
}
