#include <iostream>
#define COUNT 10

class Node
{
  public:
    int data;
    Node *left;
    Node *right;
};

void print2DUtil(Node *root, int space)
{
  if (root == NULL)
    return;

  space += COUNT;

  print2DUtil(root->right, space);

  std::cout << std::endl;
  for (int i = COUNT; i < space; i++)
  {
    std::cout << " ";
  }
  std::cout << root->data << "\n";

  print2DUtil(root->left, space);
}

void print2D(Node *root)
{
  print2DUtil(root, 0);
}

Node *insert(Node *root, int data)
{
  Node *newNode = new Node();
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;

  if (root == NULL)
  {
    return newNode;
  }
  else
  {
    Node *current = root;
    Node *parent = NULL;

    while (true)
    {
      parent = current;

      if (data < parent->data)
      {
	current = current->left;

	if (current == NULL)
	{
	  parent->left = newNode;
	  return root;
	}
      }
      else
      {
	current = current->right;

	if (current == NULL)
	{
	  parent->right = newNode;
	  return root;
	}
      }
    }
  }
}

void preorder(Node *root) {
  if(root != NULL) {
    std::cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
  }
}

int main()
{
  Node *root = insert(NULL, 5);
  root = insert(root, 3);
  root = insert(root, 6);
  root = insert(root, 4);
  root = insert(root, 2);
  root = insert(root, 7);

  //preorder(root);
  print2D(root);
  return 0;
}


