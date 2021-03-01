#include "LCHeader.h"

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        if (piles.size() == 0) {
            return false;
        }
        int n = piles.size();
        vector<vector<int>> memo(n + 1, vector<int>(n + 1, -1));
        return dp(piles, 0, piles.size() - 1, 0, memo) > 0;
    }

    int dp(vector<int>& piles, int i, int j, int counter, vector<vector<int>>& memo) {
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        if (i == j) {
            return memo[i][j] = piles[i];
        }
        int left = dp(piles, i + 1, j, counter + 1, memo);
        int right = dp(piles, i, j - 1, counter + 1, memo);
        return memo[i][j] = max(piles[i] - left, piles[j] - right);
    }
};


//7:08 7:28

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        if (piles.size() == 0) {
            return false;
        }
        int n = piles.size();
        vector<vector<vector<int>>> memo(n + 1, vector<vector<int>>(n + 1, vector<int>(2, -1)));
        return dp(piles, 0, piles.size() - 1, 0, memo) > 0;
    }

    int dp(vector<int>& piles, int i, int j, int counter, vector<vector<vector<int>>>& memo) {
        if (memo[i][j][counter % 2] != -1) {
            return memo[i][j][counter % 2];
        }
        if (i == j) {
            return memo[i][j][counter % 2] = counter % 2 == 0 ? piles[i] : -piles[i];
        }
        int left = dp(piles, i + 1, j, counter + 1, memo);
        int right = dp(piles, i, j - 1, counter + 1, memo);
        if (counter % 2 == 0) {
            return memo[i][j][counter % 2] = max(left + piles[i], right + piles[j]);
        }
        else {
            return memo[i][j][counter % 2] = min(left - piles[i], right - piles[j]);
        }
    }
};