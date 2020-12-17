#include <iostream>
using namespace std;

class Node
{
public:
  int data;
  Node *next;
  Node *prev;
};

void traverseList(Node *head)
{
  while (head != NULL)
  {
    if (head->next == NULL)
      cout << head->data << endl;
    else
      cout << head->data << "->";
    head = head->next;
  }
}

void traverseBackNForth(Node *head)
{
  Node *artificialHead = head;
  Node *lastNode = head;

  while (artificialHead != NULL)
  {
    cout << artificialHead->data << " ";
    if (artificialHead->next == NULL)
    {
      lastNode = artificialHead;
    }
    artificialHead = artificialHead->next;
  }
  while (lastNode != NULL)
  {
    cout << lastNode->data << " ";
    lastNode = lastNode->prev;
  }
  cout << endl;
}

Node *insertAtFirst(Node *head, int data)
{
  Node *newNode = new Node();
  newNode->data = data;
  newNode->next = head;
  newNode->prev = NULL;
  head->prev = newNode;

  return newNode;
}

Node *insertAtLast(Node *head, int data) {
  
}

int main()
{
  Node *head = new Node();
  Node *second = new Node();

  head->data = 2;
  second->data = 3;

  head->next = second;
  head->prev = NULL;

  second->next = NULL;
  second->prev = head;

  head = insertAtFirst(head, 1);

  traverseList(head);
  traverseBackNForth(head);

  return 0;
}