#include <iostream>
using namespace std;

class Node
{
public:
  int data;
  Node *next;
};

void linkedListTraversal(Node *ptr)
{
  while (ptr != NULL)
  {
    if (ptr->next == NULL)
    {
      cout << ptr->data << " ";
    }
    else
    {
      cout << ptr->data << "->";
    }
    ptr = ptr->next;
  }
  cout << endl;
}

Node *insertAtStart(Node *head, int data)
{
  Node *newHead = new Node();
  newHead->next = head;
  newHead->data = data;
  return newHead;
}

/**
 * Deletion of a node from
 * starting of a linked list
*/
Node *deleteFromStart(Node *head)
{
  Node *ptr = head;
  head = head->next;
  free(ptr);
  return head;
}

/**
 * Deletion of a node
 * in between of a linked list
*/
Node *deleteNodeByIndex(Node *head, int index)
{
  Node *ptr = head;
  int i = 0;
  while (i != index - 1)
  {
    ptr = ptr->next;
    i++;
  }
  Node *q = ptr->next;
  ptr->next = q->next;
  free(q);

  return head;
}

/**
 * Delete the last node
 * of linked list
*/
Node *deleteLastNode(Node *head)
{
  Node *ptr = head;
  Node *qtr = head;
  while (head->next != NULL)
  {
    ptr = head;
    head = head->next;
  }
  ptr->next = NULL;
  free(head);

  return qtr;
}

/**
 * Delete Node by key
*/
Node *deleteNodeByKey(Node *head, int key)
{
  Node *ptr = head;
  Node *qtr = head;

  while (head->data != key)
  {
    qtr = head;
    head = head->next;
  }

  qtr->next = head->next;
  free(head);

  return ptr;
}

int main()
{
  Node *head;
  head = new Node();
  head->data = 12;
  head->next = NULL;

  // Populating Linked list
  head = insertAtStart(head, 10);
  head = insertAtStart(head, 9);
  head = insertAtStart(head, 7);
  head = insertAtStart(head, 5);
  head = insertAtStart(head, 4);
  head = insertAtStart(head, 1);

  // Deletion of nodes
  head = deleteFromStart(head);
  head = deleteNodeByIndex(head, 2);
  head = deleteLastNode(head);
  head = deleteNodeByKey(head, 5);

  linkedListTraversal(head);
  return 0;
}