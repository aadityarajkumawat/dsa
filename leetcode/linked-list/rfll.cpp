#include <iostream>

#include "header-files/ListNode.h"
using namespace std;

class Solution {
   public:
    int delete_node_after(ListNode** node) {
        ListNode* ptr = *node;
        int val = ptr->val;
        ptr->next = ptr->next->next;
        return val;
    }

    ListNode* removeElements(ListNode* head, int val) {
        ListNode* ptr = head;

        while (ptr != nullptr) {
            if (ptr->next != nullptr && ptr->next->val == val)
                delete_node_after(&ptr);
            else
                ptr = ptr->next;
        }

        // in case if the first node has the value which is
        // to be deleted.
        if (head != nullptr && head->val == val) {
            head = head->next;
        }

        return head;
    }
};

int main() {
    ListNode* a = new ListNode(7);
    ListNode* b = new ListNode(7);
    ListNode* c = new ListNode(7);
    ListNode* d = new ListNode(7);

    a->next = b;
    b->next = c;
    c->next = d;

    Solution s;

    // 7 -> 7 -> 7 -> 7 -> null
    ListNode* h = s.removeElements(a, 7);

    while (h != nullptr) {
        cout << h->val << " ";
        h = h->next;
    }

    return 0;
}
