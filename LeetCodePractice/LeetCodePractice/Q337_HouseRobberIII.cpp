#include<vector>
#include<unordered_map>
#include "TreeNode.cpp"
using namespace std;

//7:08 7:23 DP with memo, ok for medium
/*
Runtime: 12 ms, faster than 91.14% of C++ online submissions for House Robber III.
Memory Usage: 28.2 MB, less than 25.36% of C++ online submissions for House Robber III.
*/
class Solution {
public:
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, vector<int>> memo;
        return rob(root, false, memo);
    }

    int rob(TreeNode* root, bool robbed, unordered_map<TreeNode*, vector<int>>& memo) {
        if (root == nullptr) {
            return 0;
        }
        if (robbed && memo.count(root) > 0 && memo[root][0] != -1) {
            return memo[root][0];
        }
        if (!robbed && memo.count(root) > 0 && memo[root][1] != -1) {
            return memo[root][1];
        }
        int max = 0;
        if (!robbed) {
            max = std::max(max, root->val + rob(root->left, true, memo) + rob(root->right, true, memo));

        }
        if (memo.count(root) == 0) {
            memo[root] = vector<int>(2, -1);
        }
        max = std::max(max, rob(root->left, false, memo) + rob(root->right, false, memo));
        robbed ? memo[root][0] = max : memo[root][1] = max;
        return max;
    }
};