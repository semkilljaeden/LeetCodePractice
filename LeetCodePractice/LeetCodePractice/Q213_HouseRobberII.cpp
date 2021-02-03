#include<vector>
using namespace std;
//9:42 10:00, 18mins, so so for an easy medium dp
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for House Robber II.
Memory Usage: 8.2 MB, less than 25.01% of C++ online submissions for House Robber II.
Next challenges:
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() < 2)
        {
            return nums[0];
        }
        vector<vector<int>> memo(nums.size(), vector<int>(4, -1));
        return max(rob(nums, 1, false, false, memo), nums[0] + rob(nums, 1, true, true, memo));
    }

    int rob(vector<int>& nums, int i, bool prev, bool first, vector<vector<int>>& memo) {
        if (i == nums.size() - 1)
        {
            if (first || prev)
            {
                return 0;
            }
            else
            {
                return nums[i];
            }
        }
        if (i > nums.size() - 2)
        {
            return 0;
        }
        auto& p = memo[i][(first ? 1 : 0) + (prev ? 2 : 0)];
        if (p != -1)
        {
            return p;
        }
        if (prev)
        {
            return p = rob(nums, i + 1, false, first, memo);
        }
        else
        {
            return p = max(rob(nums, i + 1, false, first, memo), nums[i] + rob(nums, i + 1, true, first, memo));
        }
    }
};