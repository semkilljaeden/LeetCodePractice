#include<vector>
using namespace std;
/*
Runtime: 8 ms, faster than 100.00% of C++ online submissions for Paint House II.
Memory Usage: 10.8 MB, less than 96.85% of C++ online submissions for Paint House II.
*/

class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if (costs.size() == 0 || costs[0].size() == 0) {
            return 0;
        }
        int min = INT_MAX;
        int s_min = INT_MAX;
        int min_k = -1;
        int s_min_k = -1;
        for (int k = 0; k < costs[0].size(); k++) {
            int& x = costs[0][k];
            if (x < min) {
                s_min = min;
                s_min_k = min_k;
                min = x;
                min_k = k;
            }
            else if (x < s_min) {
                s_min = x;
                s_min_k = k;
            }
        }
        for (int i = 1; i < costs.size(); i++) {
            int t1 = INT_MAX;
            int t2 = INT_MAX;
            int t1k = -1;
            int t2k = -1;
            for (int j = 0; j < costs[0].size(); j++) {
                int x = costs[i][j] + (min_k == j ? s_min : min);
                if (x < t1) {
                    t2 = t1;
                    t1 = x;
                    t2k = t1k;
                    t1k = j;
                }
                else if (x < t2) {
                    t2 = x;
                    t2k = j;
                }
            }
            min = t1;
            s_min = t2;
            min_k = t1k;
            s_min_k = t2k;
        }
        return min;
    }
};

//8:55 9:07 nk^2
/*
Runtime: 12 ms, faster than 98.11% of C++ online submissions for Paint House II.
Memory Usage: 11 MB, less than 88.96% of C++ online submissions for Paint House II.
*/
class Solution2 {
public:
    int minCostII(vector<vector<int>>& costs) {
        if (costs.size() == 0 || costs[0].size() == 0) {
            return 0;
        }
        vector<int> s1(costs[0].size());
        vector<int> s2(costs[0].size());
        auto prev = &s1;
        auto tmp = &s2;
        *prev = costs[0];
        for (int i = 1; i < costs.size(); i++) {
            auto& p = *prev;
            auto& t = *tmp;
            for (int j = 0; j < p.size(); j++) {
                int min = INT_MAX;
                for (int k = 0; k < p.size(); k++) {
                    if (k != j) {
                        min = std::min(min, p[k]);
                    }
                }
                t[j] = min + costs[i][j];
            }
            auto k = prev;
            prev = tmp;
            tmp = k;
        }
        int min = INT_MAX;
        for (int k = 0; k < prev->size(); k++) {
            min = std::min(min, (*prev)[k]);
        }
        return min;
    }
};