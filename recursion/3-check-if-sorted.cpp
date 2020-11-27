#include <iostream>
using namespace std;

bool is_sorted(int arr[], int n)
{
    if(n == 1) {
        return true;
    }
    bool restArray = is_sorted(arr + 1, n - 1);
    return (arr[0] < arr[1] && restArray);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    cout << is_sorted(arr, 5);
    return 0;
}