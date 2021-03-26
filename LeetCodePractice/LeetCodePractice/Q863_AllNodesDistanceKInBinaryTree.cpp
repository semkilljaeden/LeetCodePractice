#include "LCHeader.h"
#include "TreeNode.cpp"
//10:50 11:12
/*
Runtime: 4 ms, faster than 90.03% of C++ online submissions for All Nodes Distance K in Binary Tree.
Memory Usage: 12.4 MB, less than 83.49% of C++ online submissions for All Nodes Distance K in Binary Tree.
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> result;
    TreeNode* target;
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        this->target = target;
        rec(root, K);
        return result;
    }

    int rec(TreeNode* root, int& K) {
        if (root == nullptr) {
            return -1;
        }
        if (root == target) {
            rec2(root, K);
            return 0;
        }
        int left = rec(root->left, K);
        int right = rec(root->right, K);
        if (left > -1) {
            int r = left + 1;
            if (r == K) {
                result.push_back(root->val);
            }
            else if (r < K) {
                rec2(root->right, K - r - 1);
            }
            return r;
        }
        else if (right > -1) {
            int r = right + 1;
            if (r == K) {
                result.push_back(root->val);
            }
            else if (r < K) {
                rec2(root->left, K - r - 1);
            }
            return r;
        }
        else {
            return -1;
        }
    }

    void rec2(TreeNode* root, int K) {
        if (root == nullptr) {
            return;
        }
        if (K == 0) {
            result.push_back(root->val);
            return;
        }
        rec2(root->left, K - 1);
        rec2(root->right, K - 1);
    }
};