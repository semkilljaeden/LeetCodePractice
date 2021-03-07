#include "LCHeader.h"

//1:13 1:26
/*
Runtime: 64 ms, faster than 78.85% of C++ online submissions for Delete Tree Nodes.
Memory Usage: 37.5 MB, less than 25.00% of C++ online submissions for Delete Tree Nodes.
*/
class Solution {
public:
    int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) {
        vector<int> sum(nodes, 0);
        vector<int> size(nodes, 0);
        unordered_map<int, vector<int>> edges;
        int root = -1;
        for (int i = 0; i < parent.size(); i++) {
            if (parent[i] == -1) {
                root = i;
            }
            edges[parent[i]].push_back(i);
        }
        dp(edges, value, root, sum, size);
        int result = nodes;
        dp2(edges, value, root, sum, size, result);
        return result;
    }

    int dp(unordered_map<int, vector<int>>& edges, vector<int>& value, int node, vector<int>& sums, vector<int>& sizes) {
        int sum = value[node];
        int size = 1;
        for (auto& x : edges[node]) {
            sum += dp(edges, value, x, sums, sizes);
            size += sizes[x];
        }
        sizes[node] = size;
        return sums[node] = sum;
    }
    void dp2(unordered_map<int, vector<int>>& edges, vector<int>& value, int node, vector<int>& sums, vector<int>& sizes, int& result) {
        if (sums[node] == 0) {
            result -= sizes[node];
            return;
        }
        for (auto& x : edges[node]) {
            dp2(edges, value, x, sums, sizes, result);
        }
        return;
    }
};