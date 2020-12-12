#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

void linkedListTraversal(struct Node* ptr) {
    while (ptr != NULL) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}

int main() {
    Node* head;
    Node* second;
    Node* third;

    head = new Node();
    second = new Node();
    third = new Node();

    head->data = 7;
    head->next = second;

    second->data = 14;
    second->next = third;

    third->data = 21;
    third->next = NULL;

    linkedListTraversal(head);

    return 0;
}