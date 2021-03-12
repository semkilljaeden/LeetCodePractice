#include "LCHeader.h"
#include <queue>
//5:18

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> result;
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return result;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> pac(m, vector<int>(n, 0));
        vector<vector<int>> at(m, vector<int>(n, 0));

        vector<vector<int>> coord{ vector<int>{1, 0},
                                 vector<int>{-1, 0},
                                 vector<int>{0, 1},
                                 vector<int>{0, -1} };
        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            q.push(make_pair(i, 0));
        }
        for (int i = 1; i < n; i++) {
            q.push(make_pair(0, i));
        }
        bfs(matrix, vector<vector<int>>(m, vector<int>(n, 0)), pac, coord, q);

        for (int i = 0; i < m; i++) {
            q.push(make_pair(i, n - 1));
        }
        for (int i = 0; i < n - 1; i++) {
            q.push(make_pair(m - 1, i));
        }
        bfs(matrix, vector<vector<int>>(m, vector<int>(n, 0)), at, coord, q);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pac[i][j] == 1 && at[i][j] == 1) {
                    result.push_back(vector<int>{i, j});
                }
            }
        }
        return result;

    }

    void bfs(vector<vector<int>>& matrix, vector<vector<int>> visited, vector<vector<int>>& ocean, vector<vector<int>>& coord, queue<pair<int, int>>& q) {
        while (q.size() > 0) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto& tmp = q.front();
                ocean[tmp.first][tmp.second] = 1;
                visited[tmp.first][tmp.second] = 1;
                for (auto& x : coord) {
                    auto p = make_pair(tmp.first + x[0], tmp.second + x[1]);
                    if (p.first >= 0 && p.first < matrix.size() && p.second >= 0 && p.second < matrix[0].size() && visited[p.first][p.second] != 1 && matrix[p.first][p.second] >= matrix[tmp.first][tmp.second]) {
                        q.push(p);
                    }
                }
                q.pop();
            }
        }
    }
};

//dp does not work when two units are equal
class Solution {
public:
    vector<int> pac{ 1, 0 };
    vector<int> at{ 0, 1 };
    int m;
    int n;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> result;
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return result;
        }
        m = matrix.size();
        n = matrix[0].size();
        vector<vector<vector<int>>> memo(m, vector<vector<int>>(n, vector<int>(2, -1)));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dp(matrix, memo, result, i, j);
            }
        }
        return result;
    }

    vector<int>& dp(vector<vector<int>>& matrix, vector<vector<vector<int>>>& memo, vector<vector<int>>& result, int i, int j) {
        if (i < 0 || j < 0) {
            return pac;
        }
        if (i >= m || j >= n) {
            return at;
        }
        if (memo[i][j][0] != -1 && memo[i][j][1] != -1) {
            return memo[i][j];
        }

        memo[i][j][0] = 0;
        memo[i][j][1] = 0;
        if (out(i + 1, j) || matrix[i + 1][j] <= matrix[i][j]) {
            auto& tmp = dp(matrix, memo, result, i + 1, j);
            memo[i][j][0] |= tmp[0];
            memo[i][j][1] |= tmp[1];
        }
        if (out(i - 1, j) || matrix[i - 1][j] <= matrix[i][j]) {
            auto& tmp = dp(matrix, memo, result, i - 1, j);
            memo[i][j][0] |= tmp[0];
            memo[i][j][1] |= tmp[1];
        }
        if (out(i, j + 1) || matrix[i][j + 1] <= matrix[i][j]) {
            auto& tmp = dp(matrix, memo, result, i, j + 1);
            memo[i][j][0] |= tmp[0];
            memo[i][j][1] |= tmp[1];
        }
        if (out(i, j - 1) || matrix[i][j - 1] <= matrix[i][j]) {
            auto& tmp = dp(matrix, memo, result, i, j - 1);
            memo[i][j][0] |= tmp[0];
            memo[i][j][1] |= tmp[1];
        }

        if (memo[i][j][0] == 1 && memo[i][j][1] == 1) {
            result.push_back(vector<int>{i, j});
        }
        return memo[i][j];
    }

    bool out(int i, int j) {
        return i < 0 || j < 0 || i >= m || j >= n;
    }
};
