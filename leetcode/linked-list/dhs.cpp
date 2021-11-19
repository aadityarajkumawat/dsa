#include <iostream>
#include <vector>
using namespace std;

class MyHashSet {
    vector<bool> vec;

   public:
    MyHashSet() {
        for (int i = 0; i < 1000001; i++) {
            vec.push_back(false);
        }
    }

    void add(int key) { vec[key] = true; }

    void remove(int key) { vec[key] = false; }

    bool contains(int key) { return vec[key]; }
};

int main() {
    MyHashSet* hs = new MyHashSet();

    hs->add(0);
    hs->add(6);
    hs->add(9);
    hs->add(2);

    cout << hs->contains(2) << endl;
    cout << hs->contains(9) << endl;

    return 0;
}
