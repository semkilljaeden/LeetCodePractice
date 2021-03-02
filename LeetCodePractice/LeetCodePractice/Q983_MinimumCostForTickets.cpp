#include "LCHeader.h"
//2:46 2:59 AC
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Minimum Cost For Tickets.
Memory Usage: 18.8 MB, less than 6.36% of C++ online submissions for Minimum Cost For Tickets.
*/
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<vector<int>> memo(days.size(), vector<int>(400, -1));
        return dp(0, days, costs, 0, memo);
    }

    int dp(int idx, vector<int>& days, vector<int>& costs, int bought, vector<vector<int>>& memo) {
        if (idx >= days.size()) {
            return 0;
        }
        if (memo[idx][bought] != -1) {
            return memo[idx][bought];
        }
        if (bought >= days[idx]) {
            return dp(idx + 1, days, costs, bought, memo);
        }
        int min = INT_MAX;
        min = std::min(min, costs[0] + dp(idx + 1, days, costs, days[idx], memo));
        min = std::min(min, costs[1] + dp(idx + 1, days, costs, days[idx] + 6, memo));
        min = std::min(min, costs[2] + dp(idx + 1, days, costs, days[idx] + 29, memo));
        return memo[idx][bought] = min;
    }
};