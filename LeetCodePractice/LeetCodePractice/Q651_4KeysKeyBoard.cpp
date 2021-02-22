#include<vector>
#include<algorithm>
#include<string>
using namespace std;
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for 4 Keys Keyboard.
Memory Usage: 6.2 MB, less than 34.02% of C++ online submissions for 4 Keys Keyboard.
*/
class Solution {
public:
    int maxA(int N) {
        vector<int> memo(N + 1, -1);
        return dp(N, memo);
    }
    int dp(int n, vector<int>& memo) {
        if (n == 1) {
            return 1;
        }
        if (memo[n] != -1) {
            return memo[n];
        }
        int max = 0;
        max = 1 + dp(n - 1, memo);
        for (int i = 1; i < n - 1; i++) {
            max = std::max((n - i - 1) * dp(i, memo), max);
        }

        return memo[n] = max;
    }
};

//2:00, sad did not think of the best recursion
class Solution {
public:
    int maxA(int N) {
        return dp(N);
    }
    int dp(int n) {
        if (n == 1) {
            return 1;
        }
        int max = 0;
        max = 1 + dp(n - 1);
        for (int i = 1; i < n - 1; i++) {
            max = std::max((n - i - 1) * dp(i), max);
        }

        return max;
    }
};

//1:03 1:20 TLE haha, there are some greedy concept
class Solution {
public:
    int maxA(int N) {
        return dp(0, N, 0);
    }
    int dp(int l, int n, int cb) {
        if (n <= 0) {
            return l;
        }
        int max = 0;
        max = std::max(dp(l + 1, n - 1, cb), max);
        if (cb > 0) {
            max = std::max(dp(l + cb, n - 1, cb), max);
        }
        max = std::max(dp(l, n - 2, l), max);
        return max;
    }
};