#include "LCHeader.h"
//1:15 1:24 hahahahah too easy
/*
Runtime: 36 ms, faster than 29.38% of C++ online submissions for Valid Palindrome III.
Memory Usage: 16.8 MB, less than 40.76% of C++ online submissions for Valid Palindrome III.
*/
class Solution {
public:
    bool isValidPalindrome(string s, int k) {
        vector<vector<int>> memo(s.size(), vector<int>(s.size(), -1));
        int max = dp(s, 0, s.size() - 1, memo);
        return s.size() - max <= k;
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
        int max = 0;
        if (s[left] == s[right]) {
            max = std::max(max, 2 + dp(s, left + 1, right - 1, memo));
        }
        max = std::max(max, dp(s, left + 1, right, memo));
        max = std::max(max, dp(s, left, right - 1, memo));
        return memo[left][right] = max;
    }
};