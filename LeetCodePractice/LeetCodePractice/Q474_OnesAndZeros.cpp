#include<vector>
#include<string>
using namespace std;
//10:09 10:22
/**
Runtime: 232 ms, faster than 70.86% of C++ online submissions for Ones and Zeroes.
Memory Usage: 102.8 MB, less than 9.65% of C++ online submissions for Ones and Zeroes.

*/
class Solution {
public:
    vector<string> list;
    vector<vector<vector<int>>> memo;
    int findMaxForm(vector<string>& strs, int m, int n) {
        this->list = strs;
        memo = vector<vector<vector<int>>>(strs.size() + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        dp(0, m, n);
        return memo[0][m][n];
    }

    int dp(int pos, int m, int n) {
        if (pos == list.size()) {
            return 0;
        }
        if (memo[pos][m][n] > -1) {
            return memo[pos][m][n];
        }
        int rm = 0;
        int rn = 0;
        parse(list[pos], rm, rn);
        if (rm > m || rn > n) {
            return memo[pos][m][n] = dp(pos + 1, m, n);
        }
        return memo[pos][m][n] = std::max(dp(pos + 1, m, n), dp(pos + 1, m - rm, n - rn) + 1);

    }

    void parse(string& s, int& m, int& n) {
        for (auto& x : s) {
            if (x == '0') {
                m++;
            }
            if (x == '1') {
                n++;
            }
        }
        return;
    }
};