#include "LCHeader.h"
//12:45 1:42, read the answer
class Solution {
public:
    vector<int> memo;
    vector<int> digit;
    int base = 1000000007;
    int distinctSubseqII(string S) {
        memo = vector<int>(S.size() + 1, -1);
        digit = vector<int>(S.size() + 1, -1);
        return dp(S, 0) - 1;
    }

    int dp(string& S, int i) {
        if (i == S.size()) {
            memo[i] = 1;
            digit[i] = 0;
            return 1;
        }
        int tmp = dp(S, i + 1);
        int dup = 0;
        for (int j = i + 1; j < S.size(); j++) {
            if (digit[j] == S[i]) {
                dup = memo[j + 1];
                break;
            }
        }
        memo[i] = (tmp + tmp) % base;
        memo[i] -= dup;
        memo[i] %= base;
        if (memo[i] < 0) {
            memo[i] += base;
        }
        digit[i] = S[i];
        return memo[i];
    }
};