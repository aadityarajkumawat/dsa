#include "ListNode.h"

#include <iostream>
using namespace std;

ListNode::ListNode() {
    val = 0;
    next = nullptr;
}

ListNode::ListNode(int val) {
    this->val = val;
    this->next = nullptr;
}

ListNode::ListNode(int val, ListNode* next) {
    this->val = val;
    this->next = next;
}

void ListNode::traversal() {
    ListNode* ptr = this;
    while (ptr != nullptr) {
        cout << ptr->val << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

void ListNode::push(int x) {
    ListNode* ptr = this;

    while (ptr->next != nullptr) {
        ptr = ptr->next;
    }

    ListNode* new_node = new ListNode(x);
    ptr->next = new_node;
}
