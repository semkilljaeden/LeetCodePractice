#include<vector>
#include<string>
using namespace std;
//8:49 9:03
/*
Runtime: 52 ms, faster than 27.59% of C++ online submissions for Minimum ASCII Delete Sum for Two Strings.
Memory Usage: 15.1 MB, less than 50.26% of C++ online submissions for Minimum ASCII Delete Sum for Two Strings.
*/
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>> memo(s1.size() + 1, vector<int>(s2.size() + 1, -1));
        return dp(s1, s2, 0, 0, memo);
    }

    int dp(string& s1, string& s2, int i, int j, vector<vector<int>>& memo) {
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        if (i == s1.size()) {
            int sum = 0;
            for (int x = j; x < s2.size(); x++) {
                sum += s2[x];
            }
            return memo[i][j] = sum;
        }
        if (j == s2.size()) {
            int sum = 0;
            for (int x = i; x < s1.size(); x++) {
                sum += s1[x];
            }
            return memo[i][j] = sum;
        }
        int min = INT_MAX;
        if (s1[i] == s2[j]) {
            return dp(s1, s2, i + 1, j + 1, memo);
        }
        min = std::min(min, dp(s1, s2, i + 1, j, memo) + s1[i]);
        min = std::min(min, dp(s1, s2, i, j + 1, memo) + s2[j]);
        return memo[i][j] = min;
    }
};