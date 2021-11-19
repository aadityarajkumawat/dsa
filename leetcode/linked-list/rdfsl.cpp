#include <iostream>
#include <unordered_map>
using namespace std;

class ListNode {
   public:
    int val;
    ListNode* next;
    ListNode() {
        val = 0;
        next = nullptr;
    }

    ListNode(int val) {
        this->val = val;
        this->next = nullptr;
    }

    ListNode(int val, ListNode* next) {
        this->val = val;
        this->next = next;
    }
};

void push(ListNode** node, int val) {
    if (*node == nullptr) {
        (*node) = new ListNode(val);
        return;
    }

    ListNode* ptr = *node;
    while (ptr->next != nullptr) {
        ptr = ptr->next;
    }
    ptr->next = new ListNode(val);
}

void traverseList(ListNode* list) {
    while (list != nullptr) {
        cout << list->val << " ";
        list = list->next;
    }
    cout << endl;
}

class Solution {
   public:
    ListNode* deleteDuplicates(ListNode* head) {
        unordered_map<int, int> hashMap;

        ListNode* ptr = head;
        ListNode* pptr = head;

        while (ptr != nullptr) {
            if (hashMap.find(ptr->val) != hashMap.end()) {
                ListNode* temp = ptr->next;
                pptr->next = ptr->next;
                ptr = temp;
            } else {
                if (ptr != nullptr) hashMap[ptr->val] = 1;
                pptr = ptr;
                ptr = ptr->next;
            }
        }

        return head;
    }
};

int main() {
    ListNode* head = nullptr;
    push(&head, 1);
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 3);

    Solution* s = new Solution();
    ListNode* head1 = s->deleteDuplicates(head);

    traverseList(head1);

    return 0;
}
