#include "LCHeader.h"
#include<queue>
//9:27 9:50 one shot AC omfg!~!!!! hahhahahahha

class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        unordered_map<int, unordered_set<int>> outgoing;
        unordered_map<int, unordered_set<int>> incoming;
        unordered_set<int> entry;
        for (int i = 1; i <= n; i++) {
            entry.insert(i);
        }
        for (int i = 0; i < relations.size(); i++) {
            auto& x = relations[i];
            outgoing[x[0]].insert(x[1]);
            incoming[x[1]].insert(x[0]);
            entry.erase(x[1]);
        }
        if (entry.size() == 0) {
            return -1;
        }
        queue<int> q;
        for (auto& x : entry) {
            q.push(x);
        }
        int count = 0;
        int n_count = 0;
        while (q.size() > 0) {
            int size = q.size();
            unordered_set<int> next;
            for (int i = 0; i < size; i++) {
                int x = q.front();
                q.pop();
                n_count++;
                auto& set = outgoing[x];
                for (auto tmp : set) {
                    incoming[tmp].erase(x);
                    if (incoming[tmp].size() == 0) {
                        next.insert(tmp);
                    }
                }
            }
            count++;
            for (auto& x : next) {
                q.push(x);
            }
        }
        if (n_count < n) {
            return -1;
        }
        return count;
    }
};