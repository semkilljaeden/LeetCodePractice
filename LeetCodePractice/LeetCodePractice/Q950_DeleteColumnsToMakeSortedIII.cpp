#include "LCHeader.h"
//7:49 read the answer 8:33
/*
Runtime: 16 ms, faster than 96.35% of C++ online submissions for Delete Columns to Make Sorted III.
Memory Usage: 10.2 MB, less than 93.43% of C++ online submissions for Delete Columns to Make Sorted III.
*/
class Solution {
public:
    int m;
    int n;
    int minDeletionSize(vector<string>& strs) {
        m = strs.size();
        n = strs[0].size();
        int max = 0;
        vector<int> memo(n + 1, -1);
        for (int i = 0; i < n; i++) {
            max = std::max(dp(strs, i, memo), max);
        }
        return n - max;
    }

    int dp(vector<string>& strs, int idx, vector<int>& memo) {
        int max = 1;
        if (idx == n - 1) {
            return 1;
        }
        if (memo[idx] != -1) {
            return memo[idx];
        }
        for (int i = idx + 1; i < n; i++) {
            bool cont = false;
            for (int j = 0; j < m; j++) {
                if (strs[j][i] < strs[j][idx]) {
                    cont = true;
                    break;
                }
            }
            if (cont) {
                continue;
            }
            max = std::max(dp(strs, i, memo) + 1, max);
        }
        return memo[idx] = max;
    }
};