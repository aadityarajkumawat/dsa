#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

void flatten(Node* root) {

    if (root->left != nullptr) {
        flatten(root->left);

        Node* temp = root->right;
        root->right = root->left;
        root->left = nullptr;

        Node* t = root->right;
    }
}

int main() {
    return 0;
}
