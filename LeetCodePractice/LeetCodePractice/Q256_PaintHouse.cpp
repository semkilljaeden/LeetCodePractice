#include<vector>
using namespace std;
//5:52 to 6:00, given dp and resolve is too easy
/*
* Runtime: 4 ms, faster than 99.59% of C++ online submissions for Paint House.
Memory Usage: 9.5 MB, less than 89.15% of C++ online submissions for Paint House.
*/
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Paint House.
Memory Usage: 9.6 MB, less than 89.15% of C++ online submissions for Paint House.
*/
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if (costs.size() == 0)
        {
            return 0;
        }
        vector<int> s1(3);
        vector<int> s2(3);
        auto m = &s1;
        auto t = &s2;
        (*m) = costs[0];
        for (size_t i = 1; i < costs.size(); i++) {
            auto& cost = costs[i];
            auto& tmp = *t;
            auto& memo = *m;
            tmp[0] = min(memo[1], memo[2]) + cost[0];
            tmp[1] = min(memo[0], memo[2]) + cost[1];
            tmp[2] = min(memo[0], memo[1]) + cost[2];
            swap(m, t);
        }
        return min((*m)[0], min((*m)[1], (*m)[2]));
    }
};


class Solution3 {
public:
    int minCost(vector<vector<int>>& costs) {
        if (costs.size() == 0)
        {
            return 0;
        }
        vector<int> memo(3);
        vector<int> tmp(3);
        memo = costs[0];
        for (size_t i = 1; i < costs.size(); i++) {
            auto& cost = costs[i];
            tmp[0] = min(memo[1], memo[2]) + cost[0];
            tmp[1] = min(memo[0], memo[2]) + cost[1];
            tmp[2] = min(memo[0], memo[1]) + cost[2];
            memo = tmp;
        }
        return min(memo[0], min(memo[1], memo[2]));
    }
};


class Solution2{
public:
    int minCost(vector<vector<int>>& costs) {
        if (costs.size() == 0)
        {
            return 0;
        }
        vector<vector<int>> memo(costs.size(), vector<int>(3));
        memo[0] = costs[0];
        for (size_t i = 1; i < costs.size(); i++) {
            auto& cur = memo[i];
            auto& prev = memo[i - 1];
            auto& cost = costs[i];
            cur[0] = min(prev[1], prev[2]) + cost[0];
            cur[1] = min(prev[0], prev[2]) + cost[1];
            cur[2] = min(prev[0], prev[1]) + cost[2];
        }
        return min(memo.back()[0], min(memo.back()[1], memo.back()[2]));
    }
};