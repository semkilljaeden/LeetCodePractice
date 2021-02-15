#include<vector>
using namespace std;
/*
Runtime: 36 ms, faster than 91.34% of C++ online submissions for Partition Equal Subset Sum.
Memory Usage: 10.5 MB, less than 69.21% of C++ online submissions for Partition Equal Subset Sum.
*/
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto& x : nums) {
            sum += x;
        }
        if (sum % 2 != 0) {
            return false;
        }
        sum /= 2;
        vector<int> memo(sum + 1, -1);
        memo[sum] = 0;
        if (sum - nums[0] == 0) {
            return true;
        }
        else if (sum - nums[0] > 0) {
            memo[sum - nums[0]] = 0;
        }
        vector<int> tmp(memo);
        for (int j = 1; j < nums.size(); ++j) {
            auto& x = nums[j];
            for (int i = sum; i >= 0; --i) {
                if (memo[i] == -1) {
                    continue;
                }
                if (i - x == 0) {
                    return true;
                }
                if (i - x > 0) {
                    tmp[i - x] = 0;
                }
            }
            memo = tmp;
        }
        return false;
    }
};

//12:03 12:45 silly bug
/*
Runtime: 8 ms, faster than 99.06% of C++ online submissions for Partition Equal Subset Sum.
Memory Usage: 75.2 MB, less than 17.30% of C++ online submissions for Partition Equal Subset Sum.
*/
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto& x : nums) {
            sum += x;
        }
        if (sum % 2 != 0) {
            return false;
        }
        sum /= 2;
        vector<vector<int>> memo(nums.size(), vector<int>(sum + 1, -1));
        return dp(nums, 0, sum, memo);
    }

    bool dp(vector<int>& nums, int i, int sum, vector<vector<int>>& memo) {
        if (i >= nums.size()) {
            return false;
        }
        if (sum == 0) {
            return true;
        }
        else if (sum < 0) {
            return false;
        }
        if (memo[i][sum] != -1) {
            return memo[i][sum] == 1;
        }
        bool r = false;
        r = r || dp(nums, i + 1, sum - nums[i], memo);
        r = r || dp(nums, i + 1, sum, memo);
        r ? memo[i][sum] = 1 : memo[i][sum] = 0;
        return r;

    }
};
/*

Runtime: 636 ms, faster than 15.33% of C++ online submissions for Partition Equal Subset Sum.
Memory Usage: 198 MB, less than 5.03% of C++ online submissions for Partition Equal Subset Sum.
*/

class Solution2 {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto& x : nums) {
            sum += x;
        }
        vector<vector<int>> memo(nums.size(), vector<int>(sum + 1, -1));
        return dp(nums, 0, 0, sum, memo);
    }

    bool dp(vector<int>& nums, int i, int sum, int& total, vector<vector<int>>& memo) {
        if (i >= nums.size()) {
            return false;
        }
        if (sum + nums[i] == total - sum + nums[i]) {
            return true;
        }
        if (memo[i][sum] != -1) {
            return memo[i][sum] == 1;
        }
        bool r = false;
        r = r || dp(nums, i + 1, sum + nums[i], total, memo);
        r = r || dp(nums, i + 1, sum, total, memo);
        r = r || dp(nums, i + 1, 0, total, memo);
        r ? memo[i][sum] = 1 : memo[i][sum] = 0;
        return r;
    }
};