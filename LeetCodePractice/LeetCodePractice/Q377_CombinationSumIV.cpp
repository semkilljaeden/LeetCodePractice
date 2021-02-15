#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> memo(target + 1, 0);
        memo[target] = 1;
        for (int i = target; i >= 1; --i) {
            if (memo[i] == 0) {
                continue;
            }
            for (auto& x : nums) {
                int tmp = i - x;
                if (tmp < 0 || memo[tmp] > INT_MAX - memo[i]) {
                    break;
                }
                memo[tmp] += memo[i];
            }
        }
        return memo[0];
    }
};
/*
* Runtime: 0 ms, faster than 100.00% of C++ online submissions for Combination Sum IV.
Memory Usage: 8.4 MB, less than 13.83% of C++ online submissions for Combination Sum IV.
*/
//2:12 2:18
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        unordered_map<int, int> memo;
        return dp(nums, target, memo);
    }
    int dp(vector<int>& nums, int target, unordered_map<int, int>& memo) {
        if (target == 0) {
            return 1;
        }
        if (target < 0) {
            return 0;
        }
        if (memo.find(target) != memo.end()) {
            return memo[target];
        }
        int sum = 0;
        for (auto& x : nums) {
            sum += dp(nums, target - x, memo);
        }
        return memo[target] = sum;
    }
};