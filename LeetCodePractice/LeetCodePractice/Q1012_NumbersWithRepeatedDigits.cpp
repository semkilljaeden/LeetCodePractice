#include "LCHeader.h"
//12:43 1:24 45mins AC O(logN * 2 * 2 * 1 << 10)

class Solution {
public:
    int numDupDigitsAtMostN(int N) {
        string n = to_string(N);
        vector<vector<vector<vector<int>>>> memo(n.size(), vector<vector<vector<int>>>(2, vector<vector<int>>(2, vector<int>(1 << 10, -1))));
        return dp(n, 0, 1, 1, 0, 0, memo);
    }

    int dp(string& n, int idx, int limit, int leadingZero, int prevMask, int repeated, vector<vector<vector<vector<int>>>>& memo) {
        if (idx == n.size()) {
            return repeated == 1 ? 1 : 0;
        }
        if (memo[idx][limit][repeated][prevMask] != -1) {
            return memo[idx][limit][repeated][prevMask];
        }
        int upper = (limit == 1 ? n[idx] - '0' : 9);
        int sum = 0;
        for (int i = 0; i <= upper; i++) {
            bool rp = false;
            for (int j = 0; j <= upper; j++) {
                if (((1 << j) | prevMask) == prevMask && i == j) {
                    rp = true;
                    break;
                }
            }
            int zero = leadingZero == 1 && i == 0 ? 1 : 0;
            int new_prev = prevMask;
            if (zero != 1) {
                new_prev |= 1 << i;
            }
            sum += dp(n, idx + 1, limit == 1 && i == upper ? 1 : 0,

                zero

                , new_prev, repeated == 1 || rp ? 1 : 0, memo);
        }
        return memo[idx][limit][repeated][prevMask] = sum;
    }
};