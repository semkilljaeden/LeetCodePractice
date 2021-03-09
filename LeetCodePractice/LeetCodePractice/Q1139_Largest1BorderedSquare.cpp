#include "LCHeader.h"

//5:09 5:42 O(n^3) can optimize

class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> h_memo(m, vector<vector<int>>(n, vector<int>(n, 0)));
        vector<vector<vector<int>>> v_memo(n, vector<vector<int>>(m, vector<int>(m, 0)));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 1) {
                    continue;
                }
                for (int k = j; k < n; k++) {
                    if (grid[i][k] != 1) {
                        break;
                    }
                    h_memo[i][j][k] = 1;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[j][i] != 1) {
                    continue;
                }
                for (int k = j; k < m; k++) {
                    if (grid[k][i] != 1) {
                        break;
                    }
                    v_memo[i][j][k] = 1;
                }
            }
        }
        int result = 0;
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                result = std::max(result, validate(i, j, h_memo, v_memo));
            }
        }
        return result;
    }

    int validate(int i, int j, vector<vector<vector<int>>>& h_memo, vector<vector<vector<int>>>& v_memo) {
        int ii = i;
        int jj = j;
        int count = 0;
        while (ii >= 0 && jj >= 0) {
            if (h_memo[i][jj][j] == 1 && h_memo[ii][jj][j] == 1 &&
                v_memo[j][ii][i] == 1 && v_memo[jj][ii][i] == 1) {
                count = (i - ii + 1) * (i - ii + 1);
            }
            ii--;
            jj--;
        }
        return count;
    }
};