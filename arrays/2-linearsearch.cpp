#include <iostream>
#include <climits>
using namespace std;

int linearSearchI(int arr[], int n, int s)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == s)
        {
            return i;
        }
    }

    return -1;
}

int linearSearchR(int arr[], int n, int s)
{
    if (arr[n-1] != s && n >= 0)
    {
        return linearSearchI(arr, n - 1, s);
    }
    else if (arr[n-1] == s && n >= 0)
    {
        return n;
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

    if (linearSearchR(arr, n, s) == -1)
    {
        cout << "Not Found" << endl;
    }
    else
    {
        cout << "Found" << endl;
    }

    return 0;
}