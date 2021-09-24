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

void traverseList(ListNode *list) {
    while (list != nullptr) {
        cout << list->val << " ";
        list = list->next;
    }
    cout << endl;
}

class Solution {
   public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *sumList = nullptr;

        ListNode *ptr = l1;
        ListNode *qtr = l2;

        int sum = 0;
        int carry = 0;

        while (l1 != nullptr && l2 != nullptr) {
            int a = l1->val;
            int b = l2->val;

            // cout << a << " " << b << endl;

            sum = a + b + carry;
            int digit = sum;
            // cout << "digit: " << sum << endl;

            if (sum > 9) {
                carry = 1;
                digit = sum - 10;
            }

            ListNode *newNode = new ListNode(digit);
            // cout << "Node Value: " << newNode->val << endl;
            if (sumList == nullptr) {
                sumList = newNode;
            } else {
                ListNode *ptr = sumList;
                while (ptr->next != nullptr) {
                    ptr = ptr->next;
                }
                ptr->next = newNode;
            }

            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1 != nullptr) {
            sum = l1->val + carry;
            int digit = sum;
            if (sum > 9) {
                carry = 1;
                digit = sum - 10;
            }
            ListNode *newNode = new ListNode(digit);
            ListNode *ptr = sumList;
            while (ptr->next != nullptr) {
                ptr = ptr->next;
            }
            ptr->next = newNode;

            l1 = l1->next;
        }

        while (l2 != nullptr) {
            sum = l2->val + carry;
            int digit = sum;
            if (sum > 9) {
                carry = 1;
                digit = sum - 10;
            }
            ListNode *newNode = new ListNode(digit);
            ListNode *ptr = sumList;
            while (ptr->next != nullptr) {
                ptr = ptr->next;
            }
            ptr->next = newNode;

            l2 = l2->next;
        }

        if (carry != 0) {
            ListNode *newNode = new ListNode(carry);
            ListNode *ptr = sumList;
            while (ptr->next != nullptr) {
                ptr = ptr->next;
            }
            ptr->next = newNode;
        }

        return sumList;
    }
};

void push(ListNode *node, int val) {
    ListNode *ptr = node;
    while (ptr->next != nullptr) {
        ptr = ptr->next;
    }
    ptr->next = new ListNode(val);
}

int main() {
    Solution *s = new Solution();

    ListNode *l1 = new ListNode(9);
    push(l1, 9);
    push(l1, 9);
    push(l1, 9);
    push(l1, 9);
    push(l1, 9);
    push(l1, 9);

    ListNode *l2 = new ListNode(9);
    push(l2, 9);
    push(l2, 9);
    push(l2, 9);

    ListNode *n = s->addTwoNumbers(l1, l2);

    // cout << n->val << endl;

    traverseList(n);

    return 0;
}
