#include <iostream>
using namespace std;

int first_occurance(int arr[], int n, int i, int key)
{
    if (i == n)
    {
        return -1;
    }

    if (arr[i] == key)
    {
        return i;
    }

    return first_occurance(arr, n, i + 1, key);
}

int last_occurance(int arr[], int n, int i, int key)
{
    if (i == n)
    {
        return -1;
    }
    int restArray = last_occurance(arr, n, i + 1, key);
    if (restArray != -1)
    {
        return restArray;
    }

    if (arr[i] == key)
    {
        return i;
    }

    return -1;
}

int main()
{
    int arr[] = {4, 2, 1, 2, 5, 2, 7};
    // cout << first_occurance(arr, 7, 0, 2);
    cout << last_occurance(arr, 7, 0, 2);
    return 0;
}