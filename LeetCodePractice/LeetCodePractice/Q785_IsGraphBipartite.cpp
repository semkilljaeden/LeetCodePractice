#include "LCHeader.h"
#include <queue>
//3:50 4:26 stupid bug

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        unordered_set<int> left;
        unordered_set<int> right;
        unordered_set<int> unused;
        for (int i = 0; i < graph.size(); i++) {
            unused.insert(i);
        }
        queue<int> q;
        while (unused.size() > 0) {
            q.push(*unused.begin());
            auto r = bfs(graph, left, right, q, unused);
            if (!r) {
                return false;
            }
        }
        return true;
    }

    bool bfs(vector<vector<int>>& edges, unordered_set<int>& left, unordered_set<int>& right, queue<int>& q, unordered_set<int>& unused) {
        int level = 0;
        unordered_set<int> visited;
        while (q.size() > 0) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int node = q.front();
                q.pop();
                visited.insert(node);
                unused.erase(node);
                if (level % 2 == 0) {
                    if (right.count(node) > 0) {
                        return false;
                    }
                    left.insert(node);
                }
                else {
                    if (left.count(node) > 0) {
                        return false;
                    }
                    right.insert(node);
                }
                for (auto& x : edges[node]) {
                    if (visited.count(x) > 0) {
                        continue;
                    }
                    q.push(x);
                }
            }
            level++;
        }
        return true;
    }
};