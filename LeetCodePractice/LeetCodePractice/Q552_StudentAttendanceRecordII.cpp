#include<vector>
using namespace std;

class Solution3 {
public:
    int checkRecord(int n) {
        vector<vector<long>> memo1(2, vector<long>(3, 1));
        vector<vector<long>> memo2(2, vector<long>(3, 1));
        auto* p = &memo1;
        auto* c = &memo2;
        for (int i = 0; i < n; i++) {
            auto& memo = *p;
            auto& cur = *c;
            cur[0][0] = memo[0][1] + memo[0][0];
            cur[1][0] = memo[1][1] + memo[1][0] + memo[0][0];
            cur[0][1] = memo[0][2] + memo[0][0];
            cur[1][1] = memo[1][2] + memo[1][0] + memo[0][0];
            cur[0][2] = memo[0][0];
            cur[1][2] = memo[1][0] + memo[0][0];
            cur[0][0] %= 1000000007L;
            cur[1][0] %= 1000000007L;
            cur[0][1] %= 1000000007L;
            cur[1][1] %= 1000000007L;
            cur[0][2] %= 1000000007L;
            cur[1][2] %= 1000000007L;
            swap(p, c);
        }
        return (*p)[1][0];
    }
};


//Top down, memory optimized
/*
Runtime: 1856 ms, faster than 5.22% of C++ online submissions for Student Attendance Record II.
Memory Usage: 474.2 MB, less than 5.22% of C++ online submissions for Student Attendance Record II.
*/
class Solution2 {
public:
    int checkRecord(int n) {
        vector<vector<long>> memo(2, vector<long>(3, 1));
        for (int i = 0; i < n; i++) {
            vector<vector<long>> cur(2, vector<long>(3, 0));
            cur[0][0] = memo[0][1] + memo[0][0];
            cur[1][0] = memo[1][1] + memo[1][0] + memo[0][0];
            cur[0][1] = memo[0][2] + memo[0][0];
            cur[1][1] = memo[1][2] + memo[1][0] + memo[0][0];
            cur[0][2] = memo[0][0];
            cur[1][2] = memo[1][0] + memo[0][0];
            cur[0][0] %= 1000000007L;
            cur[1][0] %= 1000000007L;
            cur[0][1] %= 1000000007L;
            cur[1][1] %= 1000000007L;
            cur[0][2] %= 1000000007L;
            cur[1][2] %= 1000000007L;
            memo = move(cur);
        }
        return memo[1][0];
    }
};



//4:09, ez O(n), actually finished in 30mins

class Solution1 {
public:
    int n;
    const int base = 1000000007;
    vector<vector<vector<int>>> memo;
    int checkRecord(int n) {
        this->n = n;
        memo = vector<vector<vector<int>>>(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return dp(0);
    }

    int dp(int i, int a = 1, int prev = 0) {
        if (a < 0 || prev > 2) {
            return 0;
        }
        if (i >= n) {
            return 1;
        }
        if (memo[i][a][prev] != -1) {
            return memo[i][a][prev];
        }
        int sum = 0;
        if (prev == 0) {
            sum += dp(i + 1, a, 1) % base;
        }
        else if (prev == 1) {
            sum += dp(i + 1, a, 2) % base;
        }
        sum %= base;
        sum += dp(i + 1, a, 0) % base;
        sum %= base;
        sum += dp(i + 1, a - 1, 0) % base;
        sum %= base;
        return memo[i][a][prev] = sum;
    }
};
