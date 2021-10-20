#include <iostream>

#include "header-files/ListNode.h"
using namespace std;

class Solution {
   public:
    ListNode* getNodeByIndex(ListNode* head, int index) {
        int i = 0;

        while (i < index - 1) {
            head = head->next;
            i++;
        }

        return head;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {}
};

int main() {
    ListNode* a = new ListNode(1);

    a->push(2);
    a->push(3);
    a->push(4);
    a->push(5);

    Solution s;

    ListNode* n = s.getNodeByIndex(a, 6);
    cout << n->val << endl;

    return 0;
}
