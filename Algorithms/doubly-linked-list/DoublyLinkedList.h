//
// Created by edydee on 23/06/21.
//

#ifndef ALGORITHMS_DOUBLYLINKEDLIST_H
#define ALGORITHMS_DOUBLYLINKEDLIST_H

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    explicit Node(int data);
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList();
    explicit DoublyLinkedList(Node* node);
    DoublyLinkedList* push_back(Node* newNode);
    bool containsNodeWithValue(int data) const;
    DoublyLinkedList* remove(Node* node);
    static void removeNodeBindings(Node* node);
    void printList();
};


#endif //ALGORITHMS_DOUBLYLINKEDLIST_H
