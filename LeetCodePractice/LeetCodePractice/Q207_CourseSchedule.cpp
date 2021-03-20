#include "LCHeader.h"
#include <queue>
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> graph;
        unordered_set<int> set;
        for (int i = 0; i < numCourses; i++) {
            set.insert(i);
        }
        unordered_map<int, int> pre;
        for (auto& x : prerequisites) {
            graph[x[1]].push_back(x[0]);
            pre[x[0]]++;
            set.erase(x[0]);
        }
        queue<int> q;
        for (auto& x : set) {
            q.push(x);
        }
        while (q.size() > 0) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto x = q.front();
                q.pop();
                if (pre.count(x) > 0) {
                    pre[x]--;
                    if (pre[x] == 0) {
                        pre.erase(x);
                    }
                    else {
                        continue;
                    }
                }
                for (auto& y : graph[x]) {
                    q.push(y);
                }
            }
        }
        return pre.size() == 0;
    }
};