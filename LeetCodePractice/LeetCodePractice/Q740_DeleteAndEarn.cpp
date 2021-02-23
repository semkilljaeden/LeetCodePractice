#include "LCHeader.h"
using namespace std;
//4:27 4:45 4:47 can be improve to O(1) space

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](const int& i, const int j) {
            return i < j;
        });
        vector<vector<int>> memo(nums.size() + 1, vector<int>(2, -1));
        vector<pair<int, int>> list;
        int count = 1;
        int prev = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != prev) {
                list.push_back(make_pair(prev, count));
                prev = nums[i];
                count = 1;
            }
            else {
                count++;
            }
        }
        list.push_back(make_pair(prev, count));
        return dp(list, 0, 0, memo);
    }

    int dp(vector<pair<int, int>>& list, int pos, int taken, vector<vector<int>>& memo) {
        if (pos == list.size()) {
            return 0;
        }
        if (memo[pos][taken] != -1) {
            return memo[pos][taken];
        }
        if (taken == 1 && list[pos - 1].first + 1 == list[pos].first) {
            return memo[pos][taken] = dp(list, pos + 1, 0, memo);
        }

        return memo[pos][taken] = max(dp(list, pos + 1, 1, memo) + list[pos].first * list[pos].second, dp(list, pos + 1, 0, memo));
    }
};

