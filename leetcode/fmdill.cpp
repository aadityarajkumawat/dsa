#include <iostream>

#include "ListNode.h"
using namespace std;

class Solution {
   public:
    int getLength(ListNode* node) {
        int len = 0;
        while (node != nullptr) {
            node = node->next;
            len++;
        }

        return len;
    }

    ListNode* middleNode(ListNode* head) {
        ListNode* ptr = head;
        int len = this->getLength(head);

        int node_index = 0;

        if (len % 2 == 0) {
            node_index = (len / 2) + 1;
        } else {
            node_index = (len + 1) / 2;
        }

        for (int i = 0; i < node_index - 1; i++) {
            ptr = ptr->next;
        }

        return ptr;
    }
};

int main() {
    ListNode* a = new ListNode(1);
    ListNode* b = new ListNode(2);
    ListNode* d = new ListNode(4);
    ListNode* e = new ListNode(5);

    // a->next = b;
    // b->next = c;
    // c->next = d;
    // d->next = e;

    a->next = b;
    b->next = d;
    d->next = e;

    Solution s;

    ListNode* middleNode = s.middleNode(a);
    cout << middleNode->val << endl;

    return 0;
}
