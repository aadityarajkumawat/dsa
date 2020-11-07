#include <iostream>
#include <climits>
using namespace std;

int binarySearch(int arr[], int n, int s)
{
    int start = 0;
    int end = n-1;

    for (;start <= end;)
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

int main()
{
    int n, s;
    cin >> n >> s;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    if (binarySearch(arr, n, s) == -1)
    {
        cout << "Not found" << endl;
    }
    else
    {
        cout << "Found" << endl;
    }

    return 0;
}