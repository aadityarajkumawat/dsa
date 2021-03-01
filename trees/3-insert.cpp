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

int main()
{
    Node *root = insert(NULL, 8);
    root = insert(root, 5);
    root = insert(root, 9);
    root = insert(root, 7);
    root = insert(root, 3);

    print2D(root);
    return 0;
}
