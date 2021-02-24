#include "LCHeader.h"
//12:14 12:34

class Solution {
public:
    int dst;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        this->dst = dst;
        unordered_map<int, vector<vector<int>>> fl;
        for (const auto& x : flights) {
            fl[x[0]].push_back(vector<int>{x[1], x[2]});
        }
        unordered_map<string, int> memo;
        int r = dp(src, fl, K + 1, memo);

        if (r > 1000000) {
            return -1;
        }
        return r;
    }

    int dp(int city, unordered_map<int, vector<vector<int>>>& fl, int k, unordered_map<string, int>& memo) {
        if (k < 0) {
            return 10000000;
        }
        if (city == dst) {
            return 0;
        }
        string hash = to_string(city) + " " + to_string(k);
        if (memo.find(hash) != memo.end()) {
            return memo[hash];
        }
        auto& x = fl[city];
        int min = 10000000;
        for (auto& y : x) {
            min = std::min(min, y[1] + dp(y[0], fl, k - 1, memo));
        }
        return memo[hash] = min;
    }
};