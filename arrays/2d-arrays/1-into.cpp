#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int n, m, s;
    cin >> n >> m >> s;
    int arr[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << "Matrix is: " << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == s)
            {
                cout << i << " " << j;
            }
        }
    }

    return 0;
}