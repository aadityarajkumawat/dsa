/*
    charcter arrays - need to know size beforehand
                    - require more size
                    - no terminating extra charcter
    strings - size not required
            - performing operations is easier
            - terminates with charcter '\0'
*/
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str = "sdscvsiudvisd";

    // Convert to uppercase
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
    }

    cout << str << endl;

    // Convert to lowercase
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
    }

    cout << str << endl;

    return 0;
}