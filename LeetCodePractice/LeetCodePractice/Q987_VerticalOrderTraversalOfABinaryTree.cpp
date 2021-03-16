#include "LCHeader.h"
#include "TreeNode.cpp"
//7:08 7:44 silly bug


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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        auto p = bound(root, 0);
        int left = p.first;
        int right = p.second;
        int offset = 0 - left;
        vector<vector<pair<int, int>>> r(right + offset + 1, vector<pair<int, int>>());
        dfs(root, r, offset, 0, 0);
        vector<vector<int>> result;
        result.reserve(right + offset + 1);
        for (auto& x : r) {
            sort(x.begin(), x.end(), [](const pair<int, int>& left, const pair<int, int>& right) {
                if (left.first != right.first) {
                    return left.first < right.first;
                }
                else {
                    return left.second < right.second;
                }
            });
            vector<int> tmp;
            tmp.reserve(x.size());
            for (auto& y : x) {
                tmp.push_back(y.second);
            }
            result.push_back(tmp);
        }
        return result;
    }

    pair<int, int> bound(TreeNode* root, int col) {
        if (root == nullptr) {
            return make_pair(1000, -1000);
        }
        auto left = bound(root->left, col - 1);
        auto right = bound(root->right, col + 1);
        return make_pair(std::min(left.first, std::min(col, right.first)), std::max(left.second, std::max(col, right.second)));
    }

    void dfs(TreeNode* root, vector<vector<pair<int, int>>>& result, int& offset, int row, int col) {
        if (root == nullptr) {
            return;
        }
        dfs(root->left, result, offset, row + 1, col - 1);
        dfs(root->right, result, offset, row + 1, col + 1);
        int idx = offset + col;
        result[idx].push_back(make_pair(row, root->val));
        return;
    }
};