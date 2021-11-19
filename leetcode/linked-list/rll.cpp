#include <iostream>

#include "header-files/ListNode.h"
using namespace std;

/**
 * N <- 1 <- 2 <- 3 <- 4 <- 5  N
 *                          p
 *                             c
 *                             n
 *
 * 5 -> 4 -> 3 -> 2 -> 1
 *
 * prev = null
 * curr = head
 * next = head
 *
 * while (curr is not null):
 *      next = curr.next
 *      curr.next = prev
 *      prev = curr
 *      curr = next
 */

class Solution {
   public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev, *next, *curr;

        curr = head;
        next = head;
        prev = nullptr;

        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
};

int main() {
    ListNode* a = nullptr;
    // ListNode* b = new ListNode(2);
    // ListNode* c = new ListNode(3);
    // ListNode* d = new ListNode(4);
    // ListNode* e = new ListNode(5);

    // a->next = b;
    // b->next = c;
    // c->next = d;
    // d->next = e;

    Solution s;
    ListNode* reversed = s.reverseList(a);

    while (reversed != nullptr) {
        cout << reversed->val << " ";
        reversed = reversed->next;
    }

    return 0;
}
