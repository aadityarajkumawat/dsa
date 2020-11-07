#include <iostream>
#include <climits>
using namespace std;

int linearSearch(int arr[], int n, int s)
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

int main()
{
    int n, s;
    cin >> n >> s;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    if (linearSearch(arr, n, s) == -1)
    {
        cout << "Not Found" << endl;
    }
    else
    {
        cout << "Found" << endl;
    }

    return 0;
}