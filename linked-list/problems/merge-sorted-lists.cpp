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

// Node* mergeTwoLists(Node* head1, Node* head2) {
//   Node* mergedList = NULL;

//   while (head1 != NULL && head2 != NULL) {
//     if (head1->data > )
//   }
// }

int main() {
  Node* head1 = new Node();
  head1->data = 1;
  head1->next = NULL;
  head1 = insertAtEnd(head1, 2);
  head1 = insertAtEnd(head1, 4);
  Node* head2 = new Node();
  head2->data = 1;
  head2->next = NULL;
  head2 = insertAtEnd(head2, 3);
  head2 = insertAtEnd(head2, 4);

  // mergeTwoLists(head1, head2);
  linkedListTraversal(head1);
  return 0;
}