#include "LCHeader.h"
#include<queue>
//11:04 11:21 BFS TLE





class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int min = INT_MAX;
        for (int i = 0; i < graph.size(); i++) {
            min = std::min(bfs(graph, i), min);
        }
        return min == INT_MAX ? 0 : min;
    }

    int bfs(vector<vector<int>>& graph, int node) {
        queue<pair<int, unordered_set<int>>> q;
        unordered_set<int> visited;
        q.push(make_pair(node, visited));
        int level = 0;
        while (q.size() > 0) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto item = q.front();
                q.pop();
                int n = item.first;
                auto& v = item.second;
                for (auto x : graph[n]) {
                    auto nv = v;
                    nv.insert(x);
                    if (nv.size() == graph.size()) {
                        return level;
                    }
                    q.push(make_pair(x, nv));
                }
            }
            level++;
        }
        return INT_MAX;
    }
};