#include "LCHeader.h"
#include "queue"
//9:38 10:02, BFS, but read the answer, stupid

/*
Runtime: 28 ms, faster than 96.78% of C++ online submissions for Walls and Gates.
Memory Usage: 16.1 MB, less than 38.56% of C++ online submissions for Walls and Gates.
*/
class Solution {
public:
    int m;
    int n;
    vector<vector<int>> direction{ vector<int>{-1, 0},
                                  vector<int>{1, 0},
                                  vector<int>{0, -1},
                                  vector<int>{0, 1} };
    void wallsAndGates(vector<vector<int>>& rooms) {
        m = rooms.size();
        n = rooms[0].size();
        vector<pair<int, int>> gates;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rooms[i][j] == 0) {
                    gates.push_back(make_pair(i, j));
                }
            }
        }
        bfs(rooms, gates);
    }

    inline void bfs(vector<vector<int>>& rooms, const vector<pair<int, int>>& gates) {
        queue<pair<int, int>> q;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for (auto& x : gates) {
            q.push(x);
        }
        int level = 0;
        while (q.size() > 0) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto& tmp = q.front();
                int vp = tmp.first;
                int hp = tmp.second;
                q.pop();
                rooms[vp][hp] = std::min(rooms[vp][hp], level);
                visited[vp][hp] = 1;
                for (auto& x : direction) {
                    int v = vp + x[0];
                    int h = hp + x[1];
                    if (v < 0 || v >= m || h < 0 || h >= n || rooms[v][h] == -1 || rooms[v][h] == 0 || visited[v][h] == 1) {
                        continue;
                    }
                    q.push(make_pair(v, h));
                }
            }
            level++;
        }
    }
};