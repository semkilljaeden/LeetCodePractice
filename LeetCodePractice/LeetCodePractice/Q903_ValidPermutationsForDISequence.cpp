#include "LCHeader.h"

//11:19 there is a key point that is actually hard to prove.

class Solution {
public:
    const int base = 1000000007;
    int numPermsDISequence(string S) {
        unordered_set<int> path;
        int sum = 0;
        vector<vector<int>> memo(S.size() + 1, vector<int>(S.size() + 1, -1));
        for (int i = 0; i < S.size() + 1; i++) {
            path.insert(i);
            sum += dp(S, 0, path, i, memo);
            sum %= base;
            path.erase(i);
        }
        return sum;
    }

    int dp(const string& S, int idx, unordered_set<int>& path, int prev, vector<vector<int>>& memo) {
        if (idx == S.size()) {
            return 1;
        }
        if (memo[idx][prev] != -1) {
            return memo[idx][prev];
        }
        int sum = 0;
        for (int i = 0; i < S.size() + 1; i++) {
            if (path.count(i) > 0 || i > prev && S[idx] == 'D' || i < prev && S[idx] == 'I') {
                continue;
            }
            if (memo[idx + 1][i] == -1) {
                path.insert(i);
                sum += dp(S, idx + 1, path, i, memo);
                path.erase(i);
            }
            else {
                sum += memo[idx + 1][i];
            }

            sum %= base;
        }
        return memo[idx][prev] = sum;
    }
};