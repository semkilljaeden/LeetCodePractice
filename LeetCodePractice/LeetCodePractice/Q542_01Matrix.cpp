#include "LCHeader.h"
#include<queue>
//3:25 3:49
class Solution {
public:
    int m;
    int n;
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        vector<vector<int>> result(m, vector<int>(n, -1));
        queue<vector<int>> q;
        vector<vector<int>> direction{ {1, 0},
                                      {-1, 0},
                                      {0, 1},
                                      {0, -1} };

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1) {
                    continue;
                }
                result[i][j] = 0;
                for (auto& x : direction) {
                    int v = i + x[0];
                    int h = j + x[1];
                    if (is_valid(v, h)) {
                        if (matrix[v][h] == 1) {
                            q.push({ v, h });
                        }
                    }
                }
            }
        }

        int level = 1;
        while (q.size() > 0) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto x = q.front();
                q.pop();
                if (result[x[0]][x[1]] != -1) {
                    continue;
                }
                result[x[0]][x[1]] = level;
                for (auto& y : direction) {
                    int v = x[0] + y[0];
                    int h = x[1] + y[1];
                    if (!is_valid(v, h) || result[v][h] != -1) {
                        continue;
                    }
                    q.push({ v, h });
                }
            }
            level++;
        }
        return result;


    }

    inline bool is_valid(const int& i, const int& j) {
        return i >= 0 && i < m&& j >= 0 && j < n;
    }

};