#include <iostream>
#include <string>

class Node {
  public:
    int data;
    Node* left;
    Node* right;
};

struct Trunk
{
    Trunk *prev;
    std::string str;
 
    Trunk(Trunk *prev, std::string str)
    {
        this->prev = prev;
        this->str = str;
    }
};
 
// Helper function to print branches of the binary tree
void showTrunks(Trunk *p)
{
    if (p == nullptr) {
        return;
    }
 
    showTrunks(p->prev);
    std::cout << p->str;
}
 
// Recursive function to print a binary tree.
// It uses the inorder traversal.
void printTree(Node* root, Trunk *prev, bool isLeft)
{
    if (root == nullptr) {
        return;
    }
 
    std::string prev_str = "    ";
    Trunk *trunk = new Trunk(prev, prev_str);
 
    printTree(root->left, trunk, true);
 
    if (!prev) {
        trunk->str = "———";
    }
    else if (isLeft)
    {
        trunk->str = ".———";
        prev_str = "    |";
    }
    else {
        trunk->str = "`———";
        prev->str = prev_str;
    }
 
    showTrunks(trunk);
    std::cout << root->data << std::endl;
 
    if (prev) {
        prev->str = prev_str;
    }
    trunk->str = "    |";
 
    printTree(root->right, trunk, false);
}

// Insertion
Node *insert(Node *root, int data) {
  Node *newNode = new Node();
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
  
  if(root == NULL) {
    return newNode;
  }
  else {
    Node *current = root;
    Node *parent = NULL;

    while(true) {
      parent = current;

      if(parent->data > data) {
	current = current->left;

	if(current == NULL) {
	  parent->left = newNode;
	  return root;
	}
      }

      else {
	current = current->right;

	if(current == NULL) {
	  parent->right = newNode;
	  return root;
	}
      }
    }
  }
}

int main() {
  Node *root = insert(NULL, 27);
  root = insert(root, 14);
  root = insert(root, 10);
  root = insert(root, 19);
  root = insert(root, 35);
  root = insert(root, 31);
  root = insert(root, 42);

  printTree(root, nullptr, false);

  return 0;
}

