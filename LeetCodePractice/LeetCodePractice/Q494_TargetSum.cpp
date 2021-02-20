#include<vector>
using namespace std;



class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        vector<vector<int>> memo(nums.size() + 1, vector<int>(2001, -1));
        return dp(nums, 0, S, 0, memo);
    }

    int dp(vector<int>& nums, int sum, int S, int pos, vector<vector<int>>& memo) {
        if (pos == nums.size()) {
            return S == sum ? 1 : 0;
        }
        if (memo[pos][sum + 1000] != -1) {
            return memo[pos][sum + 1000];
        }
        return memo[pos][sum + 1000] = dp(nums, sum + nums[pos], S, pos + 1, memo) + dp(nums, sum - nums[pos], S, pos + 1, memo);
    }
};


//2:47 3:10 TLE wtf
class Solution2 {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        if (S > 1000) {
            return 0;
        }
        vector<int> prev{ 0 };
        for (auto& x : nums) {
            vector<int> tmp;
            for (auto& y : prev) {
                tmp.push_back(y + x);
                tmp.push_back(y - x);
            }
            prev = move(tmp);
        }
        int c = 0;
        for (auto& x : prev) {
            if (x == S) {
                c++;
            }
        }
        return c;
    }
};