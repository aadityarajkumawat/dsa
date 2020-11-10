#include <iostream>
#include <climits>
using namespace std;

// Pointers

int main()
{
    int a = 10;
    int *aptr = &a;

    cout << *aptr << endl;
    *aptr = 20;

    cout << a << endl;

    /* Pointer Arithmetic

        if we have an int variable
        and have its address stored in
        int *aptr = &a;

        then aptr++;
        will incerease the address value by 4,
        to move to next memory location of new integer


        Pointer and arrays

           2000     2004     2008     2012
        -------------------------------------
        |        |        |        |        |
        |   10   |   20   |   30   |   40   |  
        |        |        |        |        |
        -------------------------------------
            |
            |
            |
           arr
    */

    int arr[] = {10, 20, 30};
    cout << *arr << endl;

    int *ptr = arr;

    for (int i = 0; i < 3; i++)
    {
        cout << *ptr << endl;
        cout << *(arr + i) << endl;
        ptr++;
    }

    return 0;
}