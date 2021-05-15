#include <iostream>
using namespace std;

int main() {
    int arr[] = { 0, -9, 1, 3, -4, 5 };
    int max_n = -999;

    for (int i = 0; i < 6; i++) {
        max_n = max(max_n, arr[i]);
        cout << max_n << " ";
    }

    return 0;
}
