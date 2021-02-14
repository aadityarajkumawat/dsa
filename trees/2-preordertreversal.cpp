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

void preOrder(Node* root) {
  if (root != NULL) {
    std::cout << root->data << std::endl;
    preOrder(root->left);
    preOrder(root->right);
  }
}

int main() {
  Node* p = createNode(4);
  Node* p1 = createNode(1);
  Node* p2 = createNode(6);
  Node* p3 = createNode(5);
  Node* p4 = createNode(2);
  // Structure
  //      4
  //     / \
  //    1   6
  //   / \
  //  5   2

  p->left = p1;
  p->right = p2;

  p1->left = p3;
  p1->right = p4;

  preOrder(p);

  return 0;
}
