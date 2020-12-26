#include <iostream>
using namespace std;

class Node {
public:
  int data;
  Node* next;
};

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

Node* push(Node* head, int data) {
  Node* newNode = new Node();
  if (head == NULL) {
    newNode->data = data;
    newNode->next = NULL;
    head = newNode;

    return head;
  }
  else {
    Node* h = head;
    while (h->next != NULL) {
      h = h->next;
    }
    newNode->data = data;
    newNode->next = NULL;
    h->next = newNode;

    return head;
  }
}

void enqueue(Node* f, Node* r, int val) {
  Node* n = new Node();
  if(n == NULL) {
    cout << "Queue is full" << endl;
  }
  else {
    n->data = val;
    n->next = NULL;
    if(f == NULL) {
      f = r = n;
    }
    else {
      r->next = n;
      r = n;
    }
  }
}


int main() {
  Node* f = NULL;
  f = push(f, 4);
  f = push(f, 3);
  f = push(f, 8);

  linkedListTraversal(f);
  return 0;
}