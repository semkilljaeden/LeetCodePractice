#include "LCHeader.h"
//2:12 2:26 AC. cool
/*
Runtime: 8 ms, faster than 54.49% of C++ online submissions for Minimum Cost Tree From Leaf Values.
Memory Usage: 9.4 MB, less than 30.19% of C++ online submissions for Minimum Cost Tree From Leaf Values.
*/
class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        vector<vector<int>> max(arr.size(), vector<int>(arr.size(), 0));
        vector<vector<int>> memo(arr.size(), vector<int>(arr.size(), -1));
        for (int i = 0; i < arr.size(); i++) {
            max[i][i] = arr[i];
            int tmp = arr[i];
            for (int j = i; j < arr.size(); j++) {
                if (arr[j] > tmp) {
                    tmp = arr[j];
                }
                max[i][j] = tmp;
            }
        }
        return dp(arr, 0, arr.size() - 1, max, memo);
    }

    int dp(vector<int>& arr, int left, int right, vector<vector<int>>& max, vector<vector<int>>& memo) {
        if (left == right) {
            return 0;
        }
        if (memo[left][right] != -1) {
            return memo[left][right];
        }
        int min = INT_MAX;
        for (int i = left; i < right; i++) {
            min = std::min(min, max[left][i] * max[i + 1][right] + dp(arr, left, i, max, memo) + dp(arr, i + 1, right, max, memo));
        }
        return memo[left][right] = min;
    }
};