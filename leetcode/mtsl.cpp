#include <iostream>
using namespace std;

class ListNode {
   public:
    int val;
    ListNode *next;
    ListNode() {
        val = 0;
        next = nullptr;
    }

    ListNode(int val) {
        this->val = val;
        this->next = nullptr;
    }

    ListNode(int val, ListNode *next) {
        this->val = val;
        this->next = next;
    }
};

void push(ListNode **node, int val) {
    if (*node == nullptr) {
        (*node) = new ListNode(val);
        return;
    }

    ListNode *ptr = *node;
    while (ptr->next != nullptr) {
        ptr = ptr->next;
    }
    ptr->next = new ListNode(val);
}

void traverseList(ListNode *list) {
    while (list != nullptr) {
        cout << list->val << " ";
        list = list->next;
    }
    cout << endl;
}

class Solution {
   public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *merged = nullptr;

        while (l1 != nullptr && l2 != nullptr) {
            int a = l1->val;
            int b = l2->val;

            if (a == b) {
                push(&merged, a);
                push(&merged, b);
                l1 = l1->next;
                l2 = l2->next;
            } else if (a > b) {
                push(&merged, b);
                l2 = l2->next;
            } else {
                push(&merged, a);
                l1 = l1->next;
            }
        }

        while (l1 != nullptr) {
            push(&merged, l1->val);
            l1 = l1->next;
        }

        while (l2 != nullptr) {
            push(&merged, l2->val);
            l2 = l2->next;
        }

        return merged;
    }
};

/**
 * 1 -> 5 -> 9 -> null
 * 1 -> 1 -> 4 -> null
 *
 *
 */

int main() {
    ListNode *l1 = nullptr;
    push(&l1, 1);
    push(&l1, 2);
    push(&l1, 4);

    ListNode *l2 = nullptr;
    push(&l2, 1);
    push(&l2, 3);
    push(&l2, 4);

    traverseList(l1);
    traverseList(l2);

    Solution *s = new Solution();
    ListNode *merged = s->mergeTwoLists(l1, l2);

    traverseList(merged);

    return 0;
}
