#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    int test_cases = 0;
    cin >> test_cases;

    for (int i = 0; i < test_cases; i++) {
        string s1, s2;

        cin >> s1;
        cin >> s2;

        if (s1 == s2) {
            cout << "true" << endl;
        } else {
            unordered_map<char, bool> um1;
            unordered_map<char, bool> um2;

            if (s1.length() > s2.length()) {
                string temp = s1;
                s1 = s2;
                s2 = temp;
            }

            for (long int i = 0; i < s1.length(); i++) {
                um1[s1[i]] = true;
            }

            for (int i = 0; i < s2.length(); i++) {
                um2[s2[i]] = true;
            }

            for (auto i : um1) {
                um2[i.first] = false;
            }

            int c = 0;
            for (auto i : um2) {
                if (um2[i.first] == true) {
                    c++;
                }
            }

            if (c == 1) {
                cout << "true" << endl;
            } else {
                cout << "false" << endl;
            }
        }
    }

    return 0;
}
