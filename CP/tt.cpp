#include <iostream>
using namespace std;

typedef pair<int, int> int_pair;

int main() {
    int_pair p = {4, 5};
    cout << "{ " << p.first << ", " << p.second << " }" << endl;
    return 0;
}
