#include "LCHeader.h"
#include "queue"

/**

Runtime: 48 ms, faster than 80.60% of C++ online submissions for Minimum Knight Moves.
Memory Usage: 33.4 MB, less than 59.96% of C++ online submissions for Minimum Knight Moves.
*/


class Solution {//10:56 11:26
public:
    int minKnightMoves(int x, int y) {
        int xx = abs(x) + 10;
        int yy = abs(y) + 10;
        queue<pair<int, int>> q;
        q.push(make_pair(10, 10));
        vector<vector<int>> directions{ {2, 1},
                                        {2, -1},
                                        {-2, 1},
                                        {-2, -1},
                                        {1, 2},
                                        {-1, 2},
                                       {1, -2},
                                        {-1, -2} };
        vector<vector<int>> visited(330, vector<int>(330, -1));
        int level = 0;
        while (q.size() > 0) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto x = q.front();
                q.pop();
                if (x.first == xx && x.second == yy) {
                    return level;
                }
                for (auto& y : directions) {
                    int r = x.first + y[0];
                    int c = x.second + y[1];
                    if (r < 0 || c < 0 || r + c > 320 || r > xx + 5 || c > yy + 5) {
                        continue;
                    }
                    if (visited[r][c] != -1) {
                        continue;
                    }
                    visited[r][c] = 1;
                    q.push(make_pair(r, c));
                }
            }
            level++;
        }
        return 0;
    }
};






//2:13 2:44 TLE need to limit the solutio to one qudrant
class Solution {
public:
    int minKnightMoves(int x, int y) {
        vector<vector<int>> coord{
            {2, 1},
            {2, -1},
            {-2, 1},
            {-2, -1},
            {1, 2},
            {-1, 2},
            {1, -2},
            {-1, -2} };
        unordered_map<string, int> visited1;
        unordered_map<string, int> visited2;
        queue<vector<int>> q;
        q.push(vector<int>{0, 0, 0});
        visited1["0|0"] = 0;
        x = abs(x);
        y = abs(y);
        q.push(vector<int>{1, x, y});
        visited2[to_string(x) + "|" + to_string(y)] = 0;
        int level = 0;
        while (q.size() > 0) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto& p = q.front();
                int sign = p[0];
                string signature = to_string(p[1]) + "|" + to_string(p[2]);
                if (sign == 0 && visited2.count(signature) > 0) {
                    return level + visited2[signature];
                }
                else if (sign == 1 && visited1.count(signature) > 0) {
                    return level + visited1[signature];
                }
                else if (sign == 0 && p[1] == x && p[2] == y) {
                    return 0;
                }
                for (auto& co : coord) {
                    int xx = p[1] + co[0];
                    int yy = p[2] + co[1];
                    if (abs(xx) + abs(yy) > 300 || xx < -5 || yy < -5 || xx > x + 5 || yy > y + 5) {
                        continue;
                    }
                    string sig = to_string(xx) + "|" + to_string(yy);
                    auto& vis = p[0] == 0 ? visited1 : visited2;
                    if (vis.count(sig) > 0) {
                        continue;
                    }
                    q.push(vector<int>{p[0], xx, yy});
                    vis[sig] = level + 1;
                }
                q.pop();
            }
            level++;
        }
        return -1;
    }
};