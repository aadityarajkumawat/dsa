#include <iostream>
using namespace std;

class Node {
public:
  int data;
  Node* next;
};

// Print Linked List
void linkedListTraversal(Node* ptr) {
  while (ptr != NULL) {
    if (ptr->next == NULL) {
      cout << ptr->data << " ";
    }
    else {
      cout << ptr->data << "->";
    }
    ptr = ptr->next;
  }
  cout << endl;
}

// Case 1 -> Insert at Beginning
Node* insertAtStart(Node* head, int data) {
  Node* newHead = new Node();
  newHead->next = head;
  newHead->data = data;
  return newHead;
}

// Case 2 -> Insert in between
// data is inserted after the index specified
Node* insertAt(Node* head, int index, int data) {
  if (head->next == NULL) {
    if (index == 1) {
      Node* newNode = new Node();
      head->next = newNode;
      newNode->data = data;
      newNode->next = NULL;
      return head;
    }
    else {
      cout << "Index out of range";
      return head;
    }
  }

  Node* ptr = new Node();
  Node* p = head;

  int idx = 1;

  while (idx != index) {
    p = p->next;
    ++idx;
  }
  ptr->data = data;
  ptr->next = p->next;
  p->next = ptr;
  return head;
}

// Case 3 -> Insert at end
Node* insertAtEnd(Node* head, int data) {
  Node* p = new Node();
  Node* q = head;
  while (q->next != NULL) {
    q = q->next;
  }
  p->data = data;
  p->next = NULL;
  q->next = p;

  return head;
}

// Case 4 -> Insert after a Node
void insertAfterNode();

int main() {
  Node* head;
  head = new Node();
  head->data = 12;
  head->next = NULL;

  // Populating Linked list
  head = insertAtStart(head, 10);
  head = insertAtStart(head, 9);
  head = insertAtStart(head, 4);
  head = insertAtStart(head, 1);

  int data, index;

  cout << "Enter data:";
  cin >> data;
  // cout << "Enter index:";
  // cin >> index;

  // insertAt(head, index, data);
  insertAtEnd(head, data);
  linkedListTraversal(head);

  return 0;
}
