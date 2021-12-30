#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int totalSlippers;
        int leftSlippers;

        cin >> totalSlippers;
        cin >> leftSlippers;

        int rightSlippers = totalSlippers - leftSlippers;
        int maxPairPossible = min(leftSlippers, rightSlippers);

        int costPerPair;
        cin >> costPerPair;

        int totalPrice = costPerPair * maxPairPossible;
        cout << totalPrice << endl;
    }

    return 0;
}
