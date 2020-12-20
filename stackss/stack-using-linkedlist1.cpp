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

int isEmpty(Node* top) {
  if (top == NULL) {
    return 1;
  }
  return 0;
}

int isFull(Node* top) {
  Node* p = new Node();
  if (p == NULL) {
    return 1;
  }
  return 0;
}

Node* push(Node* top, int x) {
  if (isFull(top)) {
    cout << "Stack Overflow" << endl;
    return top;
  }
  else {
    Node* n = new Node();
    n->data = x;
    n->next = top;
    top = n;
    return top;
  }
}

int main() {
  Node* top = NULL;
  top = push(top, 70);
  top = push(top, 35);
  top = push(top, 17);
  linkedListTraversal(top);
  return 0;
}