#include <cmath>
#include <iostream>

#include "header-files/ListNode.h"
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

    int getDecimalValue(ListNode* head) {
        ListNode* ptr = head;
        int expo = getLength(head);

        int decimal_num = 0;

        while (ptr != nullptr) {
            decimal_num += (int)pow(2.0, expo - 1) * ptr->val;
            expo--;
            ptr = ptr->next;
        }

        return decimal_num;
    }
};

int main() {
    ListNode* a = new ListNode(1);

    a->push(0);
    a->push(1);

    Solution s;

    cout << s.getDecimalValue(a) << endl;

    return 0;
}
