#include <bits/stdc++.h>

#include "header-files/TreeNode.h"

using namespace std;

class Solution {
   public:
    void inorderIterative(TreeNode* root) {
        stack<TreeNode*> s;

        TreeNode* current = root;

        while (true) {
            if (current != nullptr) {
                s.push(current);
                current = current->left;
            } else {
                if (s.empty()) break;
                current = s.top();
                cout << current->val << " ";
                current = current->right;
                s.pop();
            }
        }
    }

    void inorder(TreeNode* root, vector<int>& nums) {
        if (root == nullptr) return;
        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> nums;
        inorder(root, nums);
        return nums;
    }
};

int main() {
    /*
            9
           / \
          5   12
         / \
        1   6
    */
    TreeNode* root = new TreeNode(9);
    TreeNode* left = new TreeNode(5);
    TreeNode* right = new TreeNode(12);
    TreeNode* leftleft = new TreeNode(1);
    TreeNode* leftright = new TreeNode(6);

    root->left = left;
    root->right = right;

    left->left = leftleft;
    left->right = leftright;

    Solution s;
    s.inorderIterative(root);
    // vector<int> nums = s.inorderTraversal(root);

    // for (int i = 0; i < nums.size(); i++) {
    //     cout << nums[i] << " ";
    // }

    return 0;
}
