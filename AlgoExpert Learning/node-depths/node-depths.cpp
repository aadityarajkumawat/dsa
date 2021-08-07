#include <iostream>
#include <stack>
using namespace std;

class BST {
public:
    int value = 0;
    BST* left = nullptr;
    BST* right = nullptr;

    BST(int value) {
        this->value = value;
        this->left = nullptr;
        this->right = nullptr;
    }

    BST* insert(int value) {
        BST* currentNode = this;

        while (true) {
            if (value < currentNode->value) {
                if (currentNode->left != nullptr) {
                    currentNode = currentNode->left;
                }
                else {
                    currentNode->left = new BST(value);
                    break;
                }
            }
            else {
                if (currentNode->right != nullptr) {
                    currentNode = currentNode->right;
                }
                else {
                    currentNode->right = new BST(value);
                    break;
                }
            }
        }

        return this;
    }

    bool contains(int value) {
        BST* currentNode = this;

        while (currentNode != nullptr) {
            if (value < currentNode->value) {
                currentNode = currentNode->left;
            }
            else if (value > currentNode->value) {
                currentNode = currentNode->right;
            }
            else {
                return true;
            }
        }

        return false;
    }

    BST* remove(int value, BST* parentNode = nullptr) {
        BST* currentNode = this;

        while (currentNode != nullptr) {
            if (value < currentNode->value) {
                parentNode = currentNode;
                currentNode = currentNode->left;
            }
            else if (value > currentNode->value) {
                parentNode = currentNode;
                currentNode = currentNode->right;
            }
            else {
                if (currentNode->left != nullptr && currentNode->right != nullptr) {
                    currentNode->value = currentNode->right->getMinValue();
                    currentNode->right->remove(currentNode->value, currentNode);
                }
                else if (parentNode == nullptr) {
                    if (currentNode->left != nullptr) {
                        currentNode->value = currentNode->left->value;
                        currentNode->left = currentNode->left->left;
                        currentNode->right = currentNode->left->right;
                    }
                    else if (currentNode->right != nullptr) {
                        currentNode->value = currentNode->right->value;
                        currentNode->left = currentNode->right->left;
                        currentNode->right = currentNode->right->right;
                    }
                    else {
                        currentNode = nullptr;
                    }
                }
                else if (parentNode->left == currentNode) {
                    if (currentNode->left != nullptr) {
                        parentNode->left = currentNode->left;
                    }
                    else {
                        parentNode->left = currentNode->right;
                    }
                }
                else if (parentNode->right == currentNode) {
                    if (currentNode->right != nullptr) {
                        parentNode->right = currentNode->right;
                    }
                    else {
                        parentNode->right = currentNode->left;
                    }
                }

                break;
            }
        }

        return this;
    }

    int getMinValue() {
        BST* currentNode = this;

        while (currentNode->left != nullptr) {
            currentNode = currentNode->left;
        }

        return currentNode->value;
    }

    void printBST() {
        BST* currentNode = this;

        if (currentNode->left) {
            currentNode->left->printBST();
        }
        cout << currentNode->value << endl;
        if (currentNode->right) {
            currentNode->right->printBST();
        }
    }
};

class NodeInfo {
public:
    BST* node;
    int depth;

    NodeInfo(BST* tree, int depth) {
        this->node = tree;
        this->depth = depth;
    }
};

int findSumOfNodeDepthsV0(BST* tree) {
    int sumOfDepths = 0;
    stack<NodeInfo*> stack;

    NodeInfo* rootInfo = new NodeInfo(tree, 0);

    stack.push(rootInfo);

    while (!stack.empty()) {
        NodeInfo* nodeInfo = stack.top();
        stack.pop();

        BST* node = nodeInfo->node;
        int depth = nodeInfo->depth;

        if (node == nullptr) {
            continue;
        }

        sumOfDepths += depth;

        NodeInfo* leftNode = new NodeInfo(node->left, depth + 1);
        NodeInfo* rightNode = new NodeInfo(node->right, depth + 1);

        stack.push(leftNode);
        stack.push(rightNode);
    }

    return sumOfDepths;
}

int findSumOfNodeDepthsV1(BST* tree, int depth = 0) {
    if (tree == nullptr) return 0;
    return depth + findSumOfNodeDepthsV1(tree->left, depth + 1) + findSumOfNodeDepthsV1(tree->right, depth + 1);
}

int main() {
    BST* root = new BST(10);
    root->insert(8)->insert(7)->insert(6)->insert(11)->insert(9)->insert(16);

    int nodeDepths0 = findSumOfNodeDepthsV0(root);
    int nodeDepths1 = findSumOfNodeDepthsV1(root);

    cout << nodeDepths0 << endl;
    cout << nodeDepths1 << endl;

    return 0;
}
