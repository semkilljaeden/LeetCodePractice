#include "LCHeader.h"
//fucking silly testcase
class Solution {
public:
    int profitableSchemes(int G, int P, vector<int>& group, vector<int>& profit) {
        vector<vector<vector<int>>> memo(group.size() + 1, vector<vector<int>>(G + 1, vector<int>(P + 1, INT_MIN)));

        return dp(0, G, P, group, profit, memo);
        //return memo[0][G][P];
    }
    int dp(int k, int i, int j, vector<int>& group, vector<int>& profit, vector<vector<vector<int>>>& memo) {
        if (k == group.size() - 1) {
            if (i - group[k] >= 0 && j - profit[k] <= 0) {
                return 1;
            }
            return 0;
        }
        if (i < 0) {
            return 0;
        }
        if (j < 0) {
            j = 0;
        }
        int g = group[k];
        int p = profit[k];
        int result = j - profit[k] <= 0 && i - group[k] >= 0 ? 1 : 0;
        result += dp(k + 1, i, j, group, profit, memo);
        result += dp(k + 1, i - g, j - p, group, profit, memo);
        return result;
    }
};


//8:45??
class Solution2 {
public:
    int N;
    int minProfit;
    const int base = 1000000007;
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        this->N = group.size();
        long x = 0;
        long y = 0;
        for (int i = 0; i < N; i++) {
            x += dp(n, minProfit, i, group, profit);
            y += dp2(n, i, group, profit);
        }
        y -= x;
        if (y < 0) {
            y += base;
        }
        y %= base;
        return y;
    }

    long dp(int num, int mp, int pos, vector<int>& group, vector<int>& profit) {
        long n = group[pos];
        long p = profit[pos];
        if (mp < p || num <= n) {
            return 0;
        }
        long sum = n <= num && p < mp ? 1 : 0;
        for (int i = pos + 1; i < N; i++) {
            sum += dp(num - n, mp - p, i, group, profit);
        }
        return sum;
    }

    long dp2(int num, int pos, vector<int>& group, vector<int>& profit) {
        long n = group[pos];
        if (num < n) {
            return 0;
        }
        long sum = n <= num ? 1 : 0;
        for (int i = pos + 1; i < N; i++) {
            sum += dp2(num - n, i, group, profit);
        }
        return sum;
    }
};