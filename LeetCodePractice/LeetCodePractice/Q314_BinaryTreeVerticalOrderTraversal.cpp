#include "LCHeader.h"
#include "TreeNode.cpp"
#include<queue>
//2:48 3:10

/**
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Tree Vertical Order Traversal.
Memory Usage: 12.1 MB, less than 86.39% of C++ online submissions for Binary Tree Vertical Order Traversal.
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if (root == nullptr) {
            return vector<vector<int>>();
        }
        int left = 0;
        int right = 0;
        rec(root, 0, left, right);
        vector<vector<int>> result(right - left + 1, vector<int>());
        int shift = abs(left);
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 0));
        while (q.size() > 0) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto& x = q.front();
                result[x.second + shift].push_back(x.first->val);
                if (x.first->left != nullptr) {
                    q.push(make_pair(x.first->left, x.second - 1));
                }
                if (x.first->right != nullptr) {
                    q.push(make_pair(x.first->right, x.second + 1));
                }
                q.pop();
            }
        }
        return result;
    }

    void rec(TreeNode* root, int pos, int& left, int& right) {
        if (root == nullptr) {
            return;
        }
        if (pos < left) {
            left = pos;
        }
        if (pos > right) {
            right = pos;
        }
        rec(root->left, pos - 1, left, right);
        rec(root->right, pos + 1, left, right);
        return;
    }
};