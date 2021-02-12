#include<vector>
using namespace std;
//10:28 11:09
/*
Runtime: 404 ms, faster than 28.20% of C++ online submissions for Burst Balloons.
Memory Usage: 10.2 MB, less than 18.57% of C++ online submissions for Burst Balloons.
*/
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        vector<vector<int>> memo(n, vector<int>(n, 0));
        for (int j = 2; j < n; j++) {
            for (int i = 0; i + j < n; i++) {
                auto& x = memo[i][i + j];
                x = INT_MIN;
                for (int k = i + 1; k < i + j; k++) {
                    int tmp = nums[k] * nums[i] * nums[i + j] + memo[i][k] + memo[k][i + j];
                    x = max(x, tmp);
                }
            }
        }
        return memo[0][n - 1];
    }
};

//read the answer

/*
Runtime: 720 ms, faster than 12.36% of C++ online submissions for Burst Balloons.
Memory Usage: 10.3 MB, less than 18.57% of C++ online submissions for Burst Balloons.
*/


class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<int> n(nums.size() + 2);
        n.push_back(1);
        n.insert(n.end(), nums.begin(), nums.end());
        n.push_back(1);
        vector<vector<int>> memo(n.size(), vector<int>(n.size(), -1));
        return dp(0, n.size() - 1, n, memo);
    }
    int dp(int left, int right, vector<int>& n, vector<vector<int>>& memo) {
        if (left >= right - 1) {
            return 0;
        }
        if (memo[left][right] != -1) {
            return memo[left][right];
        }
        int max = INT_MIN;
        for (int i = left + 1; i < right; i++) {
            max = std::max(max, n[i] * n[left] * n[right] +
                dp(left, i, n, memo) + dp(i, right, n, memo));
        }
        return memo[left][right] = max;
    }
};
