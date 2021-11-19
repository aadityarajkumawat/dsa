#ifndef TreeNode_H
#define TreeNode_H

class TreeNode {
   public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode();
    TreeNode(int val);
    TreeNode(int val, TreeNode* left, TreeNode* right);
};

#endif
