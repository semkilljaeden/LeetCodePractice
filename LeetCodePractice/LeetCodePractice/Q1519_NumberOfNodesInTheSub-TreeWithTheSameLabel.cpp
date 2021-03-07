#include "LCHeader.h"
//5:11 6:05, silly question

class Solution {
public:
    vector<int> base;
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        base = vector<int>(26, 0);
        unordered_map<int, vector<int>> eg;
        for (auto& x : edges) {
            eg[x[0]].push_back(x[1]);
            eg[x[1]].push_back(x[0]);
        }
        vector<vector<int>> count(n, vector<int>(26, 0));
        unordered_set<int> visited;
        dfs(eg, count, labels, 0, visited);
        vector<int> result(n);
        for (int i = 0; i < n; i++) {
            result[i] = count[i][labels[i] - 'a'];
        }
        return result;
    }

    vector<int>& dfs(unordered_map<int, vector<int>>& eg, vector<vector<int>>& count, string& labels, int node, unordered_set<int>& visited) {
        if (visited.count(node) > 0) {
            return base;
        }
        visited.insert(node);
        for (int i = 0; i < eg[node].size(); i++) {
            auto& r = dfs(eg, count, labels, eg[node][i], visited);
            for (int j = 0; j < 26; j++) {
                count[node][j] += r[j];
            }
        }
        count[node][labels[node] - 'a']++;
        visited.erase(node);
        return count[node];
    }
};