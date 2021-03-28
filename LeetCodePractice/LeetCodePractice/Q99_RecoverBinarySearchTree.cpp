#include "LCHeader.h"
#include<queue>
#include "TreeNode.cpp"
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    deque<TreeNode*> q;
    TreeNode* left;
    TreeNode* right;
    void recoverTree(TreeNode* root) {
        dfs(root);
        if (q.size() == 2) {
            if (q[1]->val < q[0]->val) {
                if (left == nullptr) {
                    left = q[0];
                    right = q[1];
                }
                else {
                    right = q[1];
                }
            }
            q.pop_front();
        }
        swap(left->val, right->val);
    }

    void dfs(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        dfs(root->left);
        if (q.size() == 2) {
            if (q[1]->val < q[0]->val) {
                if (left == nullptr) {
                    left = q[0];
                    right = q[1];
                }
                else {
                    right = q[1];
                }
            }
            q.pop_front();
        }
        q.push_back(root);
        dfs(root->right);
    }
};