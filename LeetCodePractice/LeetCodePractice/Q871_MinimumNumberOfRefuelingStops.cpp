#include "LCHeader.h"
#include "queue"

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        if (target <= startFuel) {
            return 0;
        }
        if (stations.size() == 0 || startFuel < stations[0][0]) {
            return -1;
        }
        int n = stations.size();
        vector<vector<long>> memo(n + 1, vector<long>(n + 1, 0));
        memo[0][0] = startFuel;
        for (int i = 1; i < n + 1; i++) {
            memo[i][0] = memo[i - 1][0] >= stations[i - 1][0] ? memo[i - 1][0] : 0;
            for (int j = 1; j <= i; j++) {
                long r = memo[i - 1][j - 1] >= stations[i - 1][0] ? memo[i - 1][j - 1] + stations[i - 1][1] : 0;
                long l = memo[i - 1][j] >= stations[i - 1][0] ? memo[i - 1][j] : 0;
                memo[i][j] = max(r, l);
            }
        }
        for (int i = 0; i < memo[n].size(); i++) {
            if (memo[n][i] >= target) {
                return i;
            }
        }
        return -1;
    }
};
//1:23 2:33 TLE BFS
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        if (target <= startFuel) {
            return 0;
        }
        if (stations.size() == 0 || startFuel < stations[0][0]) {
            return -1;
        }
        unordered_map<int, int> visited;
        queue<pair<int, int>> q;
        for (int i = 0; i < stations.size(); i++) {
            if (stations[i][0] <= startFuel) {
                q.push(make_pair(i, startFuel - stations[i][0]));
            }
            else {
                break;
            }
        }
        int level = 1;
        while (q.size() > 0) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto pr = q.front();
                q.pop();
                if (visited.count(pr.first) > 0 && visited[pr.first] > pr.second) {
                    continue;
                }
                visited[pr.first] = pr.second;

                pr.second += stations[pr.first][1];
                if (stations[pr.first][0] + pr.second >= target) {
                    return level;
                }
                int idx = pr.first + 1;
                while (idx < stations.size() && stations[idx][0] - stations[pr.first][0] <= pr.second) {
                    int fuel = pr.second - stations[idx][0] + stations[pr.first][0];
                    q.push(make_pair(idx, fuel));
                    idx++;
                }
            }
            level++;
        }
        return -1;
    }
};