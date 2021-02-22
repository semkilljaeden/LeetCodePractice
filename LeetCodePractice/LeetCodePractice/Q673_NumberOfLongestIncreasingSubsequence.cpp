#include<vector>
using namespace std;
//8:14 8:54, wasted too long
/*
Runtime: 108 ms, faster than 82.28% of C++ online submissions for Number of Longest Increasing Subsequence.
Memory Usage: 13.4 MB, less than 44.42% of C++ online submissions for Number of Longest Increasing Subsequence.
*/
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> memo(nums.size() + 1, -1);
        vector<int> memo2(nums.size() + 1, 0);
        int max = 0;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            dp(nums, i, memo, memo2);
            if (memo[i] == max) {
                count += memo2[i];
            }
            else if (memo[i] > max) {
                count = memo2[i];
                max = memo[i];
            }
        }
        return count;
    }

    int dp(vector<int>& nums, int idx, vector<int>& memo, vector<int>& memo2) {
        if (memo[idx] != -1) {
            return memo[idx];
        }
        int count = 1;
        int max = 1;
        for (int i = idx + 1; i < nums.size(); i++) {
            if (nums[idx] >= nums[i]) {
                continue;
            }
            int tmp = 1 + dp(nums, i, memo, memo2);
            if (tmp > max) {
                max = tmp;
                count = memo2[i];
            }
            else if (tmp == max) {
                count += memo2[i];
            }
        }
        memo[idx] = max;
        memo2[idx] = count;
        return max;
    }
};