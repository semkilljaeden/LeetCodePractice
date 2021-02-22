#include<vector>
#include<algorithm>
using namespace std;
//12:07 12:25 medium, getting better and better
/*
Runtime: 180 ms, faster than 64.70% of C++ online submissions for Maximum Length of Pair Chain.
Memory Usage: 22.9 MB, less than 59.42% of C++ online submissions for Maximum Length of Pair Chain.
*/
class Solution {
public:
    int n;
    vector<int> memo;
    int findLongestChain(vector<vector<int>>& pairs) {
        n = pairs.size();
        sort(pairs.begin(), pairs.end(), [](vector<int>& x, vector<int>& y) {
            return x[0] < y[0];
        });
        memo = vector<int>(n + 1, -1);
        return dp(pairs, 0);
    }
    int dp(vector<vector<int>>& pairs, int idx) {
        if (idx == pairs.size()) {
            return 0;
        }
        if (memo[idx] != -1) {
            return memo[idx];
        }
        auto& x = pairs[idx];
        int max = 1;
        for (int i = idx + 1; i < n; i++) {
            if (pairs[i][0] <= x[1]) {
                continue;
            }
            max = std::max(max, 1 + dp(pairs, i));
        }
        max = std::max(max, dp(pairs, idx + 1));
        return memo[idx] = max;
    }
};