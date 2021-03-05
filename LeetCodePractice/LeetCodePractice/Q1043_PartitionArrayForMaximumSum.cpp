#include "LCHeader.h"
//5:53 6:22 DP AC O(N^2)

/*
Runtime: 72 ms, faster than 13.79% of C++ online submissions for Partition Array for Maximum Sum.
Memory Usage: 59.3 MB, less than 5.33% of C++ online submissions for Partition Array for Maximum Sum.
*/

class Solution {
public:
    int K;
    vector<vector<int>> Max;
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        K = k;
        int n = arr.size();
        Max = vector<vector<int>>(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            int max = arr[i];
            for (int j = i; j < n; j++) {
                max = std::max(max, arr[j]);
                Max[i][j] = max;
            }
        }
        vector<vector<int>> memo(n + 1, vector<int>(n + 1, -1));
        return dp(arr, 0, 0, memo);
    }

    int dp(vector<int>& arr, int idx, int pStart, vector<vector<int>>& memo) {
        if (memo[idx][pStart] != -1) {
            return memo[idx][pStart];
        }
        if (idx == arr.size()) {
            return memo[idx][pStart] = pStart < idx ? Max[pStart][idx - 1] * (idx - 1 - pStart + 1) : 0;
        }
        int max = 0;
        if (idx - pStart + 1 < K) {
            max = std::max(max, dp(arr, idx + 1, pStart, memo));
            max = std::max(max, Max[pStart][idx] * (idx - pStart + 1) + dp(arr, idx + 1, idx + 1, memo));
        }
        else if (idx - pStart + 1 == K) {
            max = Max[pStart][idx] * (idx - pStart + 1) + dp(arr, idx + 1, idx + 1, memo);
        }
        return memo[idx][pStart] = max;
    }
};