#include "LCHeader.h"
//mis read the question, 12:13 12:45 failed too fucking hard

class Solution {
public:
    int base = 1000000007;
    vector<vector<int>> memo;
    int countPalindromicSubsequences(string S) {
        memo = vector<vector<int>>(S.size() + 1, vector<int>(S.size() + 1, -1));
        return dp(S, 0, S.size() - 1);
    }

    int dp(string& S, int i, int j) {
        if (i > j) {
            return 0;
        }
        if (i == j) {
            return 1;
        }
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        if (S[i] != S[j]) {
            int left = dp(S, i + 1, j);
            int right = dp(S, i, j - 1);
            memo[i][j] = (left + right) % base - dp(S, i + 1, j - 1);
            memo[i][j] %= base;
            if (memo[i][j] < 0) {
                memo[i][j] += base;
            }
            return memo[i][j] %= base;
        }
        int x = i + 1;
        int y = j - 1;
        int result = 0;
        while (S[x] != S[i] && x < j) {
            x++;
        }
        while (S[y] != S[i] && y > i) {
            y--;
        }
        if (x > y) {
            result = 2 + (2 * dp(S, i + 1, j - 1)) % base;
        }
        else if (x == y) {
            result = 1 + (2 * dp(S, i + 1, j - 1)) % base;
        }
        else {
            result = (2 * dp(S, i + 1, j - 1)) % base;
            result -= dp(S, x + 1, y - 1);
            result %= base;
        }
        memo[i][j] = result;
        if (memo[i][j] < 0) {
            memo[i][j] += base;
        }
        return memo[i][j] %= base;
    }
};