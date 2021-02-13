#include <iostream>

class Node {
public:
  int data;
  Node* left;
  Node* right;
};

Node* createNode(int data) {
  Node* node = new Node();
  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return node;
}

int main() {
  Node* p = createNode(2);
  Node* p1 = createNode(1);
  Node* p2 = createNode(4);

  p->left = p1;
  p->right = p2;
  return 0;
}