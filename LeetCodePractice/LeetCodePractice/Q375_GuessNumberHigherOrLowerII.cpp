#include<vector>
using namespace std;
//9:50 dp
class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> memo(n + 4, vector<int>(n + 5, INT_MIN));
        for (int j = 1; j <= n + 1; j++) {
            memo[j][j] = 0;
            memo[j][j + 1] = 0;
            memo[j][j + 2] = j;
            memo[j][j + 3] = j + 1;
        }
        for (int i = 4; i <= n; i++) {
            for (int j = 1; j + i <= n + 1; j++) {
                int min = INT_MAX;
                int left = j;
                int right = j + i;
                for (int k = left; k < right; ++k) {
                    min = std::min(min, std::max(memo[left][k], memo[k + 1][right]) + k);
                }
                memo[left][right] = min;
            }
        }
        return memo[1][n + 1];
    }

};


//8:34 9:06, one silly bug for the range check
/*
Runtime: 184 ms, faster than 52.55% of C++ online submissions for Guess Number Higher or Lower II.
Memory Usage: 8.3 MB, less than 45.75% of C++ online submissions for Guess Number Higher or Lower II.
*/
class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> memo(n + 1, vector<int>(n + 2, -1));
        return gm(1, n + 1, memo);
    }

    long gm(int i, int j, vector<vector<int>>& memo) {
        if (i + 1 == j) {
            return 0;
        }
        if (i + 2 == j) {
            return i;
        }
        if (i + 3 == j) {
            return i + 1;
        }
        if (i >= j) {
            return INT_MAX;
        }
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        long min = INT_MAX;
        for (int x = i; x < j; ++x) {
            long left = gm(i, x, memo);
            long right = gm(x + 1, j, memo);
            min = std::min(x + std::max(left, right), min);
        }
        return memo[i][j] = min;
    }
};