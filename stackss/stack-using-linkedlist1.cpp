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

int pop(Node** top) {
  if (isEmpty(*top)) {
    cout << "Stack is empty" << endl;
    return -1;
  }
  else {
    Node* n = *top;
    *top = (*top)->next;
    int x = n->data;
    free(n);

    return x;
  }
}

int peek(Node** top, int index) {
  Node* ptr = *top;
  if (isEmpty(*top)) {
    cout << "Stack is empty" << endl;
    return -1;
  }
  else {
    int x = 1;
    while (x < index) {
      ptr = ptr->next;
      x++;
    }
    return ptr->data;
  }
}

int main() {
  Node* top = NULL;
  top = push(top, 70);
  top = push(top, 35);
  top = push(top, 17);
  top = push(top, 8);
  /**
   *  |   17  |
   *  |   35  |
   *  |   70  |
   *  ________
  */
  linkedListTraversal(top);
  cout << "Popping an element " << pop(&top) << endl;
  linkedListTraversal(top);
  cout << "Peeking element at index 2: " << peek(&top, 2) << endl;
  linkedListTraversal(top);
  return 0;
}
