#include "LCHeader.h"
//6:52 7:38 took a long time to debug



class Solution {
public:
    unordered_map<int, int> node_dis;
    unordered_map<int, int> node_count;
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> tree;
        for (auto& x : edges) {
            tree[x[0]].push_back(x[1]);
            tree[x[1]].push_back(x[0]);
        }
        rec1(tree, 0, -1);
        vector<int> result(N, 0);
        rec2(tree, 0, result, make_pair(0, 0), -1);
        return result;
    }

    void rec1(unordered_map<int, vector<int>>& tree, int root, int parent) {
        int dis = 0;
        int count = 0;
        for (auto& x : tree[root]) {
            if (x == parent) {
                continue;
            }
            rec1(tree, x, root);
            int c = node_count[x];
            int d = node_dis[x];
            dis += d + c + 1;
            count += c + 1;
        }
        node_dis[root] = dis;
        node_count[root] = count;
    }

    void rec2(unordered_map<int, vector<int>>& tree, int root, vector<int>& result, pair<int, int> parent, int parentNode) {

        result[root] = node_dis[root] + parent.first + parent.second + (parentNode != -1 ? 1 : 0);

        node_count[root] += parent.second + (parentNode != -1 ? 1 : 0);


        for (auto& x : tree[root]) {
            if (x == parentNode) {
                continue;
            }
            rec2(tree, x, result, make_pair(result[root] - node_dis[x] - node_count[x] - 1, node_count[root] - node_count[x] - 1), root);
        }
    }

};