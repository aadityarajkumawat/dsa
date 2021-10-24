#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int start, end;
        cin >> start >> end;

        int moves = 0;

        while (start < end) {
            moves++;
            start += 2;
        }

        if (start != end) {
            moves++;
        }

        cout << moves << endl;
    }

    return 0;
}
