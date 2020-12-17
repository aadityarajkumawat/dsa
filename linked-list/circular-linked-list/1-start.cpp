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
  cout << ptr->data << endl;
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

Node *insertAtIndex(Node *head, int index, int data)
{
  Node *ptr = head;
  Node *newNode = new Node();
  newNode->data = data;
  int i = 1;
  while (i != index)
  {
    ptr = ptr->next;
    i++;
  }
  newNode->next = ptr->next;
  ptr->next = newNode;
  return head;
}

Node *insertAtLast(Node *head, int data)
{
  Node *ptr = head;
  Node *newNode = new Node();
  newNode->data = data;
  while (ptr->next != head)
  {
    ptr = ptr->next;
  }
  newNode->next = head;
  ptr->next = newNode;
  return head;
}

// DELETION

Node *deleteFromStart(Node *head)
{
  Node *secondLastNode = head;
  while (secondLastNode->next != head)
  {
    secondLastNode = secondLastNode->next;
  }
  Node *deleteThisNode = secondLastNode->next;
  secondLastNode->next = deleteThisNode->next;
  free(deleteThisNode);

  return secondLastNode->next;
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
  head = insertAtIndex(head, 2, 16);
  head = insertAtLast(head, 55);
  traverseCircularLinkedList(head);
  head = deleteFromStart(head);
  traverseCircularLinkedList(head);
  return 0;
}
