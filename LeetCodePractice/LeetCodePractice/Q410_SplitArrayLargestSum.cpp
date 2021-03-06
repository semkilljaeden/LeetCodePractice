#include<vector>
using namespace std;


class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        vector<vector<int>> memo(nums.size(), vector<int>(m + 1, -1));
        return dp(nums, m, 0, memo);
    }

    int dp(vector<int>& nums, int m, int idx, vector<vector<int>>& memo) {
        if (idx == nums.size()) {
            if (m != 0) {
                return INT_MAX;
            }
            return 0;
        }
        if (m == 0) {
            return INT_MAX;
        }
        if (memo[idx][m] != -1) {
            return memo[idx][m];
        }
        int sum = 0;
        int min = INT_MAX;
        for (int i = idx; i < nums.size(); i++) {
            sum += nums[i];
            int tmp = std::max(sum, dp(nums, m - 1, i + 1, memo));
            min = std::min(min, tmp);
        }
        return memo[idx][m] = min;
    }
};





//11:12 save space to O(n)
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<int> mm(n + 1, 0);
        vector<int> tt(n + 1, 0);
        auto* memo = &mm;
        auto* tmp = &tt;
        for (int i = 1; i < n + 1; ++i) {
            (*memo)[i] = (*memo)[i - 1] + nums[i - 1];
        }
        for (int i = 2; i <= m; i++) {
            for (int j = i; j < n + 1; j++) {
                int sum = 0;
                int min = INT_MAX;
                for (int k = j; k > i - 1; k--) {
                    sum += nums[k - 1];
                    min = std::min(min, std::max(sum, (*memo)[k - 1]));
                }
                (*tmp)[j] = min;
            }
            swap(tmp, memo);
        }
        return (*memo)[n];
    }

};


//11:00 bottom up DP, still O(mn^2)
/*
Runtime: 280 ms, faster than 31.65% of C++ online submissions for Split Array Largest Sum.
Memory Usage: 7.8 MB, less than 31.18% of C++ online submissions for Split Array Largest Sum.
*/

class Solution2 {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<vector<int>> memo(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i < n + 1; ++i) {
            memo[1][i] = memo[1][i - 1] + nums[i - 1];
        }
        for (int i = 2; i <= m; i++) {
            for (int j = i; j < n + 1; j++) {
                int sum = 0;
                int min = INT_MAX;
                for (int k = j; k > i - 1; k--) {
                    sum += nums[k - 1];
                    min = std::min(min, std::max(sum, memo[i - 1][k - 1]));
                }
                memo[i][j] = min;
            }
        }
        return memo[m][n];
    }

};

//6:58 10:21 10:33 O(mn^2) 	1740 ms	8.2 MB

class Solution4 {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<vector<int>> memo(n + 1, vector<int>(m + 1, -1));
        return dp(nums, 0, m, memo);
    }

    int dp(vector<int>& nums, int i, int m, vector<vector<int>>& memo) {
        if (i >= nums.size()) {
            return INT_MAX;
        }
        if (m > nums.size()) {
            return INT_MAX;
        }
        if (m == 1) {
            int sum = 0;
            for (int x = i; x < nums.size(); x++) {
                sum += nums[x];
            }
            return sum;
        }
        if (memo[i][m] != -1) {
            return memo[i][m];
        }
        int min = INT_MAX;
        int sum = 0;
        for (int x = i; x < nums.size() && nums.size() - x >= m; x++) {
            sum += nums[x];
            min = std::min(min, std::max(sum, dp(nums, x + 1, m - 1, memo)));
        }
        return memo[i][m] = min;
    }
};