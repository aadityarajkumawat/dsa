#include <iostream>

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* buildTree(int preorder[], int start, Node* root) {
    Node* root = new Node(preorder[start]);
    root->left = buildTree(preorder, start + 1, root);
    root->right = buildTree(preorder, start + 2, root);

}

int main() {
    /**
               5
              / \
             4   8
            /   / \
          11  13   4
         / \        \
        7   2        1
    */

    int preOrderArray[] = { 5, 4, 11, 7, 0, 2, -1, 8, 13, 4, -1, 1 };
    Node* root = new Node(5);
    Node* root = buildTree(preOrderArray, 0, root);
    return 0;
}
