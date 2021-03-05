#include "LCHeader.h"
//7:54 DP
/*
Runtime: 156 ms, faster than 44.17% of C++ online submissions for Longest String Chain.
Memory Usage: 12.8 MB, less than 98.64% of C++ online submissions for Longest String Chain
*/
class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int max = 0;
        vector<int> memo(words.size(), -1);
        for (int i = 0; i < words.size(); i++) {
            max = std::max(max, dp(words, i, memo));
        }
        return max;
    }

    int dp(vector<string>& words, int idx, vector<int>& memo) {
        if (memo[idx] != -1) {
            return memo[idx];
        }
        string& cur = words[idx];
        int max = 1;
        for (int i = 0; i < words.size(); i++) {
            string& next = words[i];
            if (isSuccessor(cur, next)) {
                max = std::max(max, 1 + dp(words, i, memo));
            }
        }
        return memo[idx] = max;
    }

    bool isSuccessor(const string& a, const string& b, int i = 0, int j = 0, bool met = false) {
        if (a.size() + 1 != b.size()) {
            return false;
        }
        if (i == a.size()) {
            return true;
        }
        else if (j == b.size()) {
            return false;
        }
        if (a[i] == b[j]) {
            return isSuccessor(a, b, i + 1, j + 1, met);
        }
        else {
            if (met) {
                return false;
            }
            else {
                return isSuccessor(a, b, i, j + 1, true);
            }
        }
    }
};


//7:15	7:53 no DP AC WTF			

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int max = 0;
        for (int i = 0; i < words.size(); i++) {
            max = std::max(max, dp(words, i));
        }
        return max;
    }

    int dp(vector<string>& words, int idx) {
        string& cur = words[idx];
        int max = 1;
        for (int i = 0; i < words.size(); i++) {
            string& next = words[i];
            if (isSuccessor(cur, next)) {
                max = std::max(max, 1 + dp(words, i));
            }
        }
        return max;
    }

    bool isSuccessor(const string& a, const string& b, int i = 0, int j = 0, bool met = false) {
        if (a.size() + 1 != b.size()) {
            return false;
        }
        if (i == a.size()) {
            return true;
        }
        else if (j == b.size()) {
            return false;
        }
        if (a[i] == b[j]) {
            return isSuccessor(a, b, i + 1, j + 1, met);
        }
        else {
            if (met) {
                return false;
            }
            else {
                return isSuccessor(a, b, i, j + 1, true);
            }
        }
    }
};