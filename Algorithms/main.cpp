#include <iostream>
#include "./doubly-linked-list/DoublyLinkedList.h"

using namespace std;

int main() {
    Node *head = new Node(8);
    auto *list = new DoublyLinkedList(head);

    // ================================
    Node *sec = new Node(7);
    Node *third = new Node(6);
    Node *fourth = new Node(5);

    // ================================
    list->push_back(sec);
    list->push_back(third);
    list->push_back(fourth);

    // ================================
    bool found = list->containsNodeWithValue(10);

    // ================================
    list->remove(third);
    list->printList();
    return 0;
}
