#include "LCHeader.h"
class Solution {//4:15 19
public:
    int maxSubArray(vector<int>& nums) {
        int max = INT_MIN;
        for (auto& x : nums) {
            if (x > max) {
                max = x;
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0) {
                continue;
            }
            int sum = 0;
            while (i < nums.size() && sum + nums[i] >= 0) {
                sum += nums[i];
                i++;
                max = std::max(max, sum);
            }
        }
        return max;
    }
};