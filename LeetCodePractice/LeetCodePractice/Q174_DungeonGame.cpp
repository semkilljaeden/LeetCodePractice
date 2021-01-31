#include<vector>
#include<string>
using namespace std;
//1:48 hard,read the solution, did not come up with the reverse DP 2:07
/*
Runtime: 8 ms, faster than 88.72% of C++ online submissions for Dungeon Game.
Memory Usage: 9 MB, less than 66.87% of C++ online submissions for Dungeon Game.

*/
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& d) {
        if (d.size() == 0 || d[0].size() == 0)
        {
            return 0;
        }
        int m = d.size();
        int n = d[0].size();
        vector<vector<int>> memo(m, vector<int>(n, 0));
        memo[m - 1][n - 1] = d[m - 1][n - 1] >= 0 ? 1 : 1 - d[m - 1][n - 1];

        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (i == m - 1 && j == n - 1)
                {
                    continue;
                }
                long right = INT_MAX;
                long down = INT_MAX;
                if (i + 1 < m)
                {
                    down = memo[i + 1][j];
                }
                if (j + 1 < n)
                {
                    right = memo[i][j + 1];
                }
                right = (right -= d[i][j]) <= 0 ? 1 : right;
                down = (down -= d[i][j]) <= 0 ? 1 : down;
                memo[i][j] = min(right, down);

            }
        }
        return memo[0][0];
    }
};