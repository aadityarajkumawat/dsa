#include <iostream>
using namespace std;

class Node
{
public:
  int data;
  Node *next;
};

// TRAVERSAL

void traverseCircularLinkedList(Node *head)
{
  Node *ptr = head;
  while (ptr->next != head)
  {
    cout << ptr->data << "->";
    ptr = ptr->next;
  }
  cout << ptr->data;
}

// INSERTION

Node *insertAtStart(Node *head, int data)
{
  Node *newNode = new Node();
  Node *ptr = head;
  newNode->data = data;
  newNode->next = head;
  while (ptr->next != head)
  {
    ptr = ptr->next;
  }
  ptr->next = newNode;
  return newNode;
}

int main()
{
  Node *head = new Node();
  Node *second = new Node();
  Node *third = new Node();
  Node *fourth = new Node();

  head->data = 11;
  head->next = second;

  second->data = 22;
  second->next = third;

  third->data = 33;
  third->next = fourth;

  fourth->data = 44;
  fourth->next = head;

  head = insertAtStart(head, 00);

  traverseCircularLinkedList(head);
  return 0;
}
