#include <iostream>

#include "header-files/ListNode.h"
using namespace std;

/**
 *
 * 3 -> 8 -> 1 -> n
 *      a
 *
 */

class Solution {
   public:
    void deleteNode(ListNode* node) {
        ListNode* ptr = node;

        if (ptr == nullptr) {
            cout << "The list is empty" << endl;
            return;
        }

        if (ptr->next == nullptr) {
            cout << "This is the last node" << endl;
            cout << "it requires head to be deleted" << endl;
        } else {
            ptr->val = ptr->next->val;
            ptr->next = ptr->next->next;
        }
    }
};

int main() {
    ListNode* a = new ListNode(1);
    ListNode* b = new ListNode(2);
    ListNode* c = new ListNode(3);
    ListNode* d = new ListNode(4);

    a->next = b;
    b->next = c;
    c->next = d;

    a->traversal();

    Solution s;

    s.deleteNode(b);
    a->traversal();

    return 0;
}
