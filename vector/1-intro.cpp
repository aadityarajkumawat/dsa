#include <iostream>
#include <vector>
using namespace std;

int main()
{

    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    } // 1 2 3
    cout << endl;

    vector<int>::iterator it;
    for (it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    } // 1 2 3
    cout << endl;

    for (auto element : v)
    {
        cout << element << " ";
    } // 1 2 3
    cout << endl;

    v.pop_back(); // 1 2

    vector<int> v2(3, 50);
    // 50 50 50

    swap(v, v2);
    /**
        v -> 50 50 50
        v2 -> 1 2
    */

    for (auto element : v2)
    {
        cout << element << " ";
    } // 1 2 3
    return 0;
}