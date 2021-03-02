#include "LCHeader.h"
#include "TreeNode.cpp"
//11:52 12:14 AC~!!!!!!!!!!!!!!
/*
Runtime: 20 ms, faster than 32.60% of C++ online submissions for Binary Tree Cameras.
Memory Usage: 25.5 MB, less than 20.30% of C++ online submissions for Binary Tree Cameras.
*/
class Solution {
public:
    int minCameraCover(TreeNode* root) {
        unordered_map<TreeNode*, vector<int>> memo;
        return dp(root, 0, memo);
    }

    int dp(TreeNode* root, int watched, unordered_map<TreeNode*, vector<int>>& memo) {
        if (root == nullptr) {
            return watched == 1 ? 1001 : 0;
        }
        if (memo.count(root) > 0 && memo[root][watched] != -1) {
            return memo[root][watched];
        }
        if (watched == 1) {
            return 1 + dp(root->left, 2, memo) + dp(root->right, 2, memo);
        }
        int min = 1001;
        if (watched == 0) {
            min = std::min(min, dp(root->left, 1, memo) + dp(root->right, 0, memo));
            min = std::min(min, dp(root->left, 0, memo) + dp(root->right, 1, memo));
        }
        if (watched == 2) {
            min = std::min(min, dp(root->left, 0, memo) + dp(root->right, 0, memo));
        }
        min = std::min(min, 1 + dp(root->left, 2, memo) + dp(root->right, 2, memo));
        if (memo.count(root) == 0) {
            memo[root] = vector<int>{ -1, -1, -1 };
        }
        return memo[root][watched] = min;
    }
};