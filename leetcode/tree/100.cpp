#include <bits/stdc++.h>

#include "header-files/TreeNode.h"

using namespace std;

class Solution {
   public:
    bool compare(TreeNode* p, TreeNode* q) {
        if ((p == nullptr && q != nullptr) || (p != nullptr || q == nullptr))
            return false;

        if (p != nullptr && q != nullptr) {
            bool leftMatch = compare(p->left, q->left);
            bool rightMatches = compare(p->right, q->right);
            return leftMatch && rightMatches;
        }

        if (p == nullptr && q == nullptr) return true;
        return false;
    }

    // bool isSameTree(TreeNode* p, TreeNode* q) {}
};

int main() {
    TreeNode* r1 = new TreeNode(1);
    r1->left = new TreeNode(2);
    r1->right = new TreeNode(3);

    TreeNode* r2 = new TreeNode(1);
    r2->left = new TreeNode(2);
    r2->right = new TreeNode(3);

    Solution s;
    bool isSame = s.compare(r1, r2);

    if (isSame) {
        cout << "same" << endl;
    } else {
        cout << "not same" << endl;
    }

    return 0;
}
