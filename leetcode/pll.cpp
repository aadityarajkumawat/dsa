#include <iostream>

#include "header-files/ListNode.h"
using namespace std;

class Solution {
   public:
    int getValue(ListNode* head, int index) {
        int i = 0;
        int value = 0;

        while (i != index) {
            value = head->val;
            head = head->next;
            i++;
        }

        return value;
    }

    bool isPalindrome(ListNode* head) {
        bool is_palindrome = true;

        return is_palindrome;
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

    Solution s;

    // sol
    bool pal = s.isPalindrome(a);

    if (pal) {
        cout << "input is really a palindrome" << endl;
    } else {
        cout << "that's not a palindrome" << endl;
    }

    return 0;
}
