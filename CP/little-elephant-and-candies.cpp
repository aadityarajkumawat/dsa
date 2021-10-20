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

    int test_cases;
    cin >> test_cases;

    for (int t = 0; t < test_cases; t++) {
        int elephants, candies;
        cin >> elephants >> candies;

        bool all_elephants_can_be_happy = true;

        for (int i = 0; i < elephants; i++) {
            int candies_wanted;
            cin >> candies_wanted;
            if (candies < candies_wanted) {
                all_elephants_can_be_happy = false;
                break;
            }
            candies = candies - candies_wanted;
        }

        if (all_elephants_can_be_happy)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}
