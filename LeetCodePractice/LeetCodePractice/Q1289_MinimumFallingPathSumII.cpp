#include "LCHeader.h"
//6:39 6:48 ?? O(n^3)

class Solution {
public:
    int m;
    int n;
    int minFallingPathSum(vector<vector<int>>& arr) {
        int min = INT_MAX;
        m = arr.size();
        n = arr[0].size();
        vector<vector<int>> memo(m, vector<int>(n, -1));
        for (int i = 0; i < n; i++) {
            min = std::min(min, dp(arr, 0, i, memo));
        }
        return min;
    }

    int dp(vector<vector<int>>& arr, int i, int j, vector<vector<int>>& memo) {
        if (j < 0 || j >= n) {
            return 10000000;
        }
        if (i >= m) {
            return 0;
        }
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        int min = 10000000;
        for (int x = 0; x < n; x++) {
            if (x == j) {
                continue;
            }
            min = std::min(min, arr[i][j] + dp(arr, i + 1, x, memo));
        }
        return memo[i][j] = min;
    }
};