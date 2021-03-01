#include "LCHeader.h"
#include "queue"




class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        queue<vector<int>> q;
        int m = grid.size();
        int n = grid[0].size();
        int kc = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '@') {
                    q.push(vector<int>{i, j, 0});
                }
                if (grid[i][j] >= 'a' && grid[i][j] <= 'f') {
                    kc++;
                }
            }
        }
        vector<vector<vector<int>>> vis(m, vector<vector<int>>(n, vector<int>(64, 0)));
        vector<vector<int>> dir{
            vector<int>{1, 0},
            vector<int>{0, 1},
            vector<int>{-1, 0},
            vector<int>{0, -1} };
        int level = 1;
        while (q.size() > 0) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto x = q.front();
                q.pop();
                if (vis[x[0]][x[1]][x[2]] == 1) {
                    continue;
                }
                vis[x[0]][x[1]][x[2]] = 1;
                for (auto& t : dir) {
                    auto tmp = x;
                    tmp[0] += t[0];
                    tmp[1] += t[1];
                    if (tmp[0] < 0 || tmp[0] >= m || tmp[1] < 0 || tmp[1] >= n || grid[tmp[0]][tmp[1]] == '#') {
                        continue;
                    }
                    if (grid[tmp[0]][tmp[1]] >= 'a' && grid[tmp[0]][tmp[1]] <= 'f') {
                        tmp[2] |= 1 << (grid[tmp[0]][tmp[1]] - 'a');
                        if (tmp[2] == (1 << kc) - 1) {
                            return level;
                        }
                    }
                    if (grid[tmp[0]][tmp[1]] >= 'A' && grid[tmp[0]][tmp[1]] <= 'F' && (tmp[2] | 1 << (grid[tmp[0]][tmp[1]] - 'A')) > tmp[2]) {
                        continue;
                    }

                    q.push(tmp);
                }
            }
            level++;
            if (level > m * n * 2) {
                break;
            }
        }
        return -1;
    }
};




class Solution2 {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        queue<vector<int>> q;
        int m = grid.size();
        int n = grid[0].size();
        int kc = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '@') {
                    q.push(vector<int>{i, j, 0});
                }
                if (grid[i][j] >= 'a' && grid[i][j] <= 'f') {
                    kc++;
                }
            }
        }
        vector<vector<int>> dir{
            vector<int>{1, 0},
            vector<int>{0, 1},
            vector<int>{-1, 0},
            vector<int>{0, -1} };
        int level = 1;
        while (q.size() > 0) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto x = q.front();
                q.pop();
                for (auto& t : dir) {
                    auto tmp = x;
                    tmp[0] += t[0];
                    tmp[1] += t[1];
                    if (tmp[0] < 0 || tmp[0] >= m || tmp[1] < 0 || tmp[1] >= n || grid[tmp[0]][tmp[1]] == '#') {
                        continue;
                    }
                    if (grid[tmp[0]][tmp[1]] >= 'a' && grid[tmp[0]][tmp[1]] <= 'f') {
                        tmp[2] |= 1 << (grid[tmp[0]][tmp[1]] - 'a');
                        if (tmp[2] == (1 << kc) - 1) {
                            return level;
                        }
                    }
                    if (grid[tmp[0]][tmp[1]] >= 'A' && grid[tmp[0]][tmp[1]] <= 'F' && (tmp[2] | 1 << (grid[tmp[0]][tmp[1]] - 'A')) > tmp[2]) {
                        continue;
                    }
                    q.push(tmp);
                }
            }
            level++;
            if (level > m * n * 2) {
                break;
            }
        }
        return -1;
    }
};
