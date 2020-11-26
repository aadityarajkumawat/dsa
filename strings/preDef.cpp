#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string s = "dsfsdfdgvsdfgv";

    transform(s.begin(), s.end(), s.begin(), ::toupper);
    //(start of str, end of str, from, operation)
    cout << s << endl;

    return 0;
}