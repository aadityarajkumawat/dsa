#include "TreeNode.h"

#include <iostream>
using namespace std;

TreeNode::TreeNode() {
    val = 0;
    left = nullptr;
    right = nullptr;
}

TreeNode::TreeNode(int val) {
    this->val = val;
    this->left = nullptr;
    this->right = nullptr;
}

TreeNode::TreeNode(int val, TreeNode* left, TreeNode* right) {
    this->val = val;
    this->left = nullptr;
    this->right = nullptr;
}
