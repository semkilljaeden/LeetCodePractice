#include "LCHeader.h"
//7:13 8:44 read answer
class Solution {
public:
    int m;
    int n;
    vector<vector<int>> grid;
    vector<vector<vector<int>>> memo;

    int cherryPickup(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        this->grid = grid;
        memo = vector<vector<vector<int>>>(m + 1, vector<vector<int>>(m + 1, vector<int>(m + 1, -1)));
        int r = dp(0, 0, 0);
        return r < 0 ? 0 : r;
    }

    int dp(int i, int j, int r) {
        int y = i + j - r;
        if (i >= m || j >= n || grid[i][j] == -1
            || r >= m || y >= n || grid[r][i + j - r] == -1) {
            return INT_MIN;
        }
        if (i == m - 1 && j == n - 1) {
            return grid[i][j];
        }
        if (memo[i][j][r] != -1) {
            return memo[i][j][r];
        }
        int result = grid[i][j] + (i != r ? grid[r][y] : 0);
        int max = INT_MIN;
        max = std::max(max, dp(i + 1, j, r + 1));
        max = std::max(max, dp(i + 1, j, r));
        max = std::max(max, dp(i, j + 1, r + 1));
        max = std::max(max, dp(i, j + 1, r));
        return memo[i][j][r] = max + result;
    }

};