#include "LCHeader.h"

//10:00 10:08

class Solution {
public:
    int D;
    int F;
    const static int base = 1e9 + 7;
    int numRollsToTarget(int d, int f, int target) {
        D = d;
        F = f;
        vector<int> memo1(target + 1, 0);
        vector<int> memo2(target + 1, 0);
        auto m1 = &memo1;
        auto m2 = &memo2;
        memo1[0] = 1;
        for (int i = 0; i < d; i++) {
            for (int j = 0; j <= target; j++) {
                auto& prev = *m1;
                auto& cur = *m2;
                cur[j] = 0;
                for (int k = 0; k < f; k++) {
                    if (j - k - 1 < 0) {
                        continue;
                    }
                    cur[j] += prev[j - k - 1] % base;
                    cur[j] %= base;
                }
            }
            swap(m1, m2);
        }
        return (*m1)[target];

    }
};

//9:50 9:55 too easy
class Solution {
public:
    int D;
    int F;
    const static int base = 1e9 + 7;
    int numRollsToTarget(int d, int f, int target) {
        D = d;
        F = f;
        vector<vector<int>> memo(d, vector<int>(target + 1, -1));
        return dp(0, target, memo);
    }

    int dp(int idx, int target, vector<vector<int>>& memo) {
        if (idx == D) {
            return target == 0 ? 1 : 0;
        }
        if (target <= 0) {
            return 0;
        }
        if (memo[idx][target] != -1) {
            return memo[idx][target];
        }
        int sum = 0;
        for (int i = 0; i < F; i++) {
            sum += dp(idx + 1, target - i - 1, memo) % base;
            sum %= base;
        }
        return memo[idx][target] = sum;
    }
};