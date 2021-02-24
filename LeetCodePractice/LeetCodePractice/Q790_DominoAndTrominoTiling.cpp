#include "LCHeader.h"

//12:37 read question wrongly, re-write 1:01 1:21

class Solution {
public:
    int N;
    const int base = 1000000007;
    vector<vector<long>> memo;
    int numTilings(int N) {
        this->N = N;
        memo = vector<vector<long>>(N, vector<long>(4, -1));
        return dp(0, 0, 0);
    }

    long dp(int pos, int left, int right) {
        if (pos == N - 1) {
            return left == 1 && right == 1 || left == 0 && right == 0 ? 1 : 0;
        }
        if (memo[pos][(left << 1) + right] != -1) {
            return memo[pos][(left << 1) + right];
        }
        long result = 0;
        if (left == 0 && right == 0) {
            result = dp(pos + 1, 0, 0) + dp(pos + 1, 1, 1);
            result %= base;
            result += dp(pos + 1, 0, 1);
            result %= base;
            result += dp(pos + 1, 1, 0);
        }
        else if (left == 1 && right == 0) {
            result = dp(pos + 1, 0, 1) + dp(pos + 1, 1, 1);
        }
        else if (left == 0 && right == 1) {
            result = dp(pos + 1, 1, 0) + dp(pos + 1, 1, 1);
        }
        else if (left == 1 && right == 1) {
            result = dp(pos + 1, 0, 0);
        }
        return memo[pos][(left << 1) + right] = result %= base;;
    }
};