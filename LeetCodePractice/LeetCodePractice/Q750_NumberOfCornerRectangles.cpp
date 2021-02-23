#include "LCHeader.h"
//10:52 11:24

class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        unordered_map<string, int> memo;
        int result = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    for (int k = j + 1; k < n; k++) {
                        if (grid[i][k] == 1) {
                            string hash = to_string(j) + " " + to_string(k);
                            result += memo[hash];
                            memo[hash] += 1;
                        }
                    }
                }
            }
        }
        return result;
    }
};