#include "LCHeader.h"
#include "TreeNode.cpp"
#include<queue>
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if (root == nullptr || root->left == nullptr && root->right == nullptr) {
            return true;
        }
        queue<TreeNode*> q;
        q.push(root);
        int level = 1;
        bool gap = false;
        bool bottom = false;
        while (q.size() > 0) {
            int size = q.size();
            vector<TreeNode*> row;
            for (int i = 0; i < size; i++) {
                auto x = q.front();
                q.pop();
                auto& l = x->left;
                auto& r = x->right;
                row.push_back(l);
                row.push_back(r);
                if (l != nullptr) {
                    q.push(l);
                }
                if (r != nullptr) {
                    q.push(r);
                }
            }
            if (bottom && q.size() > 0) {
                return false;
            }
            for (auto& x : row) {
                if (gap && x != nullptr) {
                    return false;
                }
                if (!gap && x == nullptr) {
                    gap = true;
                    bottom = true;
                }
            }
        }
        return true;

    }
};