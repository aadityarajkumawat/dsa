#include <iostream>

#include "header-files/ListNode.h"
using namespace std;

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

    ListNode* getNodeByIndex(ListNode* head, int index) {
        int i = 0;

        while (i < index - 1) {
            head = head->next;
            i++;
        }

        return head;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* start_end = head;
        ListNode* start = this->getNodeByIndex(head, left);

        while (head->next != start) {
            start_end = start_end->next;
        }

        ListNode* end_start = nullptr;
        ListNode* end = this->getNodeByIndex(head, right);
        end_start = end->next;
        end->next = nullptr;

        start = reverseList(start);

        start_end->next = start;

        ListNode* ptr = start;
        while (ptr->next != nullptr) {
            ptr = ptr->next;
        }

        end = ptr;
        end->next = end_start;

        return head;
    }
};

int main() {
    ListNode* a = new ListNode(1);

    a->push(2);
    a->push(3);
    a->push(4);
    a->push(5);

    // linked list
    // 1 -> 2 -> 3 -> 4 -> 5 -> null

    Solution s;

    ListNode* n = s.reverseBetween(a, 2, 4);

    while (n != nullptr) {
        cout << n->val << " ";
        n = n->next;
    }

    return 0;
}
