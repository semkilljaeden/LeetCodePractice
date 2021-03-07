#include "LCHeader.h"
//3:06 3:15 , AC
class Solution {
public:
    double probabilityOfHeads(vector<double>& prob, int target) {
        vector<vector<double>> memo(prob.size(), vector<double>(target + 1, -1));
        return dp(prob, target, 0, memo);
    }

    double dp(vector<double>& prob, int target, int idx, vector<vector<double>>& memo) {
        if (idx == prob.size()) {
            return target == 0 ? 1.0 : 0.0;
        }
        if (memo[idx][target] != -1) {
            return memo[idx][target];
        }
        double& cur = prob[idx];
        if (target == 0) {
            return memo[idx][target] = (1.0 - cur) * dp(prob, target, idx + 1, memo);
        }

        return memo[idx][target] = cur * dp(prob, target - 1, idx + 1, memo) + (1.0 - cur) * dp(prob, target, idx + 1, memo);
    }
};