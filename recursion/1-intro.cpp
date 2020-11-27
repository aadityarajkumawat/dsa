// Sum_till(n) = n + Sum_till(n-1)

#include <iostream>
using namespace std;

int Sum_till(int n)
{
    if (n == 0)
    {
        return 0;
    }
    int prevSum = Sum_till(n - 1);
    return n + prevSum;
}

int main()
{
    int n;
    cin >> n;

    cout << Sum_till(n);

    return 0;
}