#include "LCHeader.h"
//11:37 11:46 11:53 AC
class Solution {
public:
    int M;
    int N;
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        M = workers.size();
        N = bikes.size();
        vector<vector<int>> memo(1 << M, vector<int>(1 << N, -1));
        return dp(workers, bikes, 0, 0, memo);
    }

    int dp(vector<vector<int>>& workers, vector<vector<int>>& bikes, int wMask, int bMask, vector<vector<int>>& memo) {
        if (wMask == ((1 << M) - 1)) {
            return 0;
        }
        if (memo[wMask][bMask] != -1) {
            return memo[wMask][bMask];
        }
        int min = 1000000;
        for (int i = 0; i < M; i++) {
            if (((1 << i) | wMask) == wMask) {
                continue;
            }
            for (int j = 0; j < N; j++) {
                if (((1 << j) | bMask) == bMask) {
                    continue;
                }
                auto& worker = workers[i];
                auto& bike = bikes[j];
                int dis = abs(worker[0] - bike[0]) + abs(worker[1] - bike[1]);
                min = std::min(min, dis + dp(workers, bikes, wMask | (1 << i), bMask | (1 << j), memo));
            }
        }
        return memo[wMask][bMask] = min;
    }
};