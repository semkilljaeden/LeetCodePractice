#include "LCHeader.h"

class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int n = rods.size();
        vector<vector<int>> memo(n, vector<int>(10002, INT_MIN));
        return dp(rods, 0, 5000, memo);
    }

    int dp(vector<int>& rods, int idx, int sum, vector<vector<int>>& memo) {
        if (idx == rods.size()) {
            if (sum == 5000) {
                return 0;
            }
            return INT_MIN;
        }
        if (memo[idx][sum] != INT_MIN) {
            return memo[idx][sum];
        }
        int max = INT_MIN;
        max = std::max(rods[idx] + dp(rods, idx + 1, sum + rods[idx], memo), max);
        max = std::max(dp(rods, idx + 1, sum - rods[idx], memo), max);
        max = std::max(dp(rods, idx + 1, sum, memo), max);
        return memo[idx][sum] = max;
    }
};

//6:47 MLE
class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int n = rods.size();
        vector<vector<vector<int>>> memo(n, vector<vector<int>>(5001, vector<int>(5001, -1)));
        return dp(rods, 0, 0, 0, memo);
    }

    int dp(vector<int>& rods, int idx, int leftSum, int rightSum, vector<vector<vector<int>>>& memo) {
        if (idx == rods.size()) {
            return leftSum == rightSum ? leftSum : 0;
        }
        if (memo[idx][leftSum][rightSum] != -1) {
            return memo[idx][leftSum][rightSum];
        }
        int max = 0;
        max = std::max(dp(rods, idx + 1, leftSum + rods[idx], rightSum, memo), max);
        max = std::max(dp(rods, idx + 1, leftSum, rightSum + rods[idx], memo), max);
        max = std::max(dp(rods, idx + 1, leftSum, rightSum, memo), max);
        return memo[idx][leftSum][rightSum] = max;
    }
};