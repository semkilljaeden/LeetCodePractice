#include<vector>
using namespace std;
//10:43 to 11:14 dp O(n^2)
/*
Runtime: 76 ms, faster than 22.33% of C++ online submissions for Bomb Enemy.
Memory Usage: 27.7 MB, less than 5.12% of C++ online submissions for Bomb Enemy.
*/
class Solution {
public:
    using cd = vector<int>;
    int maxKilledEnemies(vector<vector<char>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) {
            return 0;
        }
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<cd>> memo(m + 2, vector<cd>(n + 2, cd(5, 0)));
        int max = 0;
        for (int i = 1; i < m + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                auto& c = grid[i - 1][j - 1];
                auto& up = memo[i - 1][j][1];
                auto& left = memo[i][j - 1][0];
                if (c == 'E') {
                    memo[i][j][0] = left + 1;
                    memo[i][j][1] = up + 1;
                }
                else if (c == '0') {
                    memo[i][j][0] = left;
                    memo[i][j][1] = up;
                }
                else if (c == 'W') {
                    continue;
                }
                memo[i][j][4] += left + up;
            }
        }
        for (int i = m; i >= 1; i--) {
            for (int j = n; j >= 1; j--) {
                auto& c = grid[i - 1][j - 1];
                auto& right = memo[i][j + 1][2];
                auto& down = memo[i + 1][j][3];
                if (c == 'E') {
                    memo[i][j][2] = right + 1;
                    memo[i][j][3] = down + 1;
                    memo[i][j][4] += right + down;
                }
                else if (c == '0') {
                    memo[i][j][2] = right;
                    memo[i][j][3] = down;
                    memo[i][j][4] += right + down;
                    max = std::max(max, memo[i][j][4]);
                }
                else if (c == 'W') {
                    continue;
                }
            }
        }
        return max;
    }
};