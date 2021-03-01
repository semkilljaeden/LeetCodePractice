#include "LCHeader.h"
//4:03 4:28, cooked lunch in between

class Solution {
public:
    int knightDialer(int n) {
        if (n == 1) {
            return 10;
        }
        unordered_map<int, vector<int>> moves{
            {1, vector<int>{8, 6}},
            {2, vector<int>{7, 9}},
            {3, vector<int>{4, 8}},
            {4, vector<int>{3, 9, 0}},
            {6, vector<int>{1, 7, 0}},
            {7, vector<int>{2, 6}},
            {8, vector<int>{1, 3}},
            {9, vector<int>{2, 4}},
            {0, vector<int>{4, 6}}
        };
        int sum = 0;
        vector<vector<int>> memo(n + 1, vector<int>(10, -1));
        for (int i = 0; i < 10; i++) {
            if (i == 5) {
                continue;
            }
            sum += dp(moves, n, i, memo);
            sum %= 1000000007;
        }
        return sum;
    }
    int dp(unordered_map<int, vector<int>>& moves, int count, int i, vector<vector<int>>& memo) {
        if (count == 1) {
            return 1;
        }
        if (memo[count][i] != -1) {
            return memo[count][i];
        }
        int sum = 0;
        for (auto& x : moves[i]) {
            sum += dp(moves, count - 1, x, memo);
            sum %= 1000000007;
        }
        return memo[count][i] = sum;
    }
};