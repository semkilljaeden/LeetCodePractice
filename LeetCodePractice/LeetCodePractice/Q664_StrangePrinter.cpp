#include<vector>
#include<string>
using namespace std;
//9:31 10:03, TLE O(n^3) but i think good enough for me hahahhahah  i am so good
class Solution {
public:
    char base = 'a' - 1;
    int memo[100][100];
    int strangePrinter(string s) {
        memset(memo, -1, sizeof memo);
        return dp(s, 0, s.size() - 1);
    }
    int dp(string& s, int left, int right) {
        if (right < left) {
            return 0;
        }
        if (right == left) {
            return 1;
        }
        if (memo[left][right] != -1) {
            return memo[left][right];
        }
        int min = INT_MAX;
        min = std::min(min, 1 + dp(s, left + 1, right));
        for (int i = left + 1; i <= right; i++) {
            if (s[i] == s[left]) {
                min = std::min(min, dp(s, left, i - 1) + dp(s, i + 1, right));
            }
        }
        return memo[left][right] = min;
    }
};

class Solution2 {
public:
    char base = 'a' - 1;
    int strangePrinter(string s) {
        vector<vector<vector<int>>> memo(s.size() + 1, vector<vector<int>>(s.size() + 1, vector<int>(27, -1)));
        return dp(s, 0, s.size() - 1, base, memo);
    }
    int dp(string& s, int left, int right, int c, vector<vector<vector<int>>>& memo) {
        if (right < left) {
            return 0;
        }
        if (right == left) {
            return c == s[right] ? 0 : 1;
        }
        if (memo[left][right][c - base] != -1) {
            return memo[left][right][c - base];
        }
        int min = INT_MAX;
        for (int i = left; i <= right; i++) {
            if (s[i] == c) {
                min = std::min(min, dp(s, left, i - 1, s[i], memo) + dp(s, i + 1, right, s[i], memo));
            }
            else {
                min = std::min(min, 1 + dp(s, left, i - 1, s[i], memo) + dp(s, i + 1, right, s[i], memo));
                min = std::min(min, 1 + dp(s, left, i - 1, c, memo) + dp(s, i + 1, right, c, memo));
            }
        }
        return memo[left][right][c - base] = min;
    }
};