#include<string>
#include<vector>
using namespace std;


class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> memo(n + 2, vector<int>(n + 2, 0));
        for (int i = 1; i < n + 1; i++) {
            memo[i][i] = 1;
        }
        for (int j = 1; j < n; j++) {
            for (int i = 1; i + j < n + 1; i++) {
                int left = i;
                int right = i + j;
                memo[left][right] = std::max(memo[left][right], memo[left][right - 1]);
                memo[left][right] = std::max(memo[left][right], memo[left + 1][right]);
                if (s[left - 1] == s[right - 1]) {
                    memo[left][right] = std::max(memo[left][right], 2 + memo[left + 1][right - 1]);
                }
            }
        }

        return memo[1][n];
    }

};

//4:56 5:31, a bit slow, o(n^2)
/*
Runtime: 228 ms, faster than 7.75% of C++ online submissions for Longest Palindromic Subsequence.
Memory Usage: 67.1 MB, less than 25.37% of C++ online submissions for Longest Palindromic Subsequence.
*/
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> memo(s.size() + 1, vector<int>(s.size() + 1, -1));
        return dp(s, 0, s.size() - 1, memo);
    }

    int dp(string& s, int left, int right, vector<vector<int>>& memo) {
        if (left > right) {
            return 0;
        }
        if (left == right) {
            return 1;
        }
        if (memo[left][right] != -1) {
            return memo[left][right];
        }
        int result = s[left] == s[right] ? 2 + dp(s, left + 1, right - 1, memo) : 0;
        result = std::max(result, dp(s, left, right - 1, memo));
        result = std::max(result, dp(s, left + 1, right, memo));
        return memo[left][right] = result;
    }
};