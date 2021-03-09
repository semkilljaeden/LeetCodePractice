#include "LCHeader.h"
#include "TreeNode.cpp"
//7:04 7:09
/*
Runtime: 4 ms, faster than 97.30% of C++ online submissions for Diameter of Binary Tree.
Memory Usage: 20.2 MB, less than 94.78% of C++ online submissions for Diameter of Binary Tree.
*/
class Solution {//7:05
public:
    int max = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        rec(root);
        return max;
    }

    int rec(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int left = rec(root->left);
        int right = rec(root->right);
        max = std::max(left + right, max);
        return 1 + std::max(left, right);
    }
};