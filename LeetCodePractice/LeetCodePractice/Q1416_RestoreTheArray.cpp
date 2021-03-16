#include "LCHeader.h"
//7:07 fuck this shit, it is actually quite easy

class Solution {
public:
    int K;
    const int base = 1e9 + 7;
    int numberOfArrays(string s, int k) {
        K = k;
        vector<int> memo(s.size(), -1);
        return dp(s, 0, memo);
    }

    int dp(string& s, int idx, vector<int>& memo) {
        if (s[idx] == '0') {
            return 0;
        }
        if (idx == s.size()) {
            return 1;
        }
        if (memo[idx] != -1) {
            return memo[idx];
        }
        long sum = 0;
        long prev = 0;
        for (int i = idx + 1; i < s.size() + 1; i++) {
            long num = prev * 10 + s[i - 1] - '0';
            if (num > K) {
                break;
            }
            prev = num;
            sum += dp(s, i, memo);
            sum %= base;
        }
        return memo[idx] = sum;
    }
};


//6:33 6:52 TLE

class Solution {
public:
    int K;
    const int base = 1e9 + 7;
    int numberOfArrays(string s, int k) {
        string tmp = to_string(k);
        K = tmp.size() < s.size() ? k : stoi(s);
        vector<vector<int>> memo(s.size(), vector<int>(K + 1, -1));
        return dp(s, 0, 0, memo);
    }

    int dp(string& s, int idx, int prev, vector<vector<int>>& memo) {
        if (prev > K) {
            return 0;
        }
        if (idx == s.size()) {
            return 1;
        }
        if (memo[idx][prev] != -1) {
            return memo[idx][prev];
        }
        int sum = 0;
        if (prev > 0) {
            sum += dp(s, idx + 1, prev * 10 + s[idx] - '0', memo);
            sum %= base;
        }
        if (s[idx] > '0') {
            sum += dp(s, idx + 1, s[idx] - '0', memo);
        }
        sum %= base;
        return memo[idx][prev] = sum;
    }
};