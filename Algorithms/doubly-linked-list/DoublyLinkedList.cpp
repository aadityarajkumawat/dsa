//
// Created by edydee on 23/06/21.
//

#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;

Node::Node(int data) {
    this->data = data;
    this->prev = nullptr;
    this->next = nullptr;
}

DoublyLinkedList::DoublyLinkedList() {
    this->head = nullptr;
    this->tail = nullptr;
}

DoublyLinkedList::DoublyLinkedList(Node* node) {
    this->head = node;
    this->tail = node;
}

DoublyLinkedList* DoublyLinkedList::push_back(Node *newNode) {
    if(this->head == nullptr && this->tail == nullptr) {
        this->head = newNode;
        this->tail = newNode;
        return this;
    }
    this->tail->next = newNode;
    newNode->prev = this->tail;
    this->tail = newNode;
    return this;
}

bool DoublyLinkedList::containsNodeWithValue(int data) const {
    bool found = false;
    Node* ptr = this->head;
    while(ptr != nullptr) {
        if(ptr->data == data) {
            found = true;
            break;
        }
        ptr = ptr->next;
    }
    return found;
}

DoublyLinkedList* DoublyLinkedList::remove(Node* node) {
    if(node == this->head) {
        this->head = this->head->next;
    }
    else if(node == this->tail) {
        this->tail = this->tail->prev;
    }

    DoublyLinkedList::removeNodeBindings(node);
    return this;
}

void DoublyLinkedList::removeNodeBindings(Node* node) {
    if(node->next != nullptr) {
        node->next->prev = node->prev;
    }
    else if(node->prev != nullptr) {
        node->prev->next = node->next;
    }
    node->next = nullptr;
    node->prev = nullptr;
}

void DoublyLinkedList::printList() {
    cout << "null ⇆ ";
    while(this->head != nullptr) {
        cout << this->head->data << " ⇆ ";
        this->head = this->head->next;
    }
    cout << "null" << endl;
}
