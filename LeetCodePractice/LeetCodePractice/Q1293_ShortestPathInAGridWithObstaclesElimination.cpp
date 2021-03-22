#include "LCHeader.h"
#include "queue"


class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> direction{ {0, 1},
                                       {0, -1},
                                       {1, 0},
                                       {-1, 0} };
        queue<vector<int>> q;
        q.push({ 0, 0, k });
        vector<vector<int>> visited(m, vector<int>(n, -1));
        q.push({ 0, 0, k });
        int level = 0;
        while (q.size() > 0) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto x = q.front();
                q.pop();
                if (x[0] == m - 1 && x[1] == n - 1) {
                    return level;
                }
                for (auto& y : direction) {
                    int i = x[0] + y[0];
                    int j = x[1] + y[1];
                    if (i < 0 || i >= m || j < 0 || j >= n) {
                        continue;
                    }
                    int key = x[2];
                    if (grid[i][j] == 1) {
                        if (key == 0) {
                            continue;
                        }
                        key--;
                    }
                    if (visited[i][j] >= key) {
                        continue;
                    }
                    visited[i][j] = key;
                    q.push({ i, j, key });
                }
            }
            level++;
        }
        return -1;
    }
};


//5:15 5:35 dijkstra TLE
class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        auto cmp = [](const vector<int>& left, const vector<int>& right) {
            if (left[2] == right[2]) {
                return left[3] < right[3];
            }
            return left[2] > right[2];
        };
        vector<vector<int>> direction{ {0, 1},
                                       {0, -1},
                                       {1, 0},
                                       {-1, 0} };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        vector<vector<int>> visited(m, vector<int>(n, -1));
        pq.push({ 0, 0, 0, k });
        while (pq.size() > 0) {
            auto x = pq.top();
            pq.pop();
            visited[x[0]][x[1]] = 0;
            if (x[0] == m - 1 && x[1] == n - 1) {
                return x[2];
            }
            for (auto& y : direction) {
                int i = x[0] + y[0];
                int j = x[1] + y[1];
                if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] != -1) {
                    continue;
                }
                int key = x[3];
                if (grid[i][j] == 1) {
                    if (key == 0) {
                        continue;
                    }
                    key--;
                }
                pq.push({ i, j, x[2] + 1, key });
            }
        }
        return -1;
    }
};