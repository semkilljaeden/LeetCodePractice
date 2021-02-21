#include<vector>
#include<string>
using namespace std;
//read the answer, fantastic answer
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Non-negative Integers without Consecutive Ones.
Memory Usage: 6 MB, less than 80.90% of C++ online submissions for Non-negative Integers without Consecutive Ones.
*/
class Solution {
public:
    int n;
    int N;
    int findIntegers(int num) {
        string s;
        int i = 0;
        int n = num;
        while (i < 31 && n > 0) {
            s += (1 << i | num) == num ? '1' : '0';
            n = n >> 1;
            i++;
        }
        reverse(s.begin(), s.end());
        int e1 = 0;
        int e0 = 1;
        int s1 = 0;
        int s0 = 0;
        for (auto& x : s) {
            int n_e0 = x == '0' ? e0 + e1 : 0;
            int n_e1 = x == '1' ? e0 : 0;
            int n_s0 = s0 + (x == '1' ? e1 + e0 : 0) + s1;
            int n_s1 = s0;
            e1 = n_e1;
            e0 = n_e0;
            s1 = n_s1;
            s0 = n_s0;
        }
        return e1 + e0 + s0 + s1;
    }
};
//5:31 5:42 brutal force
class Solution {
public:
    int n;
    int N;
    int findIntegers(int num) {
        n = num;
        while (num > 0) {
            num = num >> 1;
            N++;
        }
        vector<vector<int>> memo(N + 1, vector<int>(2, -1));
        return dp(0, 0, 0, memo);
    }

    int dp(int i, int prev, int sum, vector<vector<int>>& memo) {
        if (sum > n) {
            return 0;
        }
        if (i == N && sum <= n) {
            return 1;
        }
        if (memo[i][prev] != -1) {
            return memo[i][prev];
        }
        int res = 0;
        if (prev == 0) {
            res += dp(i + 1, 1, (sum << 1) + 1, memo);
            res += dp(i + 1, 0, sum << 1, memo);
        }
        else {
            res += dp(i + 1, 0, sum << 1, memo);
        }
        return res;
    }
};