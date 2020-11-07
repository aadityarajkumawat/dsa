#include <iostream>
#include <climits>
using namespace std;

int binarySearchI(int arr[], int n, int s)
{
    int start = 0;
    int end = n - 1;

    for (; start <= end;)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == s)
        {
            return mid;
        }
        else if (arr[mid] > s)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return -1;
}

int binarySearchR(int arr[], int start, int end, int s)
{
    if (start <= end)
    {
        int mid = (start + end) / 2;

        if (arr[mid] == s)
        {
            return mid;
        }
        if (arr[mid] > s)
        {
            return binarySearchR(arr, start, mid - 1, s);
        }

        return binarySearchR(arr, mid + 1, end, s);
    }
    return -1;
}

int main()
{
    int n, s;
    cin >> n >> s;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    if (binarySearchR(arr, 0, n - 1, s) == -1)
    {
        cout << "Not found" << endl;
    }
    else
    {
        cout << "Found" << endl;
    }

    return 0;
}