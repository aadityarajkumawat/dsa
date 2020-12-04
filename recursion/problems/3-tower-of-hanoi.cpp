/**
 * We can only move one block at a time(n blocks)
 * there are three rods A, B, C
 * move all from A --> C in keeping em in same order
 * A --> source rod
 * B --> Helper rod
 * C --> Destination rod
**/
#include <iostream>
using namespace std;

void towerOfHanoi(int n, char src, char dest, char helper)
{
    if (n == 0)
    {
        return; // base case
    }
    towerOfHanoi(n - 1, src, helper, dest);
    cout << "Move from " << src << " to " << dest << endl;
    towerOfHanoi(n - 1, helper, dest, src);
}

int main()
{
    towerOfHanoi(3, 'A', 'C', 'B');
    return 0;
}