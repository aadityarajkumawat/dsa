#include <iostream>
#include <vector>
using namespace std;

class MyHashMap {
    vector<int> vec;

   public:
    MyHashMap() {
        for (int i = 0; i < 1000001; i++) {
            vec.push_back(-1);
        }
    }

    void put(int key, int value) { vec[key] = value; }

    int get(int key) { return vec[key]; }

    void remove(int key) { vec[key] = -1; }
};

int main() {
    MyHashMap* hm = new MyHashMap();

    hm->put(1, 3);
    hm->put(2, 8);
    hm->put(3, 2);

    // update value
    hm->put(1, 9);

    cout << hm->get(1) << endl;
    cout << hm->get(3) << endl;

    return 0;
}
