#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

Node* LCA(Node* root, int n1, int n2) {
    if (root == nullptr) return nullptr;

    if (root->data == n1 || root->data == n2) return root;

    Node* left = LCA(root->left, n1, n2);
    Node* right = LCA(root->right, n1, n2);

    if (left != nullptr && right != nullptr) return root;
    if (left == nullptr && right == nullptr) return nullptr;
    if (left != nullptr) return LCA(root->left, n1, n2);
    return LCA(root->right, n1, n2);
}

int findDist(Node* root, int k, int dist) {
    if (root == nullptr) return -1;
    if (root->data == k) return dist;

    int left = findDist(root->left, k, dist + 1);
    if (left != -1) return left;
    return findDist(root->right, k, dist + 1);
}

int distanceBetweenNodes(Node* root, int n1, int n2) {
    Node* lca = LCA(root, n1, n2);

    int d1 = findDist(lca, n1, 0);
    int d2 = findDist(lca, n2, 0);

    return d1 + d2;
}

int main() {
    /*
           1
          / \
         2   3
        /     \
       4       7
     */

    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);

    root->right->right = new Node(7);

    cout << distanceBetweenNodes(root, 4, 5);

    return 0;
}
