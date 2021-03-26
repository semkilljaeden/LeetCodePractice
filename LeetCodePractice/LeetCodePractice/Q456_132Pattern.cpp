#include "LCHeader.h"
#include<set>
//3:04 3:23
//nlogn
/*
Runtime: 12 ms, faster than 79.29% of C++ online submissions for 132 Pattern.
Memory Usage: 14.6 MB, less than 10.15% of C++ online submissions for 132 Pattern.
*/

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        vector<int> min(nums.size(), 0);
        int prev = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < prev) {
                min[i] = nums[i];
            }
            else {
                min[i] = prev;
            }
            prev = min[i];
        }

        set<int> tree;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] <= min[i]) {
                continue;
            }
            auto itr = tree.lower_bound(nums[i]);
            if (itr != tree.begin() && *(--itr) > min[i]) {
                return true;
            }
            tree.insert(nums[i]);
        }
        return false;
    }
};