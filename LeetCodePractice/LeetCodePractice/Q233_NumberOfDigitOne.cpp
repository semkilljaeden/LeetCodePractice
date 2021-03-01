#include "LCHeader.h"
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