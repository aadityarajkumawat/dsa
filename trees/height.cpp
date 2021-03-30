#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// time complexity -> O(n)
int calcHeight(Node* root)
{
    if (root == NULL)
        return 0;
    int lHeight = calcHeight(root->left);
    int rHeight = calcHeight(root->right);

    return max(lHeight, rHeight) + 1;
}

// time complexity -> O(n^2)
int calcDiameter(Node* root)
{
    if (root == NULL)
        return 0;
    int lHeight = calcHeight(root->left);
    int rHeight = calcHeight(root->right);
    int currDiameter = lHeight + rHeight + 1;

    int lDiameter = calcDiameter(root->left);
    int rDiameter = calcDiameter(root->right);

    return max(currDiameter, max(lDiameter, rDiameter));
}

// time complexity -> O(n)
int calcDia(Node* root, int* height)
{
    if (root == NULL)
    {
        *height = 0;
        return 0;
    }
    int lh = 0, rh = 0;
    int lDia = calcDia(root->left, &lh);
    int rDia = calcDia(root->right, &rh);

    int currDia = lh + rh + 1;
    *height = max(lh, rh) + 1;

    return max(currDia, max(lDia, rDia));
}

int main()
{
    /*
         1
       /   \
      2     3
     / \   / \
    4   5 6   7
  */

    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << calcDiameter(root) << endl;

    int height = 0;
    cout << calcDia(root, &height) << endl;

    return 0;
}
