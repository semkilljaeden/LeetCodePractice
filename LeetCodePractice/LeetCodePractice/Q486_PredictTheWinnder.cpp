#include<vector>
using namespace std;
//10:24 11:18

class Solution {
public:
    vector<vector<int>> memo;
    bool PredictTheWinner(vector<int>& nums) {
        memo = vector<vector<int>>(nums.size(), vector<int>(nums.size(), -1));
        return dp(nums, 0, nums.size() - 1) >= 0;
    }

    int dp(vector<int>& nums, int i, int j) {
        if (i == j) {
            return nums[i];
        }
        if (i > j) {
            return 0;
        }
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        int a = nums[i] - dp(nums, i + 1, j);
        int b = nums[j] - dp(nums, i, j - 1);
        return memo[i][j] = std::max(a, b);
    }
};