#include <iostream>

class Node
{
  public:
    int data;
    Node *left;
    Node *right;
};

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

int main()
{
  Node *root = insert(NULL, 5);
  root = insert(root, 3);
  root = insert(root, 6);

  if (search(root, 3))
  {
    std::cout << "Three found!!";
  }
  return 0;
}

