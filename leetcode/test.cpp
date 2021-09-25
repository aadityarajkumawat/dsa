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

int main() {
    Node *head = nullptr;
    cout << "address of head: " << head << ", address of pointer to address of head: " << &head << endl;

    push(&head, 4);

    cout << head->val << endl;

    return 0;
}
