#include "LCHeader.h"

//10:30 12:12 hardest medium I have ever seen

class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int min = 0;
        vector<vector<int>> memo(values.size(), vector<int>(values.size(), -1));
        return dp(values, 0, values.size() - 1, memo);
    }

    int dp(vector<int>& values, int start, int end, vector<vector<int>>& memo) {
        if (memo[start][end] != -1) {
            return memo[start][end];
        }
        if (end - start < 2) {
            return memo[start][end] = 0;
        }
        if (end - start == 2) {
            return memo[start][end] = values[start] * values[start + 1] * values[end];
        }
        int min = INT_MAX;
        for (int i = start + 1; i < end; i++) {
            min = std::min(min, dp(values, start, i, memo) + dp(values, i, end, memo) + values[start] * values[i] * values[end]);
        }
        return memo[start][end] = min;
    }
};