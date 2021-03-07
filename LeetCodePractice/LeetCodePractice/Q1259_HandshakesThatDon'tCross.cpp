#include "LCHeader.h"
/*
Runtime: 56 ms, faster than 32.14% of C++ online submissions for Handshakes That Don't Cross.
Memory Usage: 6.4 MB, less than 75.00% of C++ online submissions for Handshakes That Don't Cross.
*/
//vector is much faster
class Solution {
public:
    int base = 1e9 + 7;
    int numberOfWays(int num_people) {
        vector<int> map(num_people + 1, -1);
        return dp(num_people, map);
    }

    long dp(int n, vector<int>& map) {
        if (n == 2 || n == 0) {
            return 1;
        }
        if (n % 2 == 1) {
            return 0;
        }
        if (map[n] != -1) {
            return map[n];
        }
        long sum = 0;
        for (int i = 1; i < n; i++) {
            int left = n - i - 1;
            int right = i - 1;
            if (left % 2 != 0 || right % 2 != 0) {
                continue;
            }
            sum += dp(left, map) * dp(right, map);
            sum %= base;
        }
        return map[n] = sum;
    }
};

//4:04 4:09 seems to got the idea halt 6:05 6:30 done, 30mins

class Solution {
public:
    int base = 1e9 + 7;
    int numberOfWays(int num_people) {
        unordered_map<int, long> map;
        return dp(num_people, map);
    }

    long dp(int n, unordered_map<int, long>& map) {
        if (n == 2 || n == 0) {
            return 1;
        }
        if (n % 2 == 1) {
            return 0;
        }
        if (map.count(n) > 0) {
            return map[n];
        }
        long sum = 0;
        for (int i = 1; i < n; i++) {
            int left = n - i - 1;
            int right = i - 1;
            if (left % 2 != 0 || right % 2 != 0) {
                continue;
            }
            sum += dp(left, map) * dp(right, map);
            sum %= base;
        }
        return map[n] = sum;
    }
};