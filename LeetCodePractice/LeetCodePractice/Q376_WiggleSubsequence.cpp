#include<vector>
using namespace std;

//1:47 2:01 dp O(n^2)
/*
Runtime: 8 ms, faster than 30.07% of C++ online submissions for Wiggle Subsequence.
Memory Usage: 7.6 MB, less than 15.12% of C++ online submissions for Wiggle Subsequence.
*/
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() < 2) {
            return nums.size();
        }
        vector<vector<int>> memo(nums.size(), vector<int>(2, 0));
        memo[0][0] = 1;
        memo[0][1] = 1;
        for (int i = 1; i < nums.size(); i++) {
            int d = 1;
            int u = 1;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    u = std::max(u, memo[j][0] + 1);
                }
                else if (nums[j] > nums[i]) {
                    d = std::max(d, memo[j][1] + 1);
                }
            }
            memo[i][0] = d;
            memo[i][1] = u;
        }
        int max = 0;
        for (auto& x : memo) {
            max = std::max(max, std::max(x[0], x[1]));
        }
        return max;
    }
};