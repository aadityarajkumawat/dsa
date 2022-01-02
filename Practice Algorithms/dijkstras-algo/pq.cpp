#include <bits/stdc++.h>
using namespace std;

struct minWeight {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }
};

void traverse_pq(priority_queue<pair<int, int>, vector<pair<int, int>>, minWeight> pq) {
    while (!pq.empty()) {
        cout << pq.top().first << " ";
        pq.pop();
    }
}

int main() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, minWeight> pqq;

    pair<int, int> p1(3, 5);
    pair<int, int> p2(6, 9);
    pair<int, int> p3(7, 1);

    pqq.push(p1);
    pqq.push(p2);
    pqq.push(p3);

    traverse_pq(pqq);

    cout << pqq.top().first << "";

    return 0;
}
