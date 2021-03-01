#include "LCHeader.h"
//5:56 6:54. damn. 1 hour for a medium, wtf
/*
Runtime: 288 ms, faster than 44.79% of C++ online submissions for Length of Longest Fibonacci Subsequence.
Memory Usage: 64 MB, less than 10.61% of C++ online submissions for Length of Longest Fibonacci Subsequence.
*/
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {

        vector<vector<int>> memo(arr.size() + 1, vector<int>(arr.size() + 1, -1));
        int n = arr.size();
        unordered_map<int, int> map;
        for (int i = 0; i < n; i++) {
            map[arr[i]] = i;
        }
        int max = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                max = std::max(1 + dp(arr, j, i, map, memo), max);
            }
        }
        return max < 3 ? 0 : max;
    }

    int dp(vector<int>& arr, int pos, int prev, unordered_map<int, int>& map, vector<vector<int>>& memo) {
        if (memo[pos][prev] != -1) {
            return memo[pos][prev];
        }
        int sum = arr[pos] + arr[prev];
        memo[pos][prev] = 1;
        if (map.count(sum) > 0) {
            memo[pos][prev] += dp(arr, map[sum], pos, map, memo);
        }
        return memo[pos][prev];
    }
};



//TLE
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {

        vector<vector<int>> memo(arr.size() + 1, vector<int>(arr.size() + 1, -1));

        dp(arr, 1, 0, memo);
        int max = 0;
        for (int i = 1; i < memo.size(); i++) {
            if (memo[i][0] > max) {
                max = memo[i][0];
            }
        }
        return max;
    }

    int dp(vector<int>& arr, int pos, int prev, vector<vector<int>>& memo) {
        if (memo[pos][prev] != -1) {
            return memo[pos][prev];
        }
        int sum = (prev == 0 ? -1 : arr[pos - 1] + arr[prev - 1]);
        int max = 1;
        for (int i = pos + 1; i < arr.size(); i++) {
            if (arr[i - 1] == sum || prev == 0) {
                max = std::max(max, 1 + dp(arr, i, pos, memo));
            }
            memo[i][0] = std::max(max, dp(arr, i, 0, memo));
        }
        return memo[pos][prev] = max;
    }
};