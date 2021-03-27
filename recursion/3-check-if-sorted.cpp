#include <iostream>

bool sorted(int arr[], int n)
{
    if (n == 1)
    {
        return true;
    }

    bool restArray = sorted(arr + 1, n - 1);
    return arr[0] < arr[1] && restArray;
}

int main()
{
    int arr[] = {1, 2, 9, 4, 5, 6};

    std::cout << sorted(arr, 6) << std::endl;
    return 0;
}