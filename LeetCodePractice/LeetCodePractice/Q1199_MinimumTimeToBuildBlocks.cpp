#include "LCHeader.h"
//2:15 read the answer, so close, just did not believe in that greedy nature
//O(N^2)

class Solution {
public:
    int Split;
    int MAX = 100000000;
    int minBuildTime(vector<int>& blocks, int split) {
        Split = split;
        int n = blocks.size();
        sort(blocks.begin(), blocks.end(), std::greater<int>());
        vector<vector<int>> memo(n, vector<int>(n + 1, -1));
        return dp(blocks, 0, 1, memo);
    }

    int dp(vector<int>& blocks, int idx, int workers, vector<vector<int>>& memo) {
        if (idx >= blocks.size()) {
            return 0;
        }
        if (workers == 0) {
            return MAX;
        }
        if (workers > blocks.size() - idx) {
            workers = blocks.size() - idx;
        }
        if (memo[idx][workers] != -1) {
            return memo[idx][workers];
        }
        if (workers == blocks.size() - idx) {
            return memo[idx][workers] = blocks[idx];
        }
        int cur = blocks[idx];
        int min = Split + dp(blocks, idx, workers * 2, memo);
        int max = std::max(cur, dp(blocks, idx + 1, workers - 1, memo));
        return memo[idx][workers] = std::min(min, max);
    }
};

//1:59 TLE O(N^3)

class Solution {
public:
    int Split;
    int minBuildTime(vector<int>& blocks, int split) {
        Split = split;
        int n = blocks.size();
        sort(blocks.begin(), blocks.end(), std::greater<int>());
        vector<vector<int>> memo(n, vector<int>(n + 1, -1));
        return dp(blocks, 0, 1, memo);
    }

    int dp(vector<int>& blocks, int idx, int workers, vector<vector<int>>& memo) {
        if (workers > blocks.size() - idx) {
            workers = blocks.size() - idx;
        }
        if (memo[idx][workers] != -1) {
            return memo[idx][workers];
        }
        if (workers == blocks.size() - idx) {
            return memo[idx][workers] = blocks[idx];
        }
        int max = blocks[idx];
        int min = Split + dp(blocks, idx, workers * 2, memo);
        for (int i = 1; i < workers; i++) {
            int tmp = std::max(max, Split + dp(blocks, idx + i, (workers - i) * 2, memo));
            min = std::min(min, tmp);
        }
        return memo[idx][workers] = min;
    }
};


//12:29 12:45 1:17 1:45 TLE

class Solution {
public:
    int Split;
    int minBuildTime(vector<int>& blocks, int split) {
        Split = split;
        int n = blocks.size();
        sort(blocks.begin(), blocks.end(), std::greater<int>());
        vector<vector<vector<int>>> memo(n, vector<vector<int>>(n, vector<int>(n, -1)));
        return dp(blocks, 0, 1, 0, memo);
    }

    int dp(vector<int>& blocks, int idx, int workers, int count, vector<vector<vector<int>>>& memo) {
        if (workers > blocks.size() - idx) {
            workers = blocks.size() - idx;
        }
        if (memo[idx][workers][count] != -1) {
            return memo[idx][workers][count];
        }
        if (workers == blocks.size() - idx) {
            return blocks[idx] + count * Split;
        }
        int min = INT_MAX;
        for (int i = 0; i < workers; i++) {
            min = std::min(min,
                std::max(i > 0 ? blocks[idx] + count * Split : 0, dp(blocks, idx + i, (workers - i) * 2, count + 1, memo)));
        }
        return memo[idx][workers][count] = min;
    }
};