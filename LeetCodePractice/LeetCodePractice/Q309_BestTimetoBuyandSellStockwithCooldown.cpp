#include<vector>
using namespace std;

//8:15 8:35, silly bug
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Best Time to Buy and Sell Stock with Cooldown.
Memory Usage: 11.4 MB, less than 61.83% of C++ online submissions for Best Time to Buy and Sell Stock with Cooldown.
*/
class Solution {
public:
    using pr = pair<int, int>;
    int maxProfit(vector<int>& prices) {
        vector<pr> memo(prices.size() + 1, make_pair(-1, -1));
        int size = prices.size();
        memo[0].first = 0;
        memo[0].second = 0;
        int x = rev(prices, 1, false, memo);
        return x;
    }

    int rev(vector<int>& prices, int i, bool isHolding, vector<pr>& memo) {
        if (i >= prices.size()) {
            return isHolding ? prices.back() : 0;
        }
        if (isHolding) {
            if (memo[i].second != -1) {
                return memo[i].second;
            }
            return memo[i].second = max(prices[i - 1] + rev(prices, i + 2, false, memo), rev(prices, i + 1, true, memo));
        }
        if (memo[i].first != -1) {
            return memo[i].first;
        }
        return memo[i].first = max(-prices[i - 1] + rev(prices, i + 1, true, memo), rev(prices, i + 1, false, memo));
    }
};