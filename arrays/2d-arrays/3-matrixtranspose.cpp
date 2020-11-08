#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int A[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}};

    for (int i = 0; i < 3; i++)
    {
        for (int j = i; j < 3; j++)
        {
            if (i != j)
            {
                int temp = A[i][j];
                A[i][j] = A[j][i];
                A[j][i] = temp;
            }
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << A[i][j];
        }

        cout << endl;
    }
    return 0;
}