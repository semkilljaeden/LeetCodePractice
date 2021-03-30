#include<vector>
#include<queue>
using namespace std;

//3:25

class Solution {//9:30 10:03
public:
    int shortestDistance(vector<vector<int>>& grid) {
        queue<vector<int>> q;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> direction{ {0, 1},
                              {0, -1},
                              {1, 0},
                              {-1, 0} };
        vector<vector<int>> result(m, vector<int>(n, 0));
        int walk = 0;
        int mm = INT_MAX;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int min = INT_MAX;
                if (grid[i][j] == 1) {
                    q.push({ i, j });
                    int level = 1;
                    while (q.size() > 0) {
                        int size = q.size();
                        for (int i = 0; i < size; i++) {
                            auto x = q.front();
                            q.pop();
                            for (auto& y : direction) {
                                int r = x[0] + y[0];
                                int c = x[1] + y[1];
                                if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 2 || grid[r][c] == 1) {
                                    continue;
                                }
                                if (grid[r][c] < walk - 1) {
                                    return -1;
                                }
                                if (grid[r][c] == walk) {
                                    result[r][c] += level;
                                    grid[r][c]--;
                                    min = std::min(min, result[r][c]);
                                    q.push({ r, c });
                                }
                            }
                        }
                        level++;
                    }
                    walk--;
                    mm = min;
                }
            }
        }
        return mm == INT_MAX ? -1 : mm;

    }
};