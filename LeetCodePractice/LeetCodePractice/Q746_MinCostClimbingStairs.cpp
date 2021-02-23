#include "LCHeader.h"
//8:54 8:57

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> memo(cost.size() + 1, -1);
        return std::min(dp(cost, 0, memo), dp(cost, 1, memo));
    }

    int dp(vector<int>& cost, int pos, vector<int>& memo) {
        if (pos >= cost.size()) {
            return 0;
        }
        if (memo[pos] != -1) {
            return memo[pos];
        }
        return memo[pos] = cost[pos] + std::min(dp(cost, pos + 2, memo), dp(cost, pos + 1, memo));
    }
};