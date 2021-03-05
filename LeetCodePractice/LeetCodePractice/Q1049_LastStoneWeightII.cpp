#include "LCHeader.h"
//12:08 12:42, read the tips, a bit tricky
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Last Stone Weight II.
Memory Usage: 18.9 MB, less than 9.90% of C++ online submissions for Last Stone Weight II.
*/
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        vector<vector<int>> memo(stones.size(), vector<int>(3001, -1));
        return dp(stones, 0, 0, memo);
    }

    int dp(vector<int>& stones, int idx, int sum, vector<vector<int>>& memo) {
        if (idx == stones.size()) {
            return sum;
        }
        if (memo[idx][sum] != -1) {
            return memo[idx][sum];
        }
        int cur = stones[idx];

        return memo[idx][sum] = std::min(dp(stones, idx + 1, abs(sum - cur), memo), dp(stones, idx + 1, sum + cur, memo));
    }
};