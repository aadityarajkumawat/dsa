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
    [ { value: 4, weight: 3 }, { value: 1, weight: 5 } ]
*/

// a priority queue which prioritises smaller interger
class priority_queue_1 {
    vector<prioritised_entry *> pq;

  public:
    priority_queue_1() {}

    void add(prioritised_entry *entry) {
        if (pq.size() == 0) {
            pq.push_back(entry);
            return;
        }

        bool inserted = false;

        for (int i = 0; i < pq.size(); i++) {
            prioritised_entry *curr_elem = pq[i];

            if (entry->get_weight() < curr_elem->get_weight()) {
                inserted = true;
                for (int j = pq.size() - 1; j >= i; j--) {
                    if (j == pq.size() - 1) {
                        prioritised_entry* o = pq[j];
                        pq.push_back(o);
                    } else {
                        pq[j + 1] = pq[j];
                    }
                }

                pq[i] = entry;
                return;
            }
        }

        if (!inserted) {
            pq.push_back(entry);
        }
    }

    prioritised_entry* peek() {
        return pq[0];
    }

    void traverse_queue() {
        for (int i = 0; i < pq.size(); i++) {
            prioritised_entry* curr = pq[i];
            std::cout << "{" << curr->get_value() << ", " << curr->get_weight() << "}" << " ";
        }
        std::cout << std::endl;
    }
};

int main() { 
    priority_queue_1* pq = new priority_queue_1();
    
    prioritised_entry* pq_e2 = new prioritised_entry(1, 5);
    pq->add(pq_e2);

    prioritised_entry* pq_e1 = new prioritised_entry(4, 3);
    pq->add(pq_e1);

    prioritised_entry* pq_e3 = new prioritised_entry(7, 7);
    pq->add(pq_e3);


    pq->traverse_queue();

    return 0;
}
