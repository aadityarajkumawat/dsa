#include <iostream>
using namespace std;

class Node {
   public:
    int val;
    Node *next;

    Node() {
        val = 0;
        next = nullptr;
    }

    Node(int val) {
        this->val = val;
        this->next = nullptr;
    }

    Node(int val, Node *next) {
        this->val = val;
        this->next = next;
    }

    void setVal(int val) { this->val = val; }
    int getVal() { return val; }

    void setNext(Node *next) { this->next = next; }
    Node *getNext() { return next; }
};

void push(Node *node, int val) {
    if (node == nullptr) {
        node = new Node(val);
        return;
    }

    Node *ptr = node;
    while (ptr->next != nullptr) {
        ptr = ptr->next;
    }
    ptr->next = new Node(val);
}

void push(Node **node, int val) {
    if (*node == nullptr) {
        *node = new Node(val);
        return;
    }

    Node *ptr = *node;
    while (ptr->next != nullptr) {
        ptr = ptr->next;
    }
    ptr->next = new Node(val);
}

void some_func(Node *node) {
    cout << node->val << endl;
    Node *ptr = node;

    cout << "node: " << node << endl;
    cout << "address of node: " << &node << endl;

    cout << "ptr: " << ptr << endl;
    cout << "address of ptr: " << &ptr << endl;
    cout << ptr->val << endl;

    cout << "moving it forwards..." << endl;
    ptr = ptr->next;

    cout << ptr->val << endl;

    // ptr = ptr->next;
}

int main() {
    Node *head = nullptr;

    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);
    push(&head, 6);

    // cout << head->val << endl;
    some_func(head);

    cout << head->val << endl;

    return 0;
}
