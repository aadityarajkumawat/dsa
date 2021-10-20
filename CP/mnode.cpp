#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> int_pair;

/**
 * 1 0 2
 * 0 1
 * 0 1 2 3 2 1
 *
 * given arr B = [], length = N
 * arr A = [], length = N
 *
 * C = [ai mod bi] -> this should have maximum distinct integers
 *
 * eg:
 * B = [2, 1, 3]
 * A = [a1, a2, a3]
 * C = [a1 % 2, a2 % 1, a3 % 3]
 * - now we want a1, a2, a3 such that, ai mod bi, are mostly distinct.
 *
 * B = [1, 2, 3]
 * R = [0, 1, 2]
 *
 * a1 % 2 -> 0, 1
 * a2 % 1 -> 0
 * a3 % 3 -> 0, 1, 2
 *
 * a2 % 1 = 0 -> 0
 * a1 % 2 = 1 -> 1
 * a3 % 3 = 2 -> 2
 *
 * B = [b1, b2, b3,..., bn]
 * A = [a1, a2, a3,..., an]
 *
 * C = [a1 mod b1, a2 mod b2, a3 mod b3,..., an mod bn]
 *     [(0, 1,...,b1 - 1), (0, 1,...,b2 - 1),..., (0, 1,..., bn - 1)]
 *     (0), (0, 1), (0, 1, 2) and incase size of C is less than N,
 *     fill the rest by 0's
 */

void print_pair(int_pair p) {
    cout << "{ " << p.first << ", " << p.second << " }"
         << " ";
}

void print_vector(vector<int_pair> vec) {
    for (auto x : vec) {
        print_pair(x);
    }
    cout << endl;
}

bool found_in_vector(vector<int_pair> vec, int target) {
    bool found = false;
    for (auto x : vec) {
        if (x.first == target) {
            found = true;
        }
    }

    return found;
}

int get_max_val(vector<int_pair> vec) {
    int max_of = -1;

    for (auto x : vec) {
        if (x.first > max_of) {
            max_of = x.first;
        }
    }

    return max_of;
}

int main() {
    int t;
    cin >> t;
    while (t > 0) {
        int n;
        cin >> n;

        vector<int_pair> B;

        // taking input in array B
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            B.push_back({x, i});
        }

        // sorting B
        sort(B.begin(), B.end());
        // get max element from B
        int max_b = get_max_val(B);

        /**
         * 2 1 3
         * {1, 1} {2, 0} {3, 2}
         *
         * 1 2 3 3 2 1
         * {1, 0}, {1, 5}, {2, 1}, {2, 4}, {3, 2}, {3, 3}
         * {0, 0}, {0, 5}, {1, 1}, {0, 4}, {2, 2}, {0, 3}
         *
         */

        // filling values in C
        // fill element E: 0 <= E <= max_b - 1, and fill rest by 0's
        vector<int_pair> C;
        int r = 1;
        for (int i = 0; i < n; i++) {
            // if (i < max_b) {
            //     C.push_back({i, B[i].second});
            // } else {
            //     C.push_back({0, B[i].second});
            // }
            int idx = B[i].second;
            if (i == 0) {
                C.push_back({i, idx});
            } else if (C[i - 1].first != B[i].first) {
                C.push_back({r, idx});
                r++;
            } else {
                C.push_back({0, idx});
            }
        }

        print_vector(C);

        t--;
    }

    return 0;
}
