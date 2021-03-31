#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

bool hasPathSum(Node* root, int targetSum) {
    if (root == nullptr) return false;
    if (targetSum - root->data == 0 && root->left == nullptr && root->right == nullptr) return true;
    return hasPathSum(root->left, targetSum - root->data) || hasPathSum(root->right, targetSum - root->data);
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

    Node* root = new Node(5);

    root->left = new Node(4);
    root->left->left = new Node(11);
    root->left->left->left = new Node(7);
    root->left->left->right = new Node(2);

    root->right = new Node(8);
    root->right->left = new Node(13);
    root->right->right = new Node(4);
    root->right->right->right = new Node(1);

    bool kay = hasPathSum(root, 22);

    if (kay) cout << "true" << endl;

    return 0;
}
