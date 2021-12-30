#include <bits/stdc++.h>
using namespace std;

class prioritised_entry {
    int value;
    int weight;

  public:
    prioritised_entry(int value, int weight) {
        this->value = value;
        this->weight = weight;
    }

    int get_value() { return this->value; }

    int get_weight() { return this->weight; }
};

/*
    [ { value: 4, priority: 3 }, { value: 1, priority: 5 } ]
*/

// a priority queue which prioritises smaller interger
class priority_queue {
    vector<prioritised_entry *> pq;

  public:
    priority_queue() {}

    void add(prioritised_entry *entry) {
        for (int i = 0; i < pq.size(); i++) {
            prioritised_entry *curr_elem = pq[i];
            // if (curr_elem->get_weight() <)>
        }
    }
};

int main() { return 0; }
