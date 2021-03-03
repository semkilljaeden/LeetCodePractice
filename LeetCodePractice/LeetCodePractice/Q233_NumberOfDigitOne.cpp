#include "LCHeader.h"
//Ultimate template
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Number of Digit One.
Memory Usage: 6.1 MB, less than 64.31% of C++ online submissions for Number of Digit One.
*/
class Solution {
public:
    int countDigitOne(int n) {
        string N = to_string(n);
        vector<vector<vector<int>>> memo(N.size(), vector<vector<int>>(2, vector<int>(N.size() + 1, -1)));
        int r = dp(N, 0, 1, memo, 0);
        return r;
    }

    int dp(string& n, int idx, int limit, vector<vector<vector<int>>>& memo, int count) {
        if (idx == n.size()) {
            return count;
        }
        if (memo[idx][limit][count] != -1) {
            return memo[idx][limit][count];
        }
        int digit = n[idx] - '0';
        int size = limit == 1 ? digit : 9;
        int sum = 0;
        for (int i = 0; i <= size; i++) {
            sum += dp(n, idx + 1, limit == 1 && i == size ? 1 : 0, memo, count + (i == 1 ? 1 : 0));
        }
        return memo[idx][limit][count] = sum;
    }
};


//20mins, AC

class Solution {
public:
    int countDigitOne(int n) {
        string N = to_string(n);
        vector<vector<int>> memo(N.size(), vector<int>(2, -1));
        int r = dp(N, 0, 1, memo);
        return r;
    }

    int dp(string& n, int idx, int limit, vector<vector<int>>& memo) {
        if (idx == n.size()) {
            return 0;
        }
        if (memo[idx][limit] != -1) {
            return memo[idx][limit];
        }
        int digit = n[idx] - '0';
        int size = limit == 1 ? digit : 9;
        int sum = 0;
        for (int i = 0; i <= size; i++) {
            if (i == 1) {
                if (i == size) {
                    sum += idx + 1 < n.size() ? stoi(n.substr(idx + 1, n.size() - idx - 1)) + 1 : 1;
                }
                else {
                    int tmp = 1;
                    for (int i = idx + 1; i < n.size(); i++) {
                        tmp *= 10;
                    }
                    sum += tmp;
                }
            }
            sum += dp(n, idx + 1, limit == 1 && i == size ? 1 : 0, memo);
        }
        return memo[idx][limit] = sum;
    }
};