#include <iostream>
#include <unordered_map>
#include <vector>
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
    bool hasCycle(ListNode* head) {
        bool does_it = false;

        unordered_map<ListNode*, bool> umap;

        ListNode* ptr = head;

        if (ptr == nullptr) {
            return false;
        }

        while (!does_it) {
            bool found_in_map = umap.find(ptr) != umap.end();

            if (found_in_map) {
                does_it = true;
                break;
            }
            umap[ptr] = true;
            ptr = ptr->next;

            if (ptr == nullptr) {
                does_it = false;
                break;
            }
        }

        return does_it;
    }
};

int main() {
    ListNode* head = new ListNode(3);
    ListNode* two = new ListNode(2);
    ListNode* third = new ListNode(0);
    ListNode* fourth = new ListNode(-4);

    head->next = two;
    two->next = third;
    third->next = fourth;

    fourth->next = two;

    Solution* s = new Solution();
    bool has = s->hasCycle(nullptr);

    if (has) {
        cout << "has a cycle" << endl;
    } else {
        cout << "does not have a cycle" << endl;
    }

    return 0;
}
