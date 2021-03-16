#include "LCHeader.h"
#include<queue>
/*
Runtime: 196 ms, faster than 78.47% of C++ online submissions for Path With Minimum Effort.
Memory Usage: 24.4 MB, less than 50.21% of C++ online submissions for Path With Minimum Effort.
*/

class Solution {
public:

    struct Node {
    public:
        int i;
        int j;
        int diff;
    };
    vector<vector<int>> direction{ vector<int>{1, 0},
                                  vector<int>{0, 1},
                                  vector<int>{-1, 0},
                                  vector<int>{0, -1} };
    int m;
    int n;
    int minimumEffortPath(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        auto cmp = [](const Node& left, const Node& right) {
            return left.diff > right.diff;
        };
        priority_queue<Node, vector<Node>, decltype(cmp)> pq(cmp);
        pq.push(Node{ 0, 0, 0 });
        while (pq.size() > 0) {
            auto next = pq.top();
            if (next.i == m - 1 && next.j == n - 1) {
                return next.diff;
            }
            visited[next.i][next.j] = 1;
            pq.pop();
            for (auto& x : direction) {
                int i = next.i + x[0];
                int j = next.j + x[1];
                if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] == 1) {
                    continue;
                }
                int diff = abs(heights[i][j] - heights[next.i][next.j]);
                pq.push(Node{ i, j, std::max(next.diff, diff) });
            }
        }
        return INT_MAX;

    }

};



//7:14 7:42 TLE

class Solution {
public:
    vector<vector<int>> direction{ vector<int>{1, 0},
                                  vector<int>{0, 1},
                                  vector<int>{-1, 0},
                                  vector<int>{0, -1} };
    int m;
    int n;
    int minimumEffortPath(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        unordered_set<string> visited;
        return dfs(heights, 0, 0, visited, 0, 0);
    }

    int dfs(vector<vector<int>>& heights, int i, int j, unordered_set<string>& visited, int prev_i, int prev_j) {
        if (i < 0 || i >= m || j < 0 || j >= n || visited.count(to_string(i) + "|" + to_string(j)) > 0) {
            return INT_MAX;
        }
        if (i == m - 1 && j == n - 1) {
            return abs(heights[i][j] - heights[prev_i][prev_j]);
        }
        int diff = abs(heights[i][j] - heights[prev_i][prev_j]);
        string sig = to_string(i) + "|" + to_string(j);
        visited.insert(sig);
        int min = INT_MAX;
        for (auto& x : direction) {
            min = std::min(min, dfs(heights, i + x[0], j + x[1], visited, i, j));
        }
        visited.erase(sig);
        return std::max(min, diff);
    }
};