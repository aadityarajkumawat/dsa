#include <iostream>

#include "header-files/ListNode.h"
using namespace std;

class Solution {
   public:
    int size(ListNode* node) {
        int len = 0;
        while (node != nullptr) {
            node = node->next;
            len++;
        }

        return len;
    }

    ListNode* get_intersection_node(ListNode* headA, ListNode* headB) {
        ListNode* head_a = headA;
        ListNode* head_b = headB;

        int size_a = this->size(head_a);
        int size_b = this->size(head_b);

        ListNode* smaller = head_a;
        ListNode* larger = head_b;

        if (size_a > size_b) {
            larger = head_a;
            smaller = head_b;
        }

        int diff_in_nodes = abs(size_a - size_b);

        for (int i = 0; i < diff_in_nodes; i++) {
            larger = larger->next;
        }

        while (smaller != nullptr && larger != nullptr) {
            if (smaller == larger) {
                return smaller;
            }

            smaller = smaller->next;
            larger = larger->next;
        }

        return nullptr;
    }
};

int main() {
    ListNode* a1 = new ListNode(4);
    ListNode* a2 = new ListNode(1);

    a1->next = a2;

    ListNode* b1 = new ListNode(5);
    ListNode* b2 = new ListNode(6);
    ListNode* b3 = new ListNode(1);

    b1->next = b2;
    b2->next = b3;

    ListNode* c1 = new ListNode(8);
    ListNode* c2 = new ListNode(4);
    ListNode* c3 = new ListNode(5);

    c1->next = c2;
    c2->next = c3;

    a2->next = c1;
    b3->next = c1;

    a1->traversal();

    cout << endl;

    b1->traversal();

    Solution s;
    ListNode* commom_node = s.get_intersection_node(a1, b1);

    cout << "\nCommon Node: " << commom_node->val << endl;

    return 0;
}
