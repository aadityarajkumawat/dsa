#include <bits/stdc++.h>
using namespace std;

void init_code() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

int main() {
    init_code();

    int rounds = 0;
    cin >> rounds;

    vector<int> a;
    vector<int> b;

    for(int i = 0; i < rounds; i++) {
        int f, s;
        cin >> f >> s;
        a.push_back(f);
        b.push_back(s);
    }

    int winner = 0;
    int lead = 0;

    for(int i = 0; i < rounds; i++) {
        a[i] += a[i - 1];
        b[i] += b[i - 1];
    }

    for(int i = 0; i < rounds; i++) {
        int d = abs(a[i] - b[i]);
        if(d > lead) {
            lead = d;
            if(a[i] > b[i]) winner = 1;
            else winner = 2;
        }
    }

    cout << winner << " " << lead << endl;

    return 0;
}
