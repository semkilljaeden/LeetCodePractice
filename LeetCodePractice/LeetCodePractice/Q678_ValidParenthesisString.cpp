#include "LCHeader.h"
//2:30 2:38 DP

class Solution {
public:
    bool checkValidString(string s) {
        vector<vector<int>> memo(s.size(), vector<int>(s.size() + 1, -1));
        return dp(s, 0, 0, memo);
    }

    bool dp(string& s, int idx, int left, vector<vector<int>>& memo) {
        if (idx == s.size()) {
            return left == 0;
        }
        if (memo[idx][left] != -1) {
            return memo[idx][left] == 1;
        }
        auto& c = s[idx];
        bool result = false;
        if (c == ')') {
            if (left <= 0) {
                result |= false;
            }
            else {
                result |= dp(s, idx + 1, left - 1, memo);
            }
        }
        if (c == '(') {
            result |= dp(s, idx + 1, left + 1, memo);
        }
        if (c == '*') {

            if (left > 0) {
                result |= dp(s, idx + 1, left - 1, memo);
            }
            result |= dp(s, idx + 1, left, memo);
            result |= dp(s, idx + 1, left + 1, memo);
        }
        return memo[idx][left] = result ? 1 : 0;
    }
};