#include "LCHeader.h"
//7:55
/*
Runtime: 252 ms, faster than 71.87% of C++ online submissions for Longest Arithmetic Subsequence.
Memory Usage: 141.4 MB, less than 62.43% of C++ online submissions for Longest Arithmetic
*/
class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        vector<vector<int>> memo(A.size(), vector<int>(1002, 1));
        for (int i = 0; i < 1002; i++) {
            //memo[A.size() - 1][i] = 1;
        }
        int max = 0;
        for (int i = A.size() - 2; i >= 0; i--) {
            for (int j = i + 1; j < A.size(); j++) {
                int diff = A[j] - A[i] + 500;
                memo[i][diff] = std::max(memo[i][diff], memo[j][diff] + 1);
                max = std::max(max, memo[i][diff]);
            }
        }
        return max;
    }
};
//6:49 7:06 TLE

class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        vector<vector<int>> memo(A.size(), vector<int>(1002, -1));
        int max = 0;
        for (int i = 0; i < A.size(); i++) {
            max = std::max(max, dp(A, i, INT_MIN, memo)); //every INT_MIN goes through a while loop
        }
        return max;
    }

    int dp(vector<int>& A, int idx, int prev, vector<vector<int>>& memo) {
        int max = 1;
        if (idx == A.size() - 1) {
            return 1;
        }
        if (prev != INT_MIN && memo[idx][prev + 500] != -1) {
            return memo[idx][prev + 500];
        }
        for (int i = idx + 1; i < A.size(); i++) {
            if (A[i] - A[idx] == prev || prev == INT_MIN) {
                max = std::max(max, 1 + dp(A, i, A[i] - A[idx], memo));
            }
        }
        if (prev != INT_MIN) {
            memo[idx][prev + 500] = max;
        }
        return max;
    }
};