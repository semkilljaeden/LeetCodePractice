#include "LCHeader.h"
#include "TreeNode.cpp"

//6:52 7:06
/*
Runtime: 4 ms, faster than 99.96% of C++ online submissions for Path Sum III.
Memory Usage: 19.7 MB, less than 30.17% of C++ online submissions for Path Sum III.
*/

class Solution {
public:
    int SUM;
    int count;
    int pathSum(TreeNode* root, int sum) {
        SUM = sum;
        count = 0;
        unordered_map<int, int> map;
        map[0] = 1;
        rec(root, map, 0);
        return count;
    }
    void rec(TreeNode* root, unordered_map<int, int>& sums, int sum) {
        if (root == nullptr) {
            return;
        }
        sum += root->val;
        if (sums.count(sum - SUM) > 0) {
            count += sums[sum - SUM];
        }
        sums[sum]++;
        rec(root->left, sums, sum);
        rec(root->right, sums, sum);
        sums[sum]--;
        if (sums[sum] <= 0) {
            sums.erase(sum);
        }
    }
};