#include "LCHeader.h"
//7:28 7:45 O(MN)

class Solution {
public:
    string minimizeError(vector<string>& prices, int target) {
        vector<unordered_map<int, double>> memo(prices.size() + 1, unordered_map<int, double>());
        double r = dp(prices, target, 0, memo);
        if (r > 10000000) {
            return "-1";
        }
        string result = to_string(r);
        return result.substr(0, result.size() - 3);
    }

    double dp(vector<string>& prices, int target, int idx, vector<unordered_map<int, double>>& memo) {
        if (idx == prices.size()) {
            return target == 0 ? 0 : INT_MAX;
        }
        if (memo[idx].count(target) > 0) {
            return memo[idx][target];
        }
        double tmp = stod(prices[idx]);
        int floor = (int)tmp;
        if ((double)floor == tmp) {
            return dp(prices, target - floor, idx + 1, memo);
        }
        int ceil = (int)tmp + 1;
        double min = 0;
        min = std::min((double)ceil - tmp + dp(prices, target - ceil, idx + 1, memo),
            tmp - (double)floor + dp(prices, target - floor, idx + 1, memo));
        return memo[idx][target] = min;
    }
};