#include <iostream>

class Node
{
public:
  int data;
  Node *next;
};

int length(Node *head)
{
  int len = 0;
  while (head != NULL)
  {
    len++;
    head = head->next;
  }

  return len;
}

class Queue
{
public:
  int front = -1;
  int rear = -1;

  bool isEmpty(Node *head)
  {
    return (length(head) <= 0);
  }

  bool isFull(Node *head)
  {
    return length(head) >= 5;
  }

  void enQueue(int x, Node *head)
  {
    if (isFull(head))
    {
      std::cout << "Queue is full!" << std::endl;
      return;
    }

    Node *newNode = new Node();
    newNode->data = x;
    newNode->next = head;
    head = newNode;
  }

  int deQueue(Node *head)
  {
    if (isEmpty(head))
    {
      std::cout << "Queue is empty!" << std::endl;
      return -1;
    }
    int elementRemoved = head->data;
    head = head->next;

    return elementRemoved;
  }

  void displayQueue(Node *head)
  {
    if (isEmpty(head))
    {
      std::cout << "Queue is empty!" << std::endl;
      return;
    }

    while (head != NULL)
    {
      std::cout << head->data << std::endl;
      head = head->next;
    }
    std::cout << std::endl;
  }
};

Node *push_back(int data, Node *head)
{
  Node *newNode = new Node();
  newNode->data = data;
  newNode->next = NULL;

  if (head == NULL)
  {
    head = newNode;
    return head;
  }

  while (head->next != NULL)
  {
    head = head->next;
  }

  head->next = newNode;
  return head;
}

int main()
{
  Queue queue;
  Node *head = push_back(4, NULL);
  head = push_back(14, head);
  head = push_back(35, head);
  head = push_back(40, head);
  head = push_back(60, head);

  std::cout << head->data << std::endl;
  std::cout << head->next->data << std::endl;
  std::cout << head->next->next->data << std::endl;

  // queue.enQueue(3, head);
  // queue.displayQueue(head);

  return 0;
}
