#include<vector>
using namespace std;

//9:49 10:27 very silly bug, very silly

class Solution {
public:
    long MIN = INT_MIN;
    int maxProfit(vector<int>& prices, int fee) {
        MIN -= INT_MIN;
        vector<vector<long>> memo(prices.size() + 1, vector<long>(2, MIN));
        return dp(prices, fee, 0, 0, memo);
    }

    long dp(vector<int>& prices, int& fee, int idx, int bought, vector<vector<long>>& memo) {
        if (memo[idx][bought] != MIN) {
            return memo[idx][bought];
        }
        if (idx == prices.size() - 1) {
            return bought ? prices[idx] : 0;
        }
        long max = INT_MIN;
        if (bought) {
            max = std::max(max, prices[idx] + dp(prices, fee, idx + 1, 0, memo));
            max = std::max(max, dp(prices, fee, idx + 1, 1, memo));
        }
        else {
            max = std::max(max, -prices[idx] - fee + dp(prices, fee, idx + 1, 1, memo));
            max = std::max(max, dp(prices, fee, idx + 1, 0, memo));
        }
        return memo[idx][bought] = max;
    }
};