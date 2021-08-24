#include <iostream>
using namespace std;

void init_code() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

int main() {
    init_code();
    int x;
    cin >> x;
    cout << x << endl;

    return 0;
}
