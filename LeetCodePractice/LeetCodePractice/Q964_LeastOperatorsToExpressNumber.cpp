#include "LCHeader.h"
//10:53 11: 35, read the answer. stupid greedy

class Solution {
public:
    int leastOpsExpressTarget(int x, int target) {
        return dp(x, target);
    }

    long dp(long x, long target) {
        if (target < x) {
            long left = x - target + x - target;
            long right = 2 * target - 1;
            return min(left, right);
        }
        long action = 1;
        long cur = x;
        while (cur * x <= target) {
            cur *= x;
            action++;
        }
        if (cur == target) {
            return action - 1;
        }
        long min = action + dp(x, target - cur);
        if (cur * x - target < target) {
            min = std::min(min, action + 1 + dp(x, cur * x - target));
        }

        return min;
    }
};