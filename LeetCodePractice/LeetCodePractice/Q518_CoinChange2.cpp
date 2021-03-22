#include "LCHeader.h"
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> memo(amount + 1, vector<int>(coins.size(), -1));
        return dp(amount, coins, 0, memo);
    }

    int dp(int amount, vector<int>& coins, int idx, vector<vector<int>>& memo) {
        if (amount == 0) {
            return 1;
        }
        if (amount < 0) {
            return 0;
        }
        if (idx >= coins.size()) {
            return 0;
        }
        if (memo[amount][idx] != -1) {
            return memo[amount][idx];
        }
        int count = 0;
        count += dp(amount - coins[idx], coins, idx, memo);
        count += dp(amount, coins, idx + 1, memo);
        return memo[amount][idx] = count;
    }
};