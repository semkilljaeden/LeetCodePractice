#include "LCHeader.h"
//4:00 top down
/*
Runtime: 12 ms, faster than 83.46% of C++ online submissions for Minimum Falling Path Sum.
Memory Usage: 9.5 MB, less than 79.02% of C++ online submissions for Minimum Falling Path Sum.
*/
class Solution {
public:
    int M;
    int N;
    int minFallingPathSum(vector<vector<int>>& matrix) {
        M = matrix.size();
        N = matrix[0].size();
        vector<int> m1(N + 2, 0);
        vector<int> m2(N + 2, 0);
        auto p = &m1;
        auto c = &m2;
        for (int i = M - 1; i >= 0; i--) {
            auto& prev = *p;
            auto& cur = *c;
            std::fill(cur.begin(), cur.end(), 0);
            prev[0] = prev.back() = INT_MAX;
            for (int j = 1; j <= N; j++) {
                cur[j] = matrix[i][j - 1] + std::min(prev[j - 1], std::min(prev[j], prev[j + 1]));
            }
            swap(p, c);
        }
        int min = INT_MAX;
        for (int i = 1; i <= N; i++) {
            min = std::min(min, (*p)[i]);
        }
        return min;
    }
};

//3:50 DP
/*
* Runtime: 8 ms, faster than 98.20% of C++ online submissions for Minimum Falling Path Sum.
Memory Usage: 10 MB, less than 22.26% of C++ online submissions for Minimum Falling Path Sum.


*/

class Solution {
public:
    int M;
    int N;
    int minFallingPathSum(vector<vector<int>>& matrix) {
        M = matrix.size();
        N = matrix[0].size();
        vector<vector<int>> memo(M + 1, vector<int>(N + 1, -1));
        int min = INT_MAX;
        for (int i = 0; i < N; i++) {
            min = std::min(min, dp(matrix, 0, i, memo));
        }
        return min;
    }

    int dp(vector<vector<int>>& matrix, int m, int n, vector<vector<int>>& memo) {
        if (n < 0 || n >= N) {
            return INT_MAX;
        }
        if (m == M) {
            return 0;
        }
        if (memo[m][n] != -1) {
            return memo[m][n];
        }
        return memo[m][n] = matrix[m][n] + std::min(dp(matrix, m + 1, n, memo), std::min(dp(matrix, m + 1, n - 1, memo), dp(matrix, m + 1, n + 1, memo)));
    }
};
//3:43 3:48 TLE
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {

    }
};