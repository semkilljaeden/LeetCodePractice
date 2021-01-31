#include<vector>

using namespace std;
//3:14 to 3:32, DP, medium, ok





/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for House Robber.
Memory Usage: 8 MB, less than 55.22% of C++ online submissions for House Robber.
Next challenges:
*/


class Solution1 {
public:
    int rob(vector<int>& nums) {
        vector<vector<int>> memo(nums.size(), vector<int>{-1, -1});
        return rob(memo, nums, 0, false);
    }

    int rob(vector<vector<int>>& memo, vector<int>& nums, int i, bool robbed) {
        if (i >= nums.size())
        {
            return 0;
        }
        int& r = robbed ? memo[i][0] : memo[i][1];
        if (r > -1)
        {
            return r;
        }
        if (robbed)
        {
            return r = rob(memo, nums, i + 1, false);
        }
        else
        {
            return r = max(nums[i] + rob(memo, nums, i + 1, true), rob(memo, nums, i + 1, false));
        }
    }
};