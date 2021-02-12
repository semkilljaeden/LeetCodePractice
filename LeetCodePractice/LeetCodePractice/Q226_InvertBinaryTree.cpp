#include<vector>
#include "TreeNode.cpp"
using namespace std;
//12:13 to 12:15
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Invert Binary Tree.
Memory Usage: 9.2 MB, less than 75.17% of C++ online submissions for Invert Binary Tree.
*/
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        auto tmp = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(tmp);
        return root;
    }
};