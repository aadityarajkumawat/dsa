#include <iostream>
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

int main() {
    BST* root = new BST(10);
    root->insert(8)->insert(7)->insert(6)->insert(11)->insert(9)->insert(16);

    // root->printBST();

    root->remove(8)->remove(16);

    root->printBST();

    return 0;
}
